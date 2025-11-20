//
// Created by ssanc on 16/11/2025.
//

#include "GuardianDeLumen.h"
#include "Player.h"

GuardianDeLumen::GuardianDeLumen() : Enemigo("Guardian de Lumen", 50 , 12, 10),
fase(1), hpMax(100)  {
    std::cout << " El "<<this->nombre << "Ha aparecido..... Derrotalo! " << std::endl;
}

void GuardianDeLumen::cambiarFase() {
    if (!this->estaVivo()) {
        return;
    }

        float hpPorcent = (float)this->hp / this->hpMax;


    //Fase 3  Ataques  HP(HP( 1% a 39%) Ataques mas fuertes,mas daño
    if (hpPorcent <= 0.39f && this->fase < 3 ) {
        this->fase = 3;
        this->ataque  += 3;
        std::cout << "El " << this->nombre << "ruge de furia y entra en.... ¡Fase 3!"<< std::endl;
    }

    //Fase 2   HP(HP( 40% a 74%) habilidades especiales

    if (hpPorcent <= 0.74f && this->fase < 2 ) {
        this->fase = 2;
        this->ataque  += 2;
        std::cout << "El " << this->nombre << "Concentra energia... ¡Fase 2!"<< std::endl;

    }
    //Fase 1     HP( 75 % a 100%) golpes normales, por lo tanto no se implementa por que ya viene
    //por defecto

}

void GuardianDeLumen::recibirDano(int cantidad) {
    this-> hp -= cantidad;
    if (this->hp < 0 ) {
        this->hp = 0;
    }
    std::cout << "El " << this->nombre << " recibe " << cantidad << "de dano" <<
        "vida restante:" << this-> hp << "/" << this->hpMax << std::endl;

    //Comprobamos el cambio de fase

    this-> cambiarFase();

    //Comprobar si el jefe ha muerto

    if (this->estaVivo()) {
        std::cout << "El " << this->nombre << " ha sido derrotado." << std::endl;
        //Aqui deberia soltar ya la recompensa
    }

}

void GuardianDeLumen::atacar(Player *objetivo) {
    // Comprueba si puede atacar
    if (!this->estaVivo()) {
        return;
    }

    switch (this->fase) {
        case 1:
            this->ataqueSimple(objetivo);
            break;
        case 2:
            this->ataqueEspecial(objetivo);
            break;
        case 3:
            this->ataqueFuerte(objetivo);
            break;
        default:
            this->ataqueSimple(objetivo);
            break;
    }
}

void GuardianDeLumen::ataqueSimple(Player* objetivo) {
    // Ataque simple pero regular (daño base)
    std::cout << "El " << this->nombre << " (Fase 1) lanza un golpe simple." << std::endl;
    objetivo->recibirDano(this->ataque);
}
void GuardianDeLumen::ataqueEspecial(Player* objetivo) {
    // Daño mayor (ej. 1.5x del ataque base)


    int danoEspecial = static_cast<int>(this->ataque * 1.15); // static_cast<int> es para forzar la conversion de un tipo de dato a otro
    std::cout << "El " << this->nombre << " (Fase 2) usa daño en area!" << std::endl; //Cambiar a que tipo de daño usara
    objetivo->recibirDano(danoEspecial);
}

void GuardianDeLumen::ataqueFuerte(Player* objetivo) {
    int danoFuerte = static_cast<int>(this->ataque * 1.2);
    std::cout << " El " << this->nombre << "(Fase 3) usa golpe fuerte!!!"<<std::endl;
    objetivo->recibirDano(danoFuerte);
}


