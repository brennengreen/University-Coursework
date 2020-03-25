/*
 * File: imdb.h
 * Course: CS216-00x
 * Project: Lab 8
 * Purpose: Declaration of IMDB class
 *          This class represents a actor-movie database
 *          It contains two private data memebers:
 *             movies_db: represents a mapping from a movie (title) to a set of actors (names) in this movie
 *             actors_db: represents a mapping from a actor (name) to a set of movies (titles) which this actor was in
 */

#ifndef IMDB_H
#define IMDB_H

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

class IMDB
{
    public:
        IMDB();         // default constructor

        // insert a pair<actorName, the set of movieTitle of this actor>
        void insert_an_actor(string actorName, set<string> movieTitles);

        // use passing-in parameter, movieTitle, as the pattern to match 
        // one existing movie in the map
        // return the matched movie title from the map
        // otherwise return empty string
        string matchExistingMovie(string movieTitle) const;

        // check if a movieTitle does exist in the map
        // return true if it does; otherwise return false
        bool isExistingMovie(string movieTitle) const;
        
        // check if an actorName does exist in the map
        // return true if it does; otherwise return false
        bool isExistingActor(string actorName) const;

        // return a set of movie titles which actorName was in
        // if the passing-in parameter: actorName, is not in the map, 
        //      display message and return an empty set
        set<string> find_movies_for_an_actor(string actorName) const;

        // return a set of actor names which were all in the movieTitle
        // if the passing-in parameter: movieTitle is not in the map, 
        //      display message and return an empty set
        set<string> find_actors_in_a_movie(string movieTitle) const;
    
        // you are allowed to add more member functions if you need

    private:    
        map<string, set<string> > movies_db;    // map of <movie title, set of actors in this movie> 
        map<string, set<string> > actors_db;    // map of <actor name, set of movies this actor was in>
};

#endif   /* IMDB_H */
