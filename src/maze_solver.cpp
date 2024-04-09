#include <iostream>
#include <filesystem>
#include "maze_solver.h"
#include "stack.h"
#include "position.h"

void MazeSolver::run(const char *unsolved_filename, const char *solved_filename) {
    /// run the program
    /// \param unsolved_filename the file name of the unsolved maze
    /// \param solved_filename the file name of the solved maze

    std::filesystem::path unsolved_path = unsolved_filename;
    std::filesystem::path solved_path = solved_filename;

    bool file_opened = file_io(unsolved_path, solved_path);
    if (file_opened) {
        std::cout << "File Opened Successfully" << std::endl;
    } else {
        return;
    }
    solve_maze();
    print_maze();
    save_maze();
}

bool MazeSolver::file_io(const std::filesystem::path& file_path_unsolved,
                         const std::filesystem::path& file_path_solved) {
    ///opens the file and puts the contents into an array
    /// \param unsolved_filename the file name of the unsolved maze
    /// \param solved_filename the file name of the solved maze

    if (!std::filesystem::exists(file_path_unsolved)) {
        std::cout << "Error: File '" << file_path_unsolved
        << "' does not exist." << std::endl;
        return false;
    } else {
        _unsolved_file.open(file_path_unsolved);
    }

    if (!_unsolved_file.is_open()) {
        std::cerr << "Error: Unable to open file '"
        << file_path_unsolved << "'" << std::endl;
        return false;
    }

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            _unsolved_file.get(_maze[i][j]);
        }
    }

    _solved_file.open(file_path_solved, std::ios::out);

    return true;
}

void MazeSolver::solve_maze() {
    ///solve the maze

    Stack path_stack;
    Position start_position = {1, 0};
    Position end_position = {49, 50};
    path_stack.push(start_position);

    while (!path_stack.empty()) {
        Position current = path_stack.top();
        bool moved = false;

        if (current == end_position) {
            mark_path(path_stack);
            break;
        }
        find_path(path_stack, current, moved);
    }
}

void MazeSolver::mark_path(Stack &path_stack) {
    /// mark the correct path of the maze and unmark the wrong path

    while (!path_stack.empty()) {
        Position pos = path_stack.top();
        // Mark as part of the solution path and pop the position from the stack to
        // move to the next position
        _maze[pos._row][pos._col] = '#';
        path_stack.pop();

        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                if (_maze[i][j] == 'X') {
                    _maze[i][j] = ' ';
                }
            }
        }
    }
}

void MazeSolver::save_maze() {
    /// save the solved maze to the solution file

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            _solved_file << _maze[i][j];
        }
    }
}

void MazeSolver::print_maze() {
    /// print out the maze

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            std::cout << _maze[i][j];
        }
    }
}

void MazeSolver::find_path(Stack &path_stack, Position &current, bool &moved) {
    /// find the path of the maze
    /// \param path_stack the stack with the path
    /// \param current the current position
    /// \param moved if the position has been moved

    // array of directions to check surrounding positions
    // (up, down, left, right)
    const Position directions[] = {{-1, 0},
                                   {1,  0},
                                   {0,  -1},
                                   {0,  1}};


    for (const auto &dir: directions) {
        int next_row = current._row + dir._row;
        int next_col = current._col + dir._col;

        // Check if the next move is valid (an empty space to move into)
        if (next_row >= 0 && next_row < MAX_ROWS && next_col >= 0 &&
            next_col < MAX_COLS && _maze[next_row][next_col] == ' ') {
            path_stack.push({next_row, next_col});
            // Mark the move as 'X' to indicate it has been visited
            _maze[next_row][next_col] = 'X';
            moved = true;
            break;
        }
    }

    // If no valid moves were found (dead end), pop the current position from the stack
    if (!moved) {
        path_stack.pop();
    }
}