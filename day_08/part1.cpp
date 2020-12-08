#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

struct Instruction
{
    std::string opp;
    int arg;
};

int main()
{
    std::ifstream file("input_test.txt");
    std::string line;
    std::vector<Instruction> instructions;
    while (std::getline(file, line))
    {
        instructions.push_back({line.substr(0, 3), std::stoi(line.substr(4))});
    }
    
    auto instruction_set_size = instructions.size();
    bool visited[instruction_set_size] = {0};

    auto acc = 0;
    for (auto i=0; i<instruction_set_size; i++)
    {
        if (instructions[i].opp.compare("acc") == 0) { acc += instructions[i].arg; }
        else if (instructions[i].opp.compare("jmp") == 0){ i += instructions[i].arg -1; }
        
        if (visited[i]) { break; }
        else { visited[i] = 1; }
    }

    std::cout << "acc: " << acc << std::endl;
    return 0;
}