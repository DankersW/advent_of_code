#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
#include <algorithm>

std::string get_unigue_str(const std::string &user_form)
{
    std::string helper = user_form;
    std::sort(helper.begin(), helper.end()); 
    auto res = std::unique(helper.begin(), helper.end()); 
    return std::string(helper.begin(), res);
}

int count_shared_questions(const std::vector<std::string> &forms)
{
    int question_counter = 0;
    int group_size = forms.size();
    std::string all_form_questions = "";
    for(auto form: forms)
    {
       all_form_questions += get_unigue_str(form);
    }
    std::string all_unique_questions = get_unigue_str(all_form_questions);

    for (auto letter: all_unique_questions)
    {
        auto letter_count = std::count(all_form_questions.begin(), all_form_questions.end(), letter);
        if (letter_count == group_size){ question_counter++; }
    }
    return question_counter;
}

int main()
{
    int question_count = 0;
    std::ifstream file("input_test.txt");
    std::string line;
    std::vector<std::string> group_form;
    while (std::getline(file, line))
    {
        if (line.compare("") != 0) { group_form.push_back(line); }
        else
        {
            question_count += count_shared_questions(group_form);
            group_form = {};
        }
    }
    std::cout << "questions asked: " << question_count << std::endl;
    return 0;
}