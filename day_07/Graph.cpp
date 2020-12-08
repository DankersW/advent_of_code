#include "Graph.h"


Graph::Graph(int graph_size)
{
    this->_graph_size = graph_size;
    _adjList.resize(graph_size);
}

void Graph::add_edge(const Edge &edge)
{
    int src = edge.src;
    int dest = edge.dest;
    int weight = edge.weight;

    _adjList[src].push_back(std::make_pair(dest, weight));
}

void Graph::print_graph(int graph_size)
{
    for (int i = 0; i < graph_size; i++)
    {
        for (Pair v : _adjList[i])
        {
            std::cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
        }
        std::cout << std::endl;
    }
}

// Prints all paths from 's' to 'd' 
void Graph::printAllPaths(int s, int d) 
{ 
    // Mark all the vertices as not visited 
    bool* visited = new bool[_graph_size]; 
  
    // Create an array to store paths 
    int* path = new int[_graph_size]; 
    int path_index = 0; // Initialize path[] as empty 
  
    // Initialize all vertices as not visited 
    for (int i = 0; i < _graph_size; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function to print all paths 
    printAllPathsUtil(s, d, visited, path, path_index); 
} 
  
// A recursive function to print all paths from 'u' to 'd'. 
// visited[] keeps track of vertices in current path. 
// path[] stores actual vertices and path_index is current 
// index in path[] 
void Graph::printAllPathsUtil(int u, int d, bool visited[], int path[], int& path_index) 
{ 
    // Mark the current node and store it in path[] 
    visited[u] = true; 
    path[path_index] = u; 
    path_index++; 
  
    // If current vertex is same as destination, then print 
    // current path[] 
    if (u == d) { 
        for (int i = 0; i < path_index; i++)
        { 
            std::cout << path[i] << " "; 
        }
        std::cout << std::endl; 
    } 
    else // If current vertex is not destination 
    { 
        for(auto i = 0; i <= _adjList[u].size(); i++)
        {
            if (!visited[i])
            {
                printAllPathsUtil(i, d, visited, path, path_index); 
            }
        }

        // Recur for all the vertices adjacent to current vertex 
        //std::list<int>::iterator i; 
        //for (i = _adjList[u].begin(); i != _adjList[u].end(); ++i) 
        //    if (!visited[*i]) 
        //        printAllPathsUtil(*i, d, visited, path, path_index); 
    } 
  
    // Remove current vertex from path[] and mark it as unvisited 
    path_index--; 
    visited[u] = false; 
} 
