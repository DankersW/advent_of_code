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
        
        if (visited[i]) { return -1; }
        else { visited[i] = 1; }
    }
    return acc;
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
    for (auto i=0; i<instructions.size(); i++)
    {
        auto test_insts = instructions;
        if (instructions[i].opp.compare("nop") == 0) { test_insts[i].opp = "jmp"; }
        else if (instructions[i].opp.compare("jmp") == 0) { test_insts[i].opp = "nop"; }

        acc = execute_program(test_insts);
        if (acc != -1) { break; }        
    }
    std::cout << "acc: " << acc << std::endl;
    return 0;
}