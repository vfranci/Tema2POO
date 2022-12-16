cmake_minimum_required(VERSION 3.23)
project(Tema2OOP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Tema2OOP
        Entertainment.cpp
        Entertainment.h
        main.cpp
        Menu.cpp
        Menu.h
        Movie.cpp
        Movie.h
        OutOfBoundsException.cpp
        OutOfBoundsException.h
        InvalidInputException.cpp
        InvalidInputException.h
        Series.cpp
        Series.h)
