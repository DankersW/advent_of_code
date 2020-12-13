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

int get_direction_index_left(int jump, int index)
{
    if (index - jump >= 0) { return index - jump; }
    else { return index - jump + 4; }
}

int get_direction_index_right(int jump, int index)
{
    if (jump + index < 4) { return jump + index; }
    else { return jump + index - 4; }
}

char calc_direction(const char &starting_direction, const char &heading, int turning_degrees)
{
    char directions[4] = {'N', 'E', 'S', 'W'};

    int jumps = turning_degrees / 90;
    int index_start_direction = std::distance(directions, std::find(directions, directions + 4, starting_direction));

    int direction_index = (heading == 'L') ? get_direction_index_left(jumps, index_start_direction) : 
                                             get_direction_index_right(jumps, index_start_direction);
    return directions[direction_index];
}

int calc_manhatten_dist(const std::vector<Instruction> &instructions, char starting_direction = 'E')
{
    int east_counter = 0;
    int north_counter = 0;

    char direction = starting_direction;

    for (auto instr: instructions)
    {
        if (instr.action == 'N' || (instr.action == 'F' && direction == 'N')) { north_counter += instr.value; }
        else if (instr.action == 'S' || (instr.action == 'F' && direction == 'S')) { north_counter -= instr.value; }
        else if (instr.action == 'E' || (instr.action == 'F' && direction == 'E')) { east_counter += instr.value; }
        else if (instr.action == 'W' || (instr.action == 'F' && direction == 'W')) { east_counter -= instr.value; }
        else if (instr.action == 'L' || instr.action == 'R') { direction = calc_direction(direction, instr.action, instr.value); }
    }
    return abs(north_counter) + abs(east_counter);
}

int main()
{
    std::vector<Instruction> instructions;
    std::ifstream file("input_test.txt");
    std::string line;
    while (std::getline(file, line))
    {
        instructions.push_back({line[0], std::stoi(line.substr(1))});
    }

    int distance = calc_manhatten_dist(instructions);
    std::cout << "manhatten distance: " << distance << std::endl;

    return 0;
}