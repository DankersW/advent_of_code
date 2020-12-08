#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

bool good_bag_color(const std::vector<std::string> &interesting_colors, std::string entry)
{
    for(auto color: interesting_colors)
    {
        if (entry.find(color) != std::string::npos)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::ifstream file("input_example.txt");
    std::string line;
    std::vector<std::string> raw_input;
    

    while (std::getline(file, line))
    {
        raw_input.push_back(line);
    }

    std::vector<std::string> intereting_colors = {"shiny gold"};
    int bag_counter = 0;
    for (auto it = raw_input.rbegin(); it != raw_input.rend(); ++it)
    {
        std::string entry = *it;
        if (good_bag_color(intereting_colors, entry))
        {
            std::string parent_bag = entry.substr(0, entry.find(" bags"));
            if (std::find(intereting_colors.begin(), intereting_colors.end(), parent_bag) == intereting_colors.end())
            {
                intereting_colors.push_back(parent_bag);
                //std::cout << "add node" << parent_bag << std::endl;
            }
            bag_counter++;
        }
    }
    

    for(auto i: intereting_colors)
    {
        std::cout << i << " - " << std::endl;
    }

    std::cout << "Bag counter: " << bag_counter << std::endl;
}