//
// Created by ssanc on 15/11/2025.
//

#ifndef CLASE18POO_PLAYER_H
#define CLASE18POO_PLAYER_H
#include "Personaje.h"
#include "Inventario.h"
#include "Item.h"
#include "Buff.h"
#include <iostream>
#include <vector>


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

    //Vector para guardar los buff activos
    std::vector<Buff> buffsActivos;

    //Contructor

    Player();

    //Añadims un metodo agregarBuff cuando se encuentre con la alma iria
    void agregarBuff(const Buff& buff);

    //Actualiza la Duracion de todos los buffs, hay que llamarlo por el gamemanager al final de cada turno.
    void actualizarBuff();

    //Calcula el daño totla, sumando ataque base + buff
    int getDanoAtaqueTotal() const;

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