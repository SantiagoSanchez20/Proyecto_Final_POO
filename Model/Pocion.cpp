
#include "Pocion.h"

#include <iostream>
#include <ostream>

#include "Item.h"
#include "Player.h"


//Inicializamos el constructor.

Pocion::Pocion(std::string nombrePocion,
    std::string descripPocion,
    int cura) : Item(nombrePocion,
        descripPocion),
hpCurado(20){
    std::cout << "Pocion cread(Constructor)" << std::endl;
}
//--------Void de usar de la pocion---------


void::Pocion::usar(Player* jugador)// Se llama la clase de player para que se aplique la funcion de la pocion
{
    std::cout << "Se ha usado la pocion"<< this->nombre << " .";
    std::cout << " Recuperas: " << this->hpCurado <<" HP." <<std::endl;


    //Falta implementacion de la funcion curar en Player.cpp
    //jugador->curar(this->hpCurado);
}