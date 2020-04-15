#include "Graph.h"
#include <queue>

Graph::Graph() {
}


bool Graph::hasEdge(char v, char w) {
	set<char> thisAdjMap = adjMap[v];
	for (auto node : thisAdjMap)
	{
		if (node == w) return true;
	}
	return false;	
}

void Graph::addEdge(char v, char w) {
	adjMap[v].insert(w);
	adjMap[w].insert(v);
	
}


int Graph::BFS(char s, char t, map<char, int>& distance, map<char, char>& go_through) {
	for (auto it = adjMap.begin(); it!=adjMap.end(); ++it)
	{
		char currVertex = it->first;
		distance[currVertex] = -1;
		queue<char> thisQ;
		distance[s] = 0;
		go_through[s] = s;
		thisQ.push(s);
		char current = s;
		while (thisQ.size() > 0 && current != t) {
			current = thisQ.front();
			thisQ.pop();
			for ( auto w : adjMap[current] )
			{
			    if (distance[w] == -1) {
				distance[w] = distance[current]+1;
				go_through[w] = current;
				thisQ.push(w);
			    }
			}
		}
		return distance[t];
	}
}


