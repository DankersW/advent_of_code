#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>


std::string get_node(const std::string &entry)
{
    auto node_pos = entry.find(" bags ");
    return entry.substr(0, node_pos);
}

std::vector<std::vector<std::string>> get_edges(const std::string &entry)
{
    std::vector<std::vector<std::string>> edges;

    if (entry.find(" no ") == std::string::npos)
    {
        auto contains_pos = entry.find("contain ");
        auto edge_pos = entry.find(" bag", contains_pos);
        auto weigth_edge_1 = entry.substr(contains_pos+8, 1);
        auto edge_1 = entry.substr(contains_pos+10, edge_pos-contains_pos-10);
        edges.push_back({edge_1, weigth_edge_1});

        auto comma_pos = entry.find(", ");
        if (comma_pos != std::string::npos)
        {
            auto weigth_edge_2 = entry.substr(comma_pos+2, 1);
            auto edge2_pos = entry.find(" bag", comma_pos);

            auto edge_2 = entry.substr(comma_pos+4, edge2_pos-comma_pos-4);
            edges.push_back({edge_2, weigth_edge_2});
        }
        else
        {
            edges.push_back({"-1", "-1"});
        }
        
    }
    else 
    { 
        edges.push_back({"-1", "-1"}); 
        edges.push_back({"-1", "-1"});
    }
    return edges;
}

std::vector<std::string> color_to_id_translator(std::vector<std::string> &nodes)
{
    std::vector<std::string> map;
    for (auto node: nodes)
    {
        if (std::find(map.begin(), map.end(), node) == map.end())
        {
            map.push_back(node);
        }
    }
    for (auto _map: map)
    {
        std::cout << _map << std::endl;
    }
}

int main()
{
    std::ifstream file("input_example.txt");
    std::string line;
    std::vector<std::string> nodes = {};
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
        std::string node = get_node(line);
        std::vector<std::vector<std::string>> edges = get_edges(line);
        if (std::find(nodes.begin(), nodes.end(), node) == nodes.end()) { nodes.push_back(node); }
        std::cout << "node: " << node;
        for (auto edge: edges)
        {
            std::cout << "\t edge: " << edge[0] << "~ " << edge[1];
        }
        std::cout << std::endl;
    }
    line.seekg(0);
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
        std::string node = get_node(line);
        std::vector<std::vector<std::string>> edges = get_edges(line);
        if (std::find(nodes.begin(), nodes.end(), node) == nodes.end()) { nodes.push_back(node); }
        std::cout << "node: " << node;
        for (auto edge: edges)
        {
            std::cout << "\t edge: " << edge[0] << "~ " << edge[1];
        }
        std::cout << std::endl;
    }

    for (auto node: nodes)
    {
        std::cout << node << std::endl;
    }

    //test_i();
    
    return 0;
}