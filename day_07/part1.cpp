#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <bits/stdc++.h>
#include <memory>

#include "Graph.h" 


std::string get_node(const std::string &entry)
{
    auto node_pos = entry.find(" bags ");
    return entry.substr(0, node_pos);
}

std::pair<std::string, int> get_edge_1(const std::string &entry)
{
    if (entry.find(" no ") == std::string::npos)
    {
        auto contains_pos = entry.find("contain ");
        auto edge_pos = entry.find(" bag", contains_pos);
        auto weigth_edge = std::stoi(entry.substr(contains_pos+8, 1));
        auto edge = entry.substr(contains_pos+10, edge_pos-contains_pos-10);
        return std::make_pair(edge, weigth_edge);
    }
    else { return std::make_pair(std::string("NA"), -1); }
}

std::pair<std::string, int> get_edge_2(const std::string &entry)
{
    auto comma_pos = entry.find(", ");
    if (comma_pos != std::string::npos)
    {
        auto weigth_edge = std::stoi(entry.substr(comma_pos+2, 1));
        auto edge_pos = entry.find(" bag", comma_pos);
        auto edge = entry.substr(comma_pos+4, edge_pos-comma_pos-4);
        return std::make_pair(edge, weigth_edge);
    }
    else { return std::make_pair(std::string("NA"), -1); }
}

int main()
{
    std::ifstream file("input_example.txt");
    std::string line;
    std::vector<std::string> raw_input;
    std::vector<std::string> nodes = {};
    while (std::getline(file, line))
    {
        std::string node = get_node(line);
        if (std::find(nodes.begin(), nodes.end(), node) == nodes.end()) { nodes.push_back(node); }
        raw_input.push_back(line);
    }

    int graph_size = nodes.size();
    auto graph = std::make_unique<Graph>(graph_size);

    for (auto &line: raw_input)
    {
        std::cout << line << std::endl;

        std::string node = get_node(line);
        int node_id = std::find(nodes.begin(), nodes.end(), node) - nodes.begin();
        std::pair<std::string, int> edge_1 = get_edge_1(line);
        std::pair<std::string, int> edge_2 = get_edge_2(line);

        if (edge_1.first.compare("NA") != 0)
        {
            int edge1_id = std::find(nodes.begin(), nodes.end(), edge_1.first) - nodes.begin();
            Edge edge = {node_id, edge1_id, edge_1.second};
            graph->add_edge(edge);
        }
        if (edge_2.first.compare("NA") != 0)
        {
            int edge2_id = std::find(nodes.begin(), nodes.end(), edge_2.first) - nodes.begin();
            Edge edge = {node_id, edge2_id, edge_2.second};
            graph->add_edge(edge);
        }
            

        std::cout << "node: " << node_id << "\t edge1:" << edge_1.first << "  " << edge_1.second << "\t edge2:" << edge_2.first << "  " << edge_2.second << std::endl;
        std::cout << std::endl;
    }


    
    // construct a different graph: 
    // https://www.techiedelight.com/graph-implementation-using-stl/



    for (size_t i = 0; i < graph_size; i++)
    {
        std::cout << i << ": " << nodes[i] << std::endl;
    }

    //test_i();

    graph->print_graph(graph_size);

    graph->printAllPaths(2,4);
    
    return 0;
}

