/*   genealogy.cpp                                       */
/*   Author: Brennen Green                               */
/*   CS315 Spring 2021 Assignment 5                      */
/*   Usage: ./genealogy [Expects input data on stream]   */
/*   Extra Credit: Please check read me section!         */
/*   Outputs: The output of a series of commands of the  */
/*   form:                                               */
/*   - Family n Husband n Wife n Child n ...  and        */
/*   - Relate n n                                        */
/*   Refer to README for program description and info.   */

// EXTERNAL LIBRARIES
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// INTERNAL LIBRARIES
#include "family_graph.h"
#include "keyvaluepair.h"

// PROTOTYPES
int parse_command(std::string line, FamilyGraph * graph);

/*
* main()
*/
int main() {
    FamilyGraph * graph = new FamilyGraph; 

    std::string this_line;
    while (std::getline(std::cin, this_line)) {
        int result = parse_command(this_line, graph);
        if (result == 0) {
            continue;
        } // Handle successful command.
        else {
            std::cout << "INVALID COMMAND ERROR" << std::endl; // Throw Error
            std::cout << "COMMAND: " << this_line << std::endl;
            std::cout << "EXITING..." << std::endl;
            return 0; 
        } // Handle erroneous command and exit.
    } // Parse lines of input.
    return 0;
} // main

/*
* int parse_command(std::string line, FamilyGraph * graph)
* Input: A line of characters, a FamilyGraph.
* Output: Command output.
* Returns: 0 if successful, 1 otherwise.
*/
int parse_command(std::string line, FamilyGraph * graph) {
    std::stringstream ss; // Stream for line.

    ss << line;

    std::string token; // Parses first token.
    std::string curr_arg; // Parses args.
    ss >> token;
    if (token.compare("Relate") == 0) {
        ss >> curr_arg;
        int person1 = std::stoi(curr_arg, nullptr, 10);
        ss >> curr_arg;
        int person2 = std::stoi(curr_arg, nullptr, 10);
        process_relate(graph, person1, person2);
        return 0;
    }
    else if (token.compare("Family") == 0) {
        // Parse family first.
        ss >> curr_arg;
        int family = std::stoi(curr_arg, nullptr, 10);

        // Parse heads, storing role as identifier.
        std::string id;

        std::vector<Pair> heads;
        ss >> id;
        ss >> curr_arg;
        int head1 = std::stoi(curr_arg, nullptr, 10);
        heads.push_back(Pair(id, head1));
        ss >> id;
        ss >> curr_arg;
        int head2 = std::stoi(curr_arg, nullptr, 10);
        heads.push_back(Pair(id, head2));

        // Parse children.
        std::vector<int> children;
        while (ss >> curr_arg) {
            ss >> curr_arg; // Parse person number.
            int curr_child = std::stoi(curr_arg, nullptr, 10);
            children.push_back(curr_child);
        } // Parse all the Child commands.
        
        process_family(graph, family, heads, children);
        return 0;
    } else if (token.compare("Descendants") == 0) {
        int person;
        ss >> person;
        process_descendants(graph, person);
        return 0;
    } else if (token.compare("Ancestors") == 0) {
        int person;
        ss >> person;
        process_ancestors(graph, person);
        return 0;
    } else {
        return 1; // Malformed command.
    } // Pick the right command.
} // parse_command