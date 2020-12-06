#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 

std::string get_unigue_str(const std::string &user_form)
{
    std::string helper = user_form;
    std::sort(helper.begin(), helper.end()); 
    auto res = std::unique(helper.begin(), helper.end()); 
    return std::string(helper.begin(), res);
}

int count_shared_questions(const std::vector<std::string> &forms)
{
    int group_size = forms.size();
    std::string all_form_questions = "";
    for(auto form: forms)
    {
       all_form_questions += get_unigue_str(form);
    }
    std::string all_unique_questions = get_unigue_str(all_form_questions);

    /*
    loop question in all_unique_questions:
        if count_question_occurance(question) == size:
            question_from_everyone++
    return question_from_everyone
    */
    std::cout << "all questions: " << all_form_questions << "\t unigue q: " << all_unique_questions << "\t size: " << group_size << std::endl;
    return -1;
}

int main()
{
    int question_count = 0;
    std::ifstream file("input_example.txt");
    std::string line;
    std::vector<std::string> group_form;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
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