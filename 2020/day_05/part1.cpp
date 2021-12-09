#include <iostream>
#include <string>
#include <fstream>

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

int main()
{
    int max_seat = 0;
    std::ifstream file("input_test.txt");
    std::string line;
    while (std::getline(file, line))
    {
        int seat = get_seat(line);
        if (seat > max_seat) { max_seat = seat; }
    }
    std::cout << "max seat: " << max_seat << std::endl;
}