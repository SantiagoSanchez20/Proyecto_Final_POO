#ifndef CLASE18POO_SALAFINAL_H
#define CLASE18POO_SALAFINAL_H
#pragma once
#include "Sala.h"
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
// Clase SalaFinalE: Representa el "Salón Central" (Sala E).
// Es la última habitación del juego donde reside el Jefe Final y el objetivo (Aureus).
class SalaFinalE : public Sala {
public:
    // --- Variables de Estado (Flags) ---

    // Indica si el "Guardián de Lúmen" ha sido derrotado.
    // Si es false, el menú mostrará la opción de "Atacar".
    // Si es true, el menú cambiará para permitir recoger la recompensa.
    bool jefeVencido;

    // Indica si el jugador ya recogió el objeto "Aureus".
    // Cuando esto se vuelve true, se dispara el final del juego (Victoria).
    bool aureusRecogida;

    // Constructor: Inicializa la sala y pone los estados en false.
    SalaFinalE();

    // Función Override: Controla el flujo de la batalla final y la victoria.
    // También gestiona la lógica para que solo puedas regresar por donde viniste (B2 o C2).
    virtual void manejarTurno(GameManager* game, Player* jugador) override;
};
#endif //CLASE18POO_SALAFINAL_H