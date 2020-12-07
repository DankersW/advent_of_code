#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

void translate_bag_to_node(std::vector<std::string> bags)
{
    std::vector<std::string> nodes;
    for (auto bag: bags)
    {
        if (std::find(nodes.begin(), nodes.end(), bag) == nodes.end())
        {
            std::cout << "new bag: " << bag << std::endl;
            nodes.push_back(bag);
        }

    }


    for (auto node: nodes)
    {
        std::cout << node << std::endl;
    }
}

void get_bag(std::string entry)
{
    std::cout << entry << std::endl;
    
    auto node_pos = entry.find(" bags ");
    auto node = entry.substr(0, node_pos);

    std::cout << node << "\t" << std::endl;

    std::vector<std::string> edges = {};
    if (entry.find(" no ") == std::string::npos)
    {
        auto contains_pos = entry.find("contain ");
        auto edge_pos = entry.find(" bag", contains_pos);

        auto weigth_edge_1 = entry.substr(contains_pos+8, 1);
        auto edge_1 = entry.substr(contains_pos+10, edge_pos-contains_pos-10);

        auto comma_pos = entry.find(", ");
        if (comma_pos != std::string::npos)
        {
            auto weigth_edge_2 = entry.substr(comma_pos+2, 1);
            auto edge2_pos = entry.find(" bag", comma_pos);

            auto edge_2 = entry.substr(comma_pos+4, edge2_pos-comma_pos-4);
            std::cout << weigth_edge_2 << "-   |" << edge_2 << "|" << std::endl;
        }


        std::cout << edge_1 << " - " << weigth_edge_1 << std::endl;
    }
    

    
    std::cout << std::endl;
}

int main()
{
    std::ifstream file("input_example.txt");
    std::string line;
    std::vector<std::string> raw_input;
    while (std::getline(file, line))
    {
        //std::cout << line << std::endl;
        raw_input.push_back(line);

        //node
    }

    get_bag("light red bags contain 1 bright white bag, 2 muted yellow bags.");
    get_bag("dotted black bags contain no other bags");
    get_bag("bright white bags contain 1 shiny gold bag.");

    return 0;
}