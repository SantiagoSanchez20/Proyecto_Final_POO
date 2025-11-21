#include "Maelor.h"
#include <iostream>
#include <limits> // Para limpiar el buffer
#include "Player.h"
#include "Pocion.h"


/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
Maelor::Maelor()
    :NPC("Maelor", "Saludos extraño... si estas aqui es por que andas en busca de la fruta Aureus."){
}

Maelor::~Maelor() {}

void Maelor::interactuar(Player *jugador) {
    std::cout << "[Maelor] " << this->dialogo << std::endl;
    this->darConsejo();
    // No llamamos a iniciarAdivinanza aquí directamente porque SalaB1 controla cuándo pasa eso.
}

void Maelor::darConsejo() {
    std::cout << "[Maelor] Consejo: Los guardianes pesados son lentos. Usa tu agilidad."<< std::endl;
}

// AHORA DEVUELVE BOOL Y PIDE INPUT
bool Maelor::iniciarAdivinanza(Player* jugador) {
    std::cout << "\n[Maelor] Adivinanza: Sube y baja sin moverse?" << std::endl;
    std::cout << "1. Una pluma" << std::endl;
    std::cout << "2. Una escalera" << std::endl; // Respuesta correcta (Escalera eléctrica/normal)
    std::cout << "3. El viento" << std::endl;
    std::cout << "> Elige una opcion (1-3): ";

    int opcion;
    std::cin >> opcion;

    // Limpieza básica del buffer para evitar errores si meten letras
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (opcion == 2) {
        std::cout << "[Maelor] 'Una escalera'... Correcto!!!" << std::endl;
        this->darPocion(jugador);
        return true; // ¡Ganó!
    } else {
        std::cout << "[Maelor] No... Incorrecto. Medita y vuelve a intentarlo." << std::endl;
        return false; // Falló
    }
}

void Maelor::darPocion(Player* jugador) {
    std::cout << "[Maelor] Toma esta pocion de vida." << std::endl;
    Pocion* pocionCurativa = new Pocion("Pocion de Maelor","Una pocion que cura 15 HP",15);

    if (jugador->inventario->agregarItem(pocionCurativa)) {
        std::cout << "[Juego] Has recibido [Pocion de Maelor]." << std::endl;
    } else {
        std::cout << "[Juego] Tu inventario esta lleno. La pocion se pierde." << std::endl;
        delete pocionCurativa;
    }
}