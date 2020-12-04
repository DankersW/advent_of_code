#include <iostream>
#include <vector>
#include <fstream>
#include <string>

bool valid_passport(const std::string &passport)
{
    bool byr = passport.find(" byr:") != std::string::npos;
    bool iyr = passport.find(" iyr:") != std::string::npos;
    bool eyr = passport.find(" eyr:") != std::string::npos;
    bool hgt = passport.find(" hgt:") != std::string::npos;
    bool hcl = passport.find(" hcl:") != std::string::npos;
    bool ecl = passport.find(" ecl:") != std::string::npos;
    bool pid = passport.find(" pid:") != std::string::npos;
    //bool cid = true;

    if (byr && iyr && eyr && hgt && hcl && ecl && pid) 
    { 
        return true; 
    }
    return false;
}

int main()
{
    std::ifstream file("input_example.txt");
    std::string line;
    std::string passport = " ";
    int valid_passport_counter = 0;
    while (std::getline(file, line))
    {
        if (line.compare("") != 0) 
        { 
            passport += line + " "; 
        }
        else
        {
            std::cout << passport << std::endl;
            if (valid_passport(passport)) 
            { 
                valid_passport_counter++; 
            }
            passport = " ";
        }
    }
    std::cout << "Valid passwords counted: " << valid_passport_counter << std::endl;
    return 0;
}