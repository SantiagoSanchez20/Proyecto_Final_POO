#include "Trampa.h"
#include "Player.h" // Necesario para poder llamar a 'recibirDano' del jugador
#include <iostream>
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
// --- Constructor ---
// Inicializa la trampa con un nombre (ej: "Dardos") y el daño que causará (ej: 15).
Trampa::Trampa(std::string n, int d) : nombre(n), dano(d) {}

// --- Lógica de Activación ---
// Esta función es llamada por SalaC1 cuando el jugador intenta avanzar sin resolver el puzzle.
void Trampa::activar(Player* jugador) {
    std::cout << "\n*** CUIDADO ***" << std::endl;
    std::cout << "¡La trampa '" << nombre << "' se ha activado!" << std::endl;

    // Aplicamos el daño directo al HP del jugador.
    // La función 'recibirDano' del Player ya se encarga de restar la vida y comprobar si muere.
    jugador->recibirDano(dano);

    // Informamos al jugador de lo que acaba de pasar.
    std::cout << "Recibes " << dano << " puntos de dano." << std::endl;
    std::cout << "Tu HP actual: " << jugador->getHp() << std::endl;
}