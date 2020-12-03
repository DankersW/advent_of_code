#include <iostream>
#include <vector>
#include <string>
#include <fstream>


std::vector<bool> populate_row(const std::string &str_row)
{
    std::vector<bool> row;
    for (char const row_value: str_row) {
        if (row_value == '.') { row.push_back(false); }
        else if (row_value == '#') { row.push_back(true); }
    }
    return row;
}

int count_trees_on_path(std::vector<std::vector<bool>> matrix_path, int right_steps, int down_steps)
{
    int tree_counter = 0, current_row = 0, current_col = 0;
    while (current_row < matrix_path.size()-1)
    {
        for (int i = 0; i < right_steps; i++)
        {
            current_col++;
            if (current_col > matrix_path[0].size()-1) { current_col = 0; }
        }
        for (int i = 0; i < down_steps; i++)
        {
            if (current_row != matrix_path.size()-1) { current_row++; }
        }

        if (matrix_path[current_row][current_col]) { tree_counter++; }
    }
    return tree_counter;
}

int main()
{
    std::vector< std::vector<bool> > matrix;
    std::ifstream file("input.txt");
    std::string line;
    while (std::getline(file, line))
    {
        std::vector<bool> row = populate_row(line);
        matrix.push_back(row);
    }

    std::vector<int> tree_counters;
    tree_counters.push_back(count_trees_on_path(matrix, 1, 1));
    tree_counters.push_back(count_trees_on_path(matrix, 3, 1));
    tree_counters.push_back(count_trees_on_path(matrix, 5, 1));
    tree_counters.push_back(count_trees_on_path(matrix, 7, 1));
    tree_counters.push_back(count_trees_on_path(matrix, 1, 2));

    long total_trees = 1;
    for (auto tree_counter: tree_counters)
    {
        total_trees *= tree_counter;
    }
    
    std::cout << "Total trees: " << total_trees << std::endl;

    return 0;
}