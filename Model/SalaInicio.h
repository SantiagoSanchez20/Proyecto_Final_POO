#ifndef CLASE18POO_SALAINICIO_H
#define CLASE18POO_SALAINICIO_H
#pragma once
#include "Sala.h"
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
class SalaInicio : public Sala {
public:
    SalaInicio();


    //Agregamos el override para controlar las opciones manualmente
    virtual void manejarTurno(GameManager* game, Player* jugador) override;
};
#endif
