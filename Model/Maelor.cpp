#include "Maelor.h"
#include <iostream>
#include "Player.h"
#include "Pocion.h"

Maelor::Maelor()
    :NPC("Maelor", "Saludos extraño...."
                   "si estas aqui es por que andas en busca de la fruta Aureus, pero todos conoces su verdadero "
                   "efecto..... podria matarte o incluso darte vida eterna."){

}
Maelor::~Maelor() {
    // Definición vacía es suficiente
}

void Maelor::interactuar(Player *jugador) {
    std::cout <<"[Maelor] " << this->dialogo << std::endl;

    this->darConsejo();
    this->iniciarAdivinanza(jugador);
}
void Maelor::darConsejo() {
    std::cout << "[Maelor] Consejo: Escucha, forastero. Los guardianes pesados son lentos y predecibles, pero resistentes.Usa tu agilidad para evadirlos y atacar cuando estén vulnerables."<< std::endl;
}

void Maelor::iniciarAdivinanza(Player* jugador) {
    std::cout <<"[Maelor] En esta mazmorra es peligrosa te hara falta tener pociones de vida, si me respondes a mi adivinanza, te dare algo para el camino"<<std::endl;
    std::cout <<"[Maelor] Adivinanza: Sube y baja sin moverse?"<< std::endl;

    // Nota: Aquí se necesita implementación de lectura de input para la adivinanza.
    bool respuestaCorrecta = true; // Hardcodeado por ahora

    if (respuestaCorrecta){
        std::cout << "[Maelor]   'Escalera electrica'..... Correcto!!!."<<std::endl;
        this->darPocion(jugador);
    } else {
        std::cout <<"[Maelor] No...... Extrano. Vuelve a intentarlo, te has equivocado!!"<< std::endl;
    }
}
void Maelor::darPocion(Player* jugador) {
    std::cout <<"[Maelor] Tu respuesta es recompensada. Toma esta pocion de vida." << std::endl;

    Pocion* pocionCurativa = new Pocion("Pocion de Maelor","Una pocion que cura 15 HP",15);
    bool exito = jugador->inventario->agregarItem(pocionCurativa);

    if (exito) {
        std::cout <<"[Juego] Has recibido [Pocion de Maelor] en tu inventario." << std::endl;
    } else {
        std::cout << "[Juego] Tu inventario esta lleno." << std::endl;
        delete pocionCurativa;
    }
}