#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

struct Location
{
    int north;
    int east;
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

int main()
{
    Location ship_loc = {0,0};
    Location waypoint = {1,10};

    std::cout << "ship N: " << ship_loc.north << " E: " << ship_loc.east << "\t way N: " << waypoint.north << " E: " << waypoint.east << std::endl;


    std::ifstream file("input_example.txt");
    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
        
        char action = line[0];
        int value = std::stoi(line.substr(1));

        if (action == 'N' ) {
            waypoint.north += value;
        }
        else if (action == 'S' ) {
            waypoint.north -= value;
        }
        else if (action == 'E' ) {
            waypoint.east += value;
        }
        else if (action == 'W' ) {
            waypoint.east -= value;
        }

        else if (action == 'F') {
            ship_loc.north += waypoint.north * value;
            ship_loc.east += waypoint.east * value;
        }

        else if (action == 'L' || action == 'R'){
            //direction = calc_direction(direction, action, value);
        }




        std::cout <<  " --> ship N: " << ship_loc.north << " E: " << ship_loc.east << "\t way N: " << waypoint.north << " E: " << waypoint.east << std::endl;

        //if (action == 'N' || (action == 'F' && direction == 'N')) { north_counter += value; }


        //else if (action == 'S' || (action == 'F' && direction == 'S')) { north_counter -= value; }
        //else if (action == 'E' || (action == 'F' && direction == 'E')) { east_counter += value; }
        //else if (action == 'W' || (action == 'F' && direction == 'W')) { east_counter -= value; }
        //else if (action == 'L' || action == 'R') { direction = calc_direction(direction, action, value); }
    }


    int distance = abs(ship_loc.north) + abs(ship_loc.east);
    std::cout << "manhatten distance: " << distance << std::endl;

    return 0;
}