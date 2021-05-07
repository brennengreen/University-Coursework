/*
* UNION-FIND CLASS
* Handles the union-find algorithm.
*/
#ifndef UNION_FIND_H
#define UNION_FIND_H

#include "component.h"
#include "family.h"
#include "person.h"

#include <vector>

class UnionFind {
    public:
        UnionFind() {}
        UnionFind(Component c) { components.push_back(c); }
        void union_f(Component a, Component b);
        Component find(Person * a);
        Component get_component_by_id(int id) {
            for (auto component : components) {
                if (component.id == id) {
                    return component;
                }
            }
            return Component();
        }
    private:
        std::vector<Component> components;
}; // UnionFind

/*
* Component UnionFind::find(Person * a)
* Input: A pointer to a person to look for in the union-find.
* Returns: The component the person is in, if found, or an empty component.
*/
Component UnionFind::find(Person * a) {
    for (auto component : components) {
        if (a->representative == component.id) {
            return component;
        } // Found
    }
    return Component(); // Null components is not found, won't happen.
} // find()

/*
* UnionFind::union_f(Component a, Component b)
* Input: Two components to union into one component.
*/
void UnionFind::union_f(Component a, Component b) {
    std::vector<Component> new_components;

    a.join(b);
    for (auto component : components) {
        // Exclude the components were joining.
        if (component.id == a.id || component.id == b.id) continue;
        new_components.push_back(component);
    } // Rebuild the components vector.
    new_components.push_back(a);

    components = new_components;
} // person()

#endif