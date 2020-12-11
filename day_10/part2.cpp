#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

struct Adapter{
    bool found;
    int base_voltage;
    int voltage;
    int v_diff;
};

Adapter find_matching_adapter(const std::vector<int> &adapters, const int &voltage)
{
    //std::cout << "voltage: " << voltage << std::endl;
    for(auto adapter: adapters)
    {
        //std::cout << "adapter: " << adapter << std::endl;
        if (voltage + 1 == adapter)
        {
            return {true, voltage, adapter, adapter-voltage};
        }
        else if (voltage + 2 == adapter)
        {
            return {true, voltage, adapter, adapter-voltage};
        }
        else if (voltage + 3 == adapter)
        {
            return {true, voltage, adapter, adapter-voltage};
        }
    }
    return {false, voltage, voltage, voltage-voltage};
}

int main()
{
    std::vector<int> adapters;
    std::ifstream file("input_test.txt");
    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
        adapters.push_back(std::stoi(line));
    }
    std::sort(adapters.begin(), adapters.end());
    

    int diff_1_counter = 0;
    int diff_3_counter = 0;
    int starting_voltage = 0;
    Adapter adapter = find_matching_adapter(adapters, starting_voltage);
    while (adapter.found)
    {
        std::cout << "for voltage: " << adapter.base_voltage << " found adapter: " << adapter.voltage << "\t diff: " << adapter.v_diff << std::endl;
        if (adapter.v_diff == 1)
        {
            diff_1_counter++;
        }
        else if (adapter.v_diff == 3)
        {
            diff_3_counter++;
        }

        adapter = find_matching_adapter(adapters, adapter.voltage);
    }
    diff_3_counter++;

    std::cout << "diff 1: " << diff_1_counter << " diff 3: " << diff_3_counter << std::endl;

    std::cout << "Joint diff: " << diff_3_counter*diff_1_counter <<std::endl;
}