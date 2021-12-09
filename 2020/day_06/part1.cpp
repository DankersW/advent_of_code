#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 

int count_unique_questions(std::string &form)
{   
    std::sort(form.begin(), form.end()); 
    auto res = std::unique(form.begin(), form.end()); 
    auto unigue_str = std::string(form.begin(), res);
    return unigue_str.length();
}

int main()
{
    int question_count = 0;
    std::ifstream file("input_test.txt");
    std::string line;
    std::string group_form = "";
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
        if (line.compare("") != 0) { group_form += line; }
        else
        {
            question_count += count_unique_questions(group_form);
            group_form = "";
        }
    }
    std::cout << "questions asked: " << question_count << std::endl;
    return 0;
}