// build and execute: g++ -o ../build/part1 part1.cpp && ./../build/part1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

std::vector<int> split(const std::string s, const char delim)
{
    auto delim_index = s.find_first_of(delim);
    auto first = std::stoi(s.substr(0, delim_index));
    auto last = std::stoi(s.substr(delim_index + 1));
    return {first, last};
}

int main() 
{
    auto valid_pwd_counter = 0;
    std::ifstream file("input_part2.txt");
    std::string line; 
    while (std::getline(file, line))
    {
        std::istringstream buf(line);
        std::istream_iterator<std::string> beg(buf), end;
        std::vector<std::string> tokens(beg, end);
        
        std::vector<int> locations = split(tokens[0], '-');
        char pattern = tokens[1][0]; 
        std::string pwd = tokens[2];

        char first_char = pwd[locations[0]-1];
        char last_char = pwd[locations[1]-1];

        bool correct_pwd = (first_char != pattern && last_char == pattern) || (first_char == pattern && last_char != pattern);
        if (correct_pwd) { valid_pwd_counter++; }
    }

    std::cout << "correct pwds: " << valid_pwd_counter << std::endl;
    return 0;
}
