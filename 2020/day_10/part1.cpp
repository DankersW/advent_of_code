#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

struct Adapter{
    bool found;
    int voltage;
    int v_diff;
};

Adapter find_matching_adapter(const std::vector<int> &adapters, const int &voltage)
{
    for(auto adapter: adapters)
    {
        if (voltage + 1 == adapter) { return {true, adapter, adapter-voltage}; }
        else if (voltage + 2 == adapter) { return {true, adapter, adapter-voltage}; }
        else if (voltage + 3 == adapter) { return {true, adapter, adapter-voltage}; }
    }
    return {false, voltage, voltage-voltage};
}

int main()
{
    std::vector<int> adapters;
    std::ifstream file("input_test.txt");
    std::string line;
    while (std::getline(file, line))
    {
        adapters.push_back(std::stoi(line));
    }
    std::sort(adapters.begin(), adapters.end());
    

    int diff_1_counter = 0;
    int diff_3_counter = 1;
    Adapter adapter = find_matching_adapter(adapters, 0);
    while (adapter.found)
    {
        if (adapter.v_diff == 1) { diff_1_counter++; }
        else if (adapter.v_diff == 3) { diff_3_counter++; }
        adapter = find_matching_adapter(adapters, adapter.voltage);
    }

    std::cout << "Joint diff: " << diff_3_counter*diff_1_counter <<std::endl;
}