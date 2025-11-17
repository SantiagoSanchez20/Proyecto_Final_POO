//
// Created by ssanc on 17/11/2025.
//

#ifndef CLASE18POO_NPC_H
#define CLASE18POO_NPC_H
#include <string>
#include "Personaje.h"


//Declaracion adelante para que compilador y la clase entienda que en el proyecto existe una clase Player
class Player;
class NPC : public Personaje {
protected:
    std::string dialogo;
public:
    NPC(const std::string& nombre,const std::string& dialogoInicial);

    //Implementacion de herencia

    /*Se implementa la funcion recibirDano de personaje
     *Ya que los NPcs del juego son invulnerables
     */
    virtual void recibirDano(int cantidad) override;

    /*Implementacion de virtual pura para la interaccion
     * por la cual obligar a las clases derivadas de esta a implementar
     * basicamente es decir cuando el jugador interactura con ellos.
     */
    virtual void interactuar(Player* jugador)  = 0 ;
};


#endif //CLASE18POO_NPC_H