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
        Model/Player.cpp
        Model/Player.h
        Model/Inventario.cpp
        Model/Inventario.h
        Model/Item.cpp
        Model/Item.h
        Model/Pocion.cpp
        Model/Pocion.h
        Model/Maelor.cpp
        Model/Maelor.h
        salas/SalaInicio.cpp
        salas/SalaInicio.h
        salas/Salab1.cpp
        salas/Salab1.h
        salas/SalaB2.cpp
        salas/SalaB2.h
        salas/SalaC1.cpp
        salas/SalaC1.h
        salas/SalaC2.cpp
        salas/SalaC2.h
        salas/SalaFinal.cpp
        salas/SalaFinal.h
        salas/GameManager.cpp
        salas/GameManager.h
        salas/Sala.cpp
        salas/Sala.h
)
