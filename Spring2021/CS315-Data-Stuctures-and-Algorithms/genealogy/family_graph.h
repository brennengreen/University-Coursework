/*
* FAMILY GRAPH CLASS
* Handles all internal of processing new vertices or searching.
*/
#ifndef FAMILY_GRAPH_H
#define FAMILY_GRAPH_H

#include "person.h"
#include "family.h"
#include "keyvaluepair.h"
#include "component.h"
#include "unionfind.h"
#include "queue.h"

#include <vector>
#include <iostream>

using std::vector; // Handle code bloat in a safe way.

class FamilyGraph {
    public:
        FamilyGraph() : persons(100), families(100) {}
        void make_family(int family_id, 
                            vector<Pair> heads, 
                            vector<int> children);
        void print_family(int family_id);
        int find(int person);
        void relationship(int person1, int person2);
        void descendants(int person);
        void ancestors(int person);
        void breadth_first_search(int person1, int person2);
        void build_path(int person1, int person2, std::vector<int> prev);

    private:
        // We add an extra spot at index [0] to process unknowns.
        vector<Person> persons; // Keep track of persons 1-99.
        vector<Family> families; // Keep track of families 1-99.
        UnionFind uf_object;
}; // FamilyGraph

/*
* FamilyGraph::print_family(int family_id)
* Input: A family id which can be used to index families vector.
* Outputs: The string representation of one given family.
*/
void FamilyGraph::print_family(int family_id) {
    std::cout << "Family " << family_id;
    if (families[family_id].is_empty()) {
        std::cout << " does not exist." << std::endl;
        return;
    }

    std::cout << " has ";
    for (auto head : families[family_id].heads) {
        if (head == 0) {
            std::cout << families[family_id].get_unknown_gender();
        } else {
            if (persons[head].get_id() == 'h'||persons[head].get_id() == 'H') {
                std::cout << "husband";
            } else {
                std::cout << "wife";
            }
        }

        std::cout << " " << head << ", ";
    } // Print the heads.

    std::cout << "and children";
    if (families[family_id].children.size() > 0) {
        for (auto child : families[family_id].children) {
            std::cout << " " << child;
        }
    } // Print the children if they exist.
    std::cout << "." << std::endl;
}

/* FamilyGraph::make_family(int family_id, vector<Pair> heads,
*                                            vector<int> children)
*  Input: Specific family id number, vector of heads (with id numbers),
*     vector of children.
*  Ouput: Results of make family.
*/
void FamilyGraph::make_family(int family_id,
                                vector<Pair> heads,
                                vector<int> children) {
    if (!families[family_id].is_empty()) {
        std::cout << "\tFamily " << family_id << " has already been entered." \
            << std::endl;
        return; 
    } // Check if already processed.
    
    Family new_family = Family();

    for (auto head : heads) {
        if (persons[head.get_value()].is_married && head.get_value() > 0) { 
            std::cout << "\t";
            if (persons[head.get_value()].get_id() == 'h' || 
                    persons[head.get_value()].get_id() == 'H') {
                std::cout << "Husband ";
            } else {
                std::cout << "Wife ";
            }
            std::cout << head.get_value() << " is already married." << std::endl;
            return; // Can't have 2+ marriages, invalid command.
        } 
        new_family.heads.push_back(head.get_value());
    } // Process heads.

    for (int child : children) {
        if (persons[child].is_child) { 
            std::cout << "\tChild " << child << " is already parented." << \
                std::endl;
            return; // Cannot be child twice.
        }
        new_family.children.push_back(child);
    } // Process families.

    std::vector<Person*> this_family_persons;
    // At this point, we know its a valid family; so initialize it.
    for (auto head : heads) {
        if (head.get_value() == 0) { // Handle unknowns.
            new_family.set_unknown(head.get_key()[0]);
        } else {
            persons[head.get_value()].set_marriage(head.get_key(), family_id);
            this_family_persons.push_back(&persons[head.get_value()]);
        }
    } // Initialize heads.

    for (auto child : children) {
        persons[child].set_parentage(family_id);
        this_family_persons.push_back(&persons[child]);
    } // Initialize children

    Component componetized_family = Component(family_id, this_family_persons);
    for (auto person : this_family_persons) {
        if (person->representative > 0) {
            int this_rep = person->representative;
            Component this_component = uf_object.get_component_by_id(this_rep);
            uf_object.union_f(componetized_family, this_component);
            componetized_family = uf_object.get_component_by_id(family_id);
        }
        person->representative = family_id;
    } // Union with other representatives.
    uf_object.union_f(componetized_family, Component());

    families[family_id] = new_family;
    print_family(family_id);
} // FamilyGraph::make_family

/*
* FamilyGraph::relationship(int person1, int person2)
* Input: Two person identifying integers.
* Outputs: The string representation of how person1 an person2 are related.
*/
void FamilyGraph::relationship(int person1, int person2) {
    Component person1_rep = uf_object.find(&persons[person1]);
    Component person2_rep = uf_object.find(&persons[person2]);
    if (person1_rep.id == person2_rep.id) {
        std::cout << "Relation: ";
        breadth_first_search(person1, person2);
    } else {
        std::cout << "Persons " << person1 << " and " << person2 \
         << " are not related." << std::endl;
    }
} // relationship()

/*
* FamilyGraph::breadth_first_search(int person1, int person2)
* Input: Two person identifying integers.
* Outputs: The built path between two person vertices.
*/
void FamilyGraph::breadth_first_search(int person1, int person2) {
    std::vector<int> visited(persons.size(), 0);
    std::vector<int> prev(persons.size(), -1);
    Queue search_queue;

    search_queue.enqueue(person1);
    visited[person1] = 1;

    Person * this_person;
    while (!search_queue.is_empty()) {
        int this_persons_id = search_queue.dequeue();
        this_person = &persons[this_persons_id];

        if (this_person->is_child) {
            int this_parentage = this_person->get_parentage();
            for (auto person : families[this_parentage].get_persons()) {
                if (!visited[person]) {
                    search_queue.enqueue(person);
                    visited[person] = 1;
                    prev[person] = this_persons_id;
                }
            }
        } // Iterate over parentage.
        if (this_person->is_married) {
            int this_marriage = this_person->get_marriage();
            for (auto person : families[this_marriage].get_persons()) {
                if (!visited[person]) {
                    search_queue.enqueue(person);
                    visited[person] = 1;
                    prev[person] = this_persons_id;
                }
            }
        } // Iterate over marriage.
    }

    build_path(person1, person2, prev);
} // breadth_first_search


/*
* FamilyGraph::build_path(int person1, int person2, std::vector<int> prev)
* Input: Two person identifiers, a vector of associated previous vertices.
* Outputs: The built path between two vertices.
*/
void FamilyGraph::build_path(int person1, int person2, std::vector<int> prev) {
    std::vector<int> path;
    path.push_back(person2);
    for (int at = prev[person2]; at != -1; at = prev[at]) {
        path.push_back(at); // Add this person to path.
    }

    for (size_t i = path.size()-1; i > 0 ; i--) {
        std::cout << "person " << path[i] << " -> ";
        std::cout << "family ";
        std::cout << get_direct_relation(&persons[path[i]], &persons[path[i-1]]);
        std::cout << " -> ";
    }
    std::cout << "person " << path[0] << std::endl;
} // build_path

/*
* FamilyGraph::ancestors(int person)
* Input: One person identifier.
* Outputs: All known ancestors of one vertex (person).
*/
void FamilyGraph::ancestors(int person) {
    Person * person_ptr = &persons[person];
    if (!person_ptr->is_child) {
        std::cout << "Person " << person \
        << " has no known ancestors" << std::endl;
        return;
    } // Ensure they can have ancestors.

    Family * family_ptr = &families[person_ptr->get_parentage()];

    if (family_ptr->heads.size() == 0) {
        std::cout << "Person " << person \
        << " has no known ancestors" << std::endl;
        return;        
    } // Ensure they can have ancestors.

    std::cout << "Person " << person << "'s known ancestors: ";

    Queue persons_q;
    for (auto head : family_ptr->heads) {
        persons_q.enqueue(head);
    } // Prime the pump.

    while(!persons_q.is_empty()) {
        int this_person_id = persons_q.dequeue();
        Person * this_person = &persons[this_person_id];  
        if (this_person->is_child) {
            Family * this_family = &families[this_person->get_parentage()];
            for (auto head : this_family->heads) {
                if (head == 0) continue; // Skip unknowns.
                persons_q.enqueue(head);
            } // Add all heads to queue for processing.
        } // Check if there are ancestors to add.

        std::cout << this_person_id << " ";         
    } // Process queue.

    std::cout << std::endl;
} // ancestors

/*
* FamilyGraph::descendants(int person)
* Input: One person identifier.
* Outputs: All known descendants of one vertex (person).
*/
void FamilyGraph::descendants(int person) {
    Person * person_ptr = &persons[person];
    if (!person_ptr->is_married) {
        std::cout << "Person " << person << " has no descendants." <<std::endl;
        return;
    } // Check if the person could have any descendants.

    Family * family_ptr = &families[person_ptr->get_marriage()];

    if (family_ptr->children.size() == 0) {
        std::cout << "Person " << person << " has no descendants." <<std::endl;
        return;
    } // Check if marriage has any offspring.

    std::cout << "Person " << person << "'s descendants: ";

    Queue persons_q;
    for (auto child : family_ptr->children) {
        persons_q.enqueue(child);
    }

    while (!persons_q.is_empty()) {
        int this_person_id = persons_q.dequeue();
        Person * this_person = &persons[this_person_id];
        if (this_person->is_married) {
            Family * this_family = &families[this_person->get_marriage()];
            for (auto child : this_family->children) {
                persons_q.enqueue(child);
            } // Add all children to queue for processing.
        } // Check if there are descendants to add.

        std::cout << this_person_id << " ";
    } // Process queue.
    std::cout << std::endl;
} // descendants

/*
* process_relate(FamilyGraph * graph, int person1, int person2)
* Input: The graph to check relationship with, the two people to check.
* Outputs: Results of relating two people, will be the shortest path
* between the two people if they are related.
*/
void process_relate(FamilyGraph * graph, int person1, int person2) {
    graph->relationship(person1, person2);
} // process_relate

/*
* process_family()
* Description: Wrapper for FamilyGraph::make_family().
*/
void process_family(FamilyGraph * graph,
                        int family,
                        vector<Pair> heads,
                        vector<int> children) {
    graph->make_family(family, heads, children);
} // process_family

/*
* process_descendants()
* Description: Wrapper for FamilyGraph::descendants().
*/
void process_descendants(FamilyGraph * graph, int person) {
    graph->descendants(person);
} // process_descendants

/*
* process_ancestors()
* Description: Wrapper for FamilyGraph::ancestors().
*/
void process_ancestors(FamilyGraph * graph, int person) {
    graph->ancestors(person);
} // process_descendants
#endif