#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream file("input_example.txt");
    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }
    return 0;
}