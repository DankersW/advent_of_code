#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct Instruction
{
    std::string opp;
    int arg;
};

int execute_program(const std::vector<Instruction> &instructions)
{
    bool visited[instructions.size()] = {0};
    auto acc = 0;
    bool terminated = true;
    for (auto i=0; i<instructions.size(); i++)
    {
        if (instructions[i].opp.compare("acc") == 0) { acc += instructions[i].arg; }
        else if (instructions[i].opp.compare("jmp") == 0){ i += instructions[i].arg -1; }
        
        if (visited[i])
        {
            terminated = false;
            break; 
        }
        else { visited[i] = 1; }
    }

    if (terminated) { return acc; }
    else { return -1; };
}

int main()
{
    std::ifstream file("input_test.txt");
    std::string line;
    std::vector<Instruction> instructions;
    while (std::getline(file, line))
    {
        instructions.push_back({line.substr(0, 3), std::stoi(line.substr(4))});
    }

    auto acc = 0;
    for (auto i=1; i<instructions.size(); i++)
    {
        auto test_insts = instructions;
        if (instructions[i+1].opp.compare("nop") == 0) { test_insts[i+1].opp = "jmp"; }
        else if (instructions[i+1].opp.compare("jmp") == 0) { test_insts[i+1].opp = "nop"; }

        acc = execute_program(test_insts);
        if (acc != -1) { break; }        
    }
    std::cout << "acc: " << acc << std::endl;
    return 0;
}