#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

struct Instruction
{
    char action;
    int value;
};

char calc_direction(const char &starting_direction, int turning_degrees)
{
    char directions[4] = {'N', 'E', 'S', 'W'};

    int jumps = turning_degrees / 90;
    int index_start_direction = std::distance(directions, std::find(directions, directions + 4, starting_direction));
  
    if (jumps + index_start_direction < 4)
    {
        return directions[jumps + index_start_direction];
    }
    else
    {
        return directions[jumps + index_start_direction-4];
    }
}

int follow_instructions(const std::vector<Instruction> &instructions, char starting_direction = 'E')
{
    int east_counter = 0;
    int north_counter = 0;

    char direction = starting_direction;

    for (auto instr: instructions)
    {
        std::cout << instr.action << "-" << instr.value << std::endl;

        if (instr.action == 'N' || (instr.action == 'F' && direction == 'N'))
        {
            north_counter += instr.value;
        }
        else if (instr.action == 'S' || (instr.action == 'F' && direction == 'S'))
        {
            north_counter -= instr.value;
        }
        else if (instr.action == 'E' || (instr.action == 'F' && direction == 'E'))
        {
            east_counter += instr.value;
        }
        else if (instr.action == 'W' || (instr.action == 'F' && direction == 'W'))
        {
            east_counter -= instr.value;
        }
        else if (instr.action == 'L' || instr.action == 'R')
        {
            direction = calc_direction(direction, instr.value);
        }
        std::cout << "east: " << east_counter << "\t north: " << north_counter << std::endl;
    }

    return abs(north_counter) + abs(east_counter);
}


int main()
{
    std::vector<Instruction> instructions;
    std::ifstream file("input_example.txt");
    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
        instructions.push_back({line[0], std::stoi(line.substr(1))});
    }

    //int distance = follow_instructions(instructions);
    //std::cout << "manhatten distance: " << distance << std::endl;

    std::cout << calc_direction('N', 90) << std::endl;
    std::cout << calc_direction('E', 90) << std::endl;
    std::cout << calc_direction('S', 90) << std::endl;
    std::cout << calc_direction('W', 90) << std::endl;
    std::cout << calc_direction('N', 180) << std::endl;
    std::cout << calc_direction('E', 180) << std::endl;
    std::cout << calc_direction('S', 180) << std::endl;
    std::cout << calc_direction('W', 180) << std::endl;
    
    return 0;
}