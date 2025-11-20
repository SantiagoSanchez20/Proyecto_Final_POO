
#include "Pocion.h"

#include <iostream>
#include <ostream>


#include "Player.h"


// --- Constructor ---
Pocion::Pocion(const std::string& nombre, const std::string& descripcion, int hpCurado)
    // 1. Llama al constructor de Item
    : Item(nombre, descripcion),
    // 2. Inicializa sus propios atributos
      hpCurado(hpCurado)
{
    // Constructor
}
//--------Void de usar de la pocion---------


void::Pocion::usar(Player* jugador)// Se llama la clase de player para que se aplique la funcion de la pocion
{
    std::cout << "Bebes la " << this->nombre << "." << std::endl;
    jugador->curar(this->hpCurado);
}