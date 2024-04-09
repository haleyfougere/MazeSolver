cmake_minimum_required(VERSION 3.17)
project(Assignment_2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-static")

add_executable(solve_maze
        src/main.cpp
        src/maze_solver.cpp
        src/stack.cpp
        src/position.cpp)
