#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>


bool valid_year(const std::string &passport, const char field[4], int min, int max)
{
    if (passport.find(field) == std::string::npos) { return false; }
    auto year = std::stoi(passport.substr(passport.find(field)+ 4, 4));
    if (min <= year && year <= max) { return true;}
    return false;
}

bool valid_height(const std::string &passport)
{
    auto pos_key = passport.find("hgt:");
    if (pos_key == std::string::npos) { return false; }
    
    auto pos_space = passport.find(" ", pos_key);
    auto f_height = passport.substr(pos_key + 4, pos_space-pos_key-4);
    if (f_height.back() == 'm')
    {
        auto height = std::stoi(f_height.substr(0, f_height.size()-2));
        if (150 <= height && height <= 193) { return true; }
    }
    else if (f_height.back() == 'n')
    {
        auto height = std::stoi(f_height.substr(0, f_height.size()-2)); 
        if (59 <= height && height <= 76) { return true; }
    }
    return false;
}

bool valid_hair_color(const std::string &passport)
{
    auto pos_key = passport.find("hcl:");
    if (pos_key == std::string::npos) { return false; }

    auto pos_space = passport.find(" ", pos_key);
    auto hair = passport.substr(pos_key + 4, pos_space-pos_key-4);
    if (hair.length() != 7 ||  hair[0] != '#') { return false;}

    hair.erase(0, 1);
    for (auto item: hair)
    {
        if (!(isxdigit(item) or isdigit(item))) { return false; }
    }
    return true;
}

bool valid_eye_color(const std::string &passport)
{
    auto pos_key = passport.find("ecl:");
    if (pos_key == std::string::npos) { return false; }

    auto pos_space = passport.find(" ", pos_key);
    auto color = passport.substr(pos_key + 4, pos_space-pos_key-4);
    std::vector<std::string> accepted_colors = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

    if (std::find(accepted_colors.begin(), accepted_colors.end(), color) != accepted_colors.end()) { return true;}
    return false;
}

bool valid_passport_id(const std::string &passport)
{
    auto pos_pid = passport.find("pid:");
    if (pos_pid == std::string::npos) { return false; }

    auto pos_space = passport.find(" ", pos_pid);
    auto pid = passport.substr(pos_pid + 4, pos_space-pos_pid-4);

    if (pid.length() == 9) { return true;}
    return false;
}

bool valid_passport(const std::string &passport)
{
    bool valid_byr = valid_year(passport, "byr:", 1920, 2002);
    bool valid_iyr = valid_year(passport, "iyr:", 2010, 2020);
    bool valid_eyr = valid_year(passport, "eyr:", 2020, 2030);
    bool valid_hgt = valid_height(passport);
    bool valid_hcl = valid_hair_color(passport);
    bool valid_ecl = valid_eye_color(passport);
    bool valid_pid = valid_passport_id(passport);
    if (valid_byr && valid_iyr && valid_eyr && valid_hgt && valid_hcl && valid_ecl && valid_pid) { return true; }
    return false;
}

int main()
{
    std::ifstream file("input_part2.txt");
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
    if (valid_passport(passport)) { valid_passport_counter++; }
    
    std::cout << "Valid passwords counted: " << valid_passport_counter << std::endl;
    return 0;
}