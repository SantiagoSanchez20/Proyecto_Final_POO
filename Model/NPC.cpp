//
// Created by ssanc on 17/11/2025.
//

#include "NPC.h"
#include <iostream>



//Constructor

NPC::NPC(const std::string& nombre,const std::string& dialogoInicial): Personaje(nombre,9999),
dialogo(dialogoInicial) {

}

//Implementacion de la funcion con la herencia

void NPC::recibirDano(int cantidad) {
    std::cout << "El " << this->nombre <<
        "te observa en forma extraña. No puedes atacarle." << std::endl;
}
