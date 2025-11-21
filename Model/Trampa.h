#ifndef TRAMPA_H
#define TRAMPA_H
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
#pragma once
#include <string>

// Forward Declaration: Le decimos al compilador que existe una clase llamada Player.
// Esto es necesario porque la función 'activar' recibe un puntero a Player.
class Player;

// Clase Trampa: Representa un peligro ambiental (como dardos, pinchos, gas).
// Se usa principalmente en la Sala C1 para castigar al jugador si no resuelve el puzzle.
class Trampa {
public:
    // Nombre descriptivo de la trampa (ej: "Dardos Ocultos")
    std::string nombre;

    // Cantidad de vida (HP) que le quitará al jugador al activarse
    int dano;

    // Constructor: Inicializa el nombre y el daño.
    Trampa(std::string n, int d);

    // Función principal:
    // Se llama cuando el jugador falla un puzzle o toma una mala decisión.
    // Aplica el daño al jugador y muestra un mensaje en consola.
    void activar(Player* jugador);
};

#endif