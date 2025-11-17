//
// Created by ssanc on 16/11/2025.
//

#ifndef CLASE18POO_GUARDIANDELUMEN_H
#define CLASE18POO_GUARDIANDELUMEN_H
#include "Enemigo.h"


class GuardianDeLumen : public Enemigo{

private:
    int fase;
    int hpMax;

//Creamos clases privadas para que no haya ningun problema al momento de confusion al hacer
//llamado de las funciones de las fases, dependiendo la vida que tiene el jefe
    void cambiarFase();

    void ataqueSimple(Player* objetivo); //Fase 1     HP( 75 % a 100%) golpes normales
    void ataqueEspecial(Player* objetivo); //Fase 2   HP(HP( 40% a 74%) habilidades especiales
    void ataqueFuerte(Player* objetivo); //Fase 3  Ataques  HP(HP( 1% a 39%) Ataques mas fuertes, es decir mas daño

    public:
    //Constructor
    GuardianDeLumen();
    //Destructor
    ~GuardianDeLumen();

    //Implementacion de Virtua y override por la heredacion de la clase enemigo

    virtual void atacar(Player* objetivo) override;


    virtual void recibirDano(int cantidad) override;




};


#endif //CLASE18POO_GUARDIANDELUMEN_H