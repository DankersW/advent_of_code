#include <iostream>
#include <vector>
#include <fstream>
#include <string>


bool valid_year(const std::string &passport, const char field[4], int min, int max)
{
    auto year = std::stoi(passport.substr(passport.find(field)+ 4, 4));
    if (min <= year && year <= max) { return true;}
    return false;
}

bool valid_height(const std::string &passport)
{
    return true;
}

bool valid_hair_color(const std::string &passport)
{
    return true;
}

bool valid_eye_color(const std::string &passport)
{
    return true;
}

bool valid_passport_id(const std::string &passport)
{
    return true;
}

bool valid_passport(const std::string &passport)
{
    std::cout << passport << std::endl;
    bool byr = passport.find("byr:") != std::string::npos;
    bool iyr = passport.find("iyr:") != std::string::npos;
    bool eyr = passport.find("eyr:") != std::string::npos;
    bool hgt = passport.find("hgt:") != std::string::npos;
    bool hcl = passport.find("hcl:") != std::string::npos;
    bool ecl = passport.find("ecl:") != std::string::npos;
    bool pid = passport.find("pid:") != std::string::npos;
    if (!(byr && iyr && eyr && hgt && hcl && ecl && pid)) { return false; }

    bool valid_byr = valid_year(passport, "byr:", 1920, 2002);
    bool valid_iyr = valid_year(passport, "iyr:", 2010, 2020);
    bool valid_eyr = valid_year(passport, "eyr:", 2020, 2030);
    bool valid_hgt = valid_height(passport); // todo
    bool valid_hcl = valid_hair_color(passport);
    bool valid_ecl = valid_eye_color(passport);
    bool valid_pid = valid_passport_id(passport);
    if (valid_byr && valid_iyr && valid_eyr && valid_hgt && valid_hcl && valid_ecl && valid_pid) { return true; }

    return false;
}

int main()
{
    std::ifstream file("input_example.txt");
    std::string line;
    std::string passport = "";
    int valid_passport_counter = 0;
    while (std::getline(file, line))
    {
        if (line.compare("") != 0) { passport += line + " "; }
        else
        {
            if (valid_passport(passport)) { valid_passport_counter++; }
            passport = "";
        }
    }
    std::cout << std::endl << "Valid passwords counted: " << valid_passport_counter << std::endl;
    return 0;
}