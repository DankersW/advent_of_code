// build and execute: g++ -o ../build/part1 part1.cpp && ./../build/part1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <regex>

std::vector<int> split(const std::string s, const char delim)
{
    auto delim_index = s.find_first_of(delim);
    auto first = std::stoi(s.substr(0, delim_index));
    auto last = std::stoi(s.substr(delim_index + 1));
    return {first, last};
}

int count_match_in_regex(std::string s, std::string re)
{
    std::regex words_regex(re);
    auto words_begin = std::sregex_iterator(s.begin(), s.end(), words_regex);
    auto words_end = std::sregex_iterator();
    return std::distance(words_begin, words_end);
}

int main() 
{
    auto valid_pwd_counter = 0;
    std::ifstream file("input_part1.txt");
    std::string line; 
    while (std::getline(file, line))
    {
        std::istringstream buf(line);
        std::istream_iterator<std::string> beg(buf), end;
        std::vector<std::string> tokens(beg, end);
        
        std::vector<int> min_max_values = split(tokens[0], '-');
        char pattern = tokens[1][0]; 
        std::string pwd = tokens[2];
        
        int pattern_hits = count_match_in_regex(pwd, std::string(1, pattern));
        if (min_max_values[0] <= pattern_hits && min_max_values[1] >= pattern_hits) { valid_pwd_counter++; }
    }

    std::cout << "correct pwds: " << valid_pwd_counter << std::endl;
    return 0;
}
