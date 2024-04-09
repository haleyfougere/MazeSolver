#ifndef ASSIGNMENT_2_MAZE_SOLVER_H
#define ASSIGNMENT_2_MAZE_SOLVER_H
#include <vector>
#include <fstream>
#include <filesystem>
#include "stack.h"
#include "position.h"

class MazeSolver {
    static const int MAX_ROWS = 51;
    static const int MAX_COLS = 52;
    std::fstream _unsolved_file;
    std::fstream _solved_file;
    char _maze[MAX_ROWS][MAX_COLS];

public:
    bool file_io(const std::filesystem::path& file_path_unsolved,
                 const std::filesystem::path& file_path_solved);
    void solve_maze();
    void run(const char* unsolved_filename, const char* solved_filename);
    void find_path(Stack& path_stack, Position& current, bool& moved);
    void mark_path(Stack& path_stack);
    void save_maze();
    void print_maze();
};

#endif
