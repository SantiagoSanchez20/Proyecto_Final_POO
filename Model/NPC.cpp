#include "NPC.h"
#include <iostream>

/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */

//Constructor
NPC::NPC(const std::string& nombre,const std::string& dialogoInicial): Personaje(nombre,9999),
dialogo(dialogoInicial) {

}

//Implementacion de la funcion con la herencia

void NPC::recibirDano(int cantidad) {
    std::cout << "El " << this->nombre <<
        "te observa en forma extraña. No puedes atacarle." << std::endl;
}
