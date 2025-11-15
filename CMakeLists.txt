cmake_minimum_required(VERSION 4.0)
project(Clase18POO)

set(CMAKE_CXX_STANDARD 20)

add_executable(Clase18POO main.cpp
        Model/Personaje.cpp
        Model/Personaje.h
        View/Consola.cpp
        View/Consola.h
        Model/Arma.cpp
        Model/Arma.h
        Model/EspadaBruma.cpp
        Model/EspadaBruma.h
        Model/DagaVelo.cpp
        Model/DagaVelo.h
        Model/Inventario.cpp
        Model/Inventario.h
        Model/Item.cpp
        Model/Item.h
        Model/Pocion.cpp
        Model/Pocion.h
        Model/Player.cpp
        Model/Player.h
        Model/Enemigo.cpp
        Model/Enemigo.h
)
