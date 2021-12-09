#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

int find_nr(const std::string &row_str, int max_rows)
{
    int max = max_rows, min = 0;
    for(auto letter: row_str)
    {        
        if (letter == 'F' || letter == 'L') { max = max - ((max -min)/2) - 1; }
        else if (letter == 'B' || letter == 'R') { min = min + ((max -min)/2) + 1; }
    }
    return min;
}

int get_seat(const std::string &input_line)
{
    int row = find_nr(input_line.substr(0,7), 127);
    int col = find_nr(input_line.substr(7,9), 7);
    return row * 8 + col;
}

int find_own_seat(const std::vector<int> &seats)
{
    for (int i=1; i <= seats.size(); i++)
    {
        if (seats[i] + 1 != seats[i+1]) { return seats[i] + 1;}
    }
    return -1;
}

int main()
{
    std::vector<int> seats = {-1};
    std::ifstream file("input_test.txt");
    std::string line;
    while (std::getline(file, line))
    {
        int seat = get_seat(line);
        seats.push_back(seat);
    }
    std::sort(seats.begin(), seats.end());
    seats.push_back(-1);

    int own_seat = find_own_seat(seats);
    std::cout << "own seat: " <<  own_seat << std::endl;
}