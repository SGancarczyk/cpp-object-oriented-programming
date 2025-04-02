cmake_minimum_required(VERSION 3.10.0)
project(proi-lab2 VERSION 0.1.0 LANGUAGES C CXX)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY   https://github.com/google/googletest.git
    GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

set(PROJECT_SOURCES vec_n.cpp vec_n.hpp)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(proi-lab2 main.cpp ${PROJECT_SOURCES})
add_executable(proi-lab2-unittests unittests.cpp ${PROJECT_SOURCES})
target_link_libraries(proi-lab2-unittests PUBLIC gtest_main)
