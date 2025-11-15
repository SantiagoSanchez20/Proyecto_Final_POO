//
// Created by ssanc on 15/11/2025.
//

#include "Player.h"
#include "Enemigo.h"
#include "Arma.h"
#include "Item.h"

Player::Player()
: Personaje("Jugador",100),
ataqueBase(8),
hpMax(100),
armaEquipada(nullptr){

}

//Implementacion de la Herencia recibiDano

void Player::recibirDano(int cantidad) {

    this->vida -=cantidad;

    if (this->vida < 0) {
        this->vida = 0; //Colocamos esto para evitar que haya vida negativa
    }
    std::cout << "[Jugador]"<< this->nombre << " recibe "<< cantidad <<
        "de daño. vida restante: " << this->vida << std::endl;

    if (!this->estaVivo()) {
        std::cout << "[Jugador]"<< this->nombre << " ha sido derrotado."<<std::endl;

    }

}

//Metodos de interaccion

void Player::atacar(Enemigo* objetivo) {
    if (!this->estaVivo()) {
        std::cout << "[Jugador] No puedes atacar, estas muerto." << std::endl;
        return;
    }
    if (!objetivo->estaVivo()) {
        std::cout << "[Jugador] El objetivo " << objetivo->getNombre() << " ya esta derrotado." << std::endl;
        return;
    }

    int danoTotal = this->ataqueBase;
    std::string nombreArma = "sus punos";

    // 'armaEquipada->danioAdicional' funcionará
    // gracias al #include "Arma.h".
    if (this->armaEquipada != nullptr) {
        danoTotal += this->armaEquipada->danioAdicional;
        nombreArma = "su " + this->armaEquipada->getNombre(); // Asumiendo que Arma hereda getNombre de Item
    }

    std::cout << "[Jugador] " << this->nombre << " ataca a " << objetivo->getNombre()
        << " con " << nombreArma << " e inflige " << danoTotal << " de dano." << std::endl;

    objetivo->recibirDano(danoTotal);
}

//Implementamos el mover al player.
void Player::mover() {
    std::cout << "[jugador]" << this->nombre << " se mueve..." << std::endl;
}

void Player::equiparArma(Arma* nuevaArma) {
    this->armaEquipada = nuevaArma;
    if (nuevaArma != nullptr) {
        std::cout << "[Jugador] " << this->nombre << " ha equipado "
            << nuevaArma->getNombre() << "." << std::endl;
    } else {
        std::cout << "[Jugador] " << this->nombre << "Ha desequipado su arma" << std::endl;
    }
}
Arma* Player::getArmaEquipada() const {
    return this->armaEquipada;
}

void Player::curar(int cantidad) {
    this->vida += cantidad;
    if (this-> vida > this->hpMax) {
        this->vida = this->hpMax;

    }
    std::cout << "[Jugador] " << this->nombre << " se cura " << cantidad
        << " de vida. Vida actual: " << this->vida << std::endl;
}







