cmake_minimum_required(VERSION 3.5)
project(lib-manager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(header)
include_directories(external)


add_executable(lib-manager
    ./src/main.cpp
    ./src/menu.cpp
    ./src/book.cpp
    ./src/library.cpp
    ./header/book.hpp
    ./header/menu.hpp
    ./header/library.hpp
    ./external/sqlite3.c
    
)
