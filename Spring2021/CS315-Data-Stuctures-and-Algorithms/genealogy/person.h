/*
* PERSON CLASS
* Handles all representation of a person.
*/
#ifndef PERSON_H
#define PERSON_H

#include <string>

#include "family.h"

class Person {
    public:
        Person() { identifier = 'u'; } // u means undefined.
        Person(std::string i, int f) {
            if (i.compare("Wife") == 0) {
                identifier = 'w';
                marriage = f;
                is_married = 1;
            } else if (i.compare("Husband") == 0) {
                identifier = 'h';
                marriage = f;
                is_married = 1;
            } else {
                identifier = 'c';
                parentage = f;
                is_child = 1;
            } // Check if head of househole or child.
        }
        bool is_defined() { return (is_child || is_married); }

        void set_marriage(std::string i, int family) {
            if (i.compare("Wife") == 0) {
                identifier = 'w';
            } else if (i.compare("Husband") == 0) {
                identifier = 'h';
            } // Update identifier.
            marriage = family;
            is_married = 1;
        } // set_marriage
        void set_parentage(int family) { 
            parentage = family;
            is_child = 1;
        } // set_parentage
        
        char get_id() { return identifier; }
        int get_parentage() { return parentage; }
        int get_marriage() { return marriage; }

        int is_child = 0;
        int is_married = 0;
        
        int representative = 0;

    private:
        int parentage;
        int marriage;
        char identifier; // h (husband), w (wife), c (child), u (undefined)

}; // Person

/*
* get_direct_relation(Person * person1, Person * person2)
* Input: Two pointers to a person object.
* Returns: The identifier of the family that relates person1 and person2.
*/
int get_direct_relation(Person * person1, Person * person2) {
    if (person1->get_marriage() == person2->get_marriage() 
        && person1->is_married && person2->is_married) {
        return person1->get_marriage();
    } // Related by marriage.
    if (person1->get_parentage() == person2->get_parentage() 
        && person1->is_child && person2->is_child) {
        return person1->get_parentage();
    } // Related by parents.
    if (person1->get_marriage() == person2->get_parentage() 
        && person1->is_married && person2->is_child) {
        return person1->get_marriage();
    } // Child-Parent Relation.
    if (person1->get_parentage() == person2->get_marriage() 
        && person1->is_child && person2->is_married) {
        return person1->get_parentage();
    } // Child-Parent Relation.
    return -1; // No Direct Relation.
} // get_direct_relation

#endif