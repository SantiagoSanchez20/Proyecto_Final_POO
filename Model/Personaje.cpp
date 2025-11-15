#include "Personaje.h"
#include <iostream>


//Creamos el constructor

Personaje::Personaje(std::string &nombre, int vida) : nombre(nombre), vida(vida) {
}


//Creamos el booleando
bool Personaje::estaVivo() const {
    return this->vida  > 0 ;
}

std::string Personaje::getNombre() const {
    return this->nombre;

}

int Personaje::getVida() const {
    return this->vida;
}