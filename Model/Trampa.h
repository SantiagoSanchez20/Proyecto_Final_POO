#ifndef TRAMPA_H
#define TRAMPA_H

#pragma once
#include <string>

class Player; // Le decimos que la clase Player existe

class Trampa {
public:
    std::string nombre;
    int dano;

    // Constructor
    Trampa(std::string n, int d);

    // Función para activar la trampa
    void activar(Player* jugador);
};

#endif