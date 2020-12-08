#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <vector>
#include <iostream>
//#include <list> 

struct Edge {
    int src, dest, weight;
};
 
typedef std::pair<int, int> Pair;


class Graph
{
public:
    std::vector<std::vector<Pair>> _adjList;
    int _graph_size;

    Graph(int graph_size);

    void add_edge(const Edge &edge);
    void print_graph(int graph_size);

    void printAllPaths(int s, int d);
    void printAllPathsUtil(int u, int d, bool visited[], int path[], int& path_index);
};

#endif