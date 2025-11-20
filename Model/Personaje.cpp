#include "Personaje.h"
#include <iostream>


//Creamos el constructor

Personaje::Personaje(const std::string& nombre, int hp)
    : nombre(nombre), hp(hp)
{

}


//Creamos el booleando
bool Personaje::estaVivo() const {
    return this->hp  > 0 ;
}

std::string Personaje::getNombre() const {
    return this->nombre;

}

int Personaje::getHP() const {
    return this->hp;
}