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
        Model/SalaInicio.cpp
        Model/SalaInicio.h
        Model/Salab1.cpp
        Model/Salab1.h
        Model/SalaB2.cpp
        Model/SalaB2.h
        Model/SalaC1.cpp
        Model/SalaC1.h
        Model/SalaC2.cpp
        Model/SalaC2.h
        Model/SalaFinal.cpp
        Model/SalaFinal.h
        Controller/GameManager.cpp
        Controller/GameManager.h
        Model/Sala.cpp
        Model/Sala.h
)
