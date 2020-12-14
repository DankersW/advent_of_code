#include <iostream>
#include <string>
#include <fstream>

struct Location
{
    int x;
    int y;
};

Location move_waypoint(int degrees, char rotation, Location waypoint)
{
    for (int i=0; i < (degrees/90); ++i)
    {
        Location helper;
        if (rotation == 'R') { Location helper = {-waypoint.y, waypoint.x}; }
        else if (rotation == 'L') { Location helper = {waypoint.y, -waypoint.x}; }
        waypoint = helper;
    }
    return waypoint;
}

int main()
{
    Location ship_loc = {0,0};
    Location waypoint = {1,10};

    std::ifstream file("input_test.txt");
    std::string line;
    while (std::getline(file, line))
    {        
        char action = line[0];
        int value = std::stoi(line.substr(1));

        if (action == 'N' ) { waypoint.x += value; }
        else if (action == 'S' ) { waypoint.x -= value; }
        else if (action == 'E' ) { waypoint.y += value; }
        else if (action == 'W' ) { waypoint.y -= value; }
        else if (action == 'L' || action == 'R') { waypoint = move_waypoint(value, action, waypoint); }
        else if (action == 'F') 
        {
            ship_loc.x += waypoint.x * value;
            ship_loc.y += waypoint.y * value;
        }
    }

    int distance = abs(ship_loc.x) + abs(ship_loc.y);
    std::cout << "Manhatten distance: " << distance << std::endl;

    return 0;
}