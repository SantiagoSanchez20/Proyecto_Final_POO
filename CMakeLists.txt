cmake_minimum_required(VERSION 4.0)
project(Clase18POO)

set(CMAKE_CXX_STANDARD 20)

add_executable(Clase18POO main.cpp
        Personaje.cpp
        Personaje.h
        Mago.cpp
        Mago.h
        Guerrero.cpp
        Guerrero.h)
