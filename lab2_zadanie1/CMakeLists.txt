cmake_minimum_required(VERSION 3.10.0)
project(proi-lab2 VERSION 0.1.0 LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Tworzenie pliku wykonywalnego
add_executable(proi-lab2 main.cpp vec_n.cpp)
