#include <iostream>
#include "maze_solver.h"

using namespace std;

int main(int argc, char** argv) {
    //expecting 3 arguments, the program name and the input file and the output file
    if (argc != 3) {
        std::cout << "Error, incorrect number of arguments." << std::endl;
        return 1;
    }

    MazeSolver maze_solver;
    maze_solver.run(argv[1], argv[2]);

    return 0;
}