/*
* FAMILY CLASS
* Handles all representation of a family.
*/
#ifndef FAMILY_H
#define FAMILY_H

#include "person.h"
#include <vector>
#include <string>

class Family {
    public:
        Family() {}
        std::vector<int> heads; // Heads of Household (hh hw, wh, ww)
        std::vector<int> children;
        std::vector<int> get_persons();
        bool is_empty() { return (heads.size() < 1); } // Empty if no heads.
        std::string get_unknown_gender();
        void set_unknown(char gender) { 
            unknowns.insert(unknowns.begin(), gender);
        }
    private:
        std::vector<char> unknowns; // List of the genders of unknowns.
}; // Family

/*
* std::vector<int> Family::get_persons()
* Returns: A vector of person identifiers.
*/
std::vector<int> Family::get_persons() {
    std::vector<int> result;
    for (auto head : heads) {
        if (head > 0) {
            result.push_back(head);
        }
    }
    for (auto child : children) {
        if (child > 0) {
            result.push_back(child);
        }
    }
    return result;
}


/*
* Family::get_unknown_gender()
* Returns: String representation of the gender of unknown person.
*/
std::string Family::get_unknown_gender() {
    char gender = unknowns.back();
    unknowns.pop_back(); // Remove that unknown.
    if (gender == 'W' || gender == 'w') {
        return std::string("wife");
    } else if (gender == 'H' || gender == 'h') {
        return std::string("husband");
    }
    return std::string("gender unknown");
} // get_unknown_gender

#endif