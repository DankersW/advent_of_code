#include <iostream>
#include <string>
#include <fstream>

int get_row_nr(const std::string &row_str, int max_rows)
{
    std::cout << row_str << std::endl;
    return 0;
}

int main()
{
    std::ifstream file("input_example.txt");
    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;

        int row_nr = get_row_nr(line.substr(0,7), 127);

        std::cout << std::endl;
    }
}