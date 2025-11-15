//
// Created by ssanc on 15/11/2025.
//

#ifndef CLASE18POO_PLAYER_H
#define CLASE18POO_PLAYER_H
#include "Personaje.h"
#include "Inventario.h"
#include "Item.h"
#include <iostream>


//Declaramos clases adelantadas para que decirle al copilador que estas clases existen en el trabajo
class Enemigo;
class Arma;

class Player : public Personaje {

private:
    // --- Atributos Privados ---
    Arma* armaEquipada; // Puntero al arma. 'nullptr' significa desarmado.

    // Guardamos el HP máximo para la lógica de curación
    const int hpMax;

    public:
    int  ataqueBase;
    Inventario Inventario; //Inventario

//Contructor

    Player();

    //Metodos de interaccion del sistema

    void atacar(Enemigo* objetivo);

    //Funcion para que que cuando el player quiera usar algun item de inventario.

    void usarItem(Item* item);

    //Funcion cuando se quiera mover entre salas
    void mover();

    //---Gestion de armas---

    void equiparArma(Arma* nuevaArma);

    Arma* getArmaEquipada() const;

    //---Gestion de curas cuando se usa una pocion

    void curar(int cantidad);

    //Creamos un virtual para que pueda usar y cambiar valores de recibirDano

    virtual void recibirDano(int cantidad) override;

};


#endif //CLASE18POO_PLAYER_H