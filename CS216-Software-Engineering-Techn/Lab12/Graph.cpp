/*
 * File: Graph.cpp
 * Course: CS216-00x
 * Project: Lab 11
 * Purpose: Provide the implementation of Graph class
 */
#ifndef GRAPH_CPP
#define GRAPH_CPP
#include "Graph.h"

#include <iostream>
#include <queue>

// default constructor
template<typename Vertex> Graph<Vertex>::Graph()
{
}

// check if an edge exists between v and w
template<typename Vertex> bool Graph<Vertex>::hasEdge(Vertex v, Vertex w)
{
    if (adjMap.find(v) == adjMap.end())
        return false;
    if (adjMap[v].find(w) != adjMap[v].end())
        return true;
    else
        return false;
}

// add an edge between v and w to the graph
// note that it is an undirected graph
template<typename Vertex> void Graph<Vertex>::addEdge(Vertex v, Vertex w)
{
    adjMap[v].insert(w);
    adjMap[w].insert(v);
}

// Apply BFS traversal to find the shortest path from the given source s to destination t
// return the distnace from s to t
// if s or t does not exist, return INVALID_VERTEX (=-2) 
// if there is no path from s to t, return NOPATH (=-1)
// store the shortest path distance from the given source s  to vertex w in distance map<w, distance>
// store which next vertex to go through on the shortest path to the given source s in go_through map<w, v>. 
// Here a pair <w, v> in go_through map represents on the shortest path from w to the given source s, it needs to take the path: w-->v...-->s  
template<typename Vertex> int Graph<Vertex>::BFS(Vertex s, Vertex t, map<Vertex, int>& distance, map<Vertex, Vertex>& go_through)
{
    if ( adjMap.find(s) == adjMap.end() || adjMap.find(t) == adjMap.end())
    {
        cout << "Invalid source Vertex or/and destination Vertex!" << endl;
        return INVALID_VERTEX;
    }

    // Mark all the vertices with current distance to s: -1
    for (auto it = adjMap.begin(); it != adjMap.end(); it++)
    {
        distance[it->first] = NOPATH;
    }


    // Create a queue for BFS
    queue<Vertex> bfs;

    // Enqueue the source s
    bfs.push(s);
    // Mark the distance from the source s to s: 0
    distance[s] = 0;
    // Mark the shortest path to the given source s going through s
    go_through[s] = s;

    Vertex current = bfs.front();
    while(!bfs.empty() && current != t)
    {
        current = bfs.front();
        // Get all adjacent vertices of current Vertex
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        set<Vertex> adjVertices = adjMap[current];
        for(auto i  = adjVertices.begin(); i != adjVertices.end(); i++)
        {
            if(distance[*i] == NOPATH)
            {
                distance[*i] = distance[current]+1;
                go_through[*i] = current;
                bfs.push(*i);
            }
        }
        bfs.pop();
    }
    return distance[t];
}
#endif
