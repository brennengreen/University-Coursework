/*
* COMPONENT CLASS
* Handles processing of components for union-find.
*/
#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
#include "person.h"

class Component {
    public:
        Component() {}
        Component(int i) : id(i) {}
        Component(int i, std::vector<Person*> p) : id(i), persons(p) {}
        bool find(Person * person);
        void join(Component other_component);
        int id;
        std::vector<Person*> persons;
}; // Component

/*
* Component::join(Component other_component)
* Input: A component to join to this component.
*/

void Component::join(Component other_component) {
    for (auto person : other_component.persons) {
        if (find(person)) continue; // If the person's there already, dont add.
        else {
            person->representative = id;
            persons.push_back(person);
        }
    } // Add other persons to this component.
} // join()

/*
* Component::find(Person * person)
* Input: A pointer to a person to look for in this component.
* Returns: True if the person is found in the component, false otherwise.
*/

bool Component::find(Person * person) {
    for (auto curr_person : persons) {
        if (curr_person == person) {
            return true;
        }
    } // Look for the target.
    return false;
} // find()

#endif