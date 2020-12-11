#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <chrono>


std::vector<int> adapters;
long int path_memory[100] = {0};

long int count_path(int i)
{
    if (i == adapters.size() - 1)
    {
        return 1;
    }

    // check memory
    if (path_memory[i] != 0) { return path_memory[i]; }

    long int path_counter = 0;
    for (int j = i+1; j<adapters.size(); ++j)
    {
        if (adapters[j] - adapters[i] <= 3) { path_counter += count_path(j); }
    }

    path_memory[i] = path_counter;
    return path_counter;
}

int main()
{
    std::ifstream file("input_test.txt");
    std::string line;
    while (std::getline(file, line))
    {
        adapters.push_back(std::stoi(line));
    }
    adapters.push_back(0);
    std::sort(adapters.begin(), adapters.end());

    auto start_time = std::chrono::high_resolution_clock::now();
    long int path_counter = count_path(0);
    auto stop_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop_time - start_time).count();

    std::cout << "Possible paths: " << path_counter << std::endl;
    std::cout << "time: " << duration << " micro-seconds" << std::endl;
}