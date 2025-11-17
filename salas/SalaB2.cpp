#include "SalaB2.h"
#include "GameManager.h"
#include "Player.h"
#include "Enemigo.h" // Para buscar al Guardia

SalaB2::SalaB2() : Sala(
    "B2",
    "Sala de arma misteriosa. Taller con yunques y herramientas. Una espada nueva está clavada en un bloque."
), jugadorYaObservo(false), espadaRecogida(false), guardiaVencido(false)
{
}

void SalaB2::manejarTurno(GameManager* game, Player* jugador) {

    std::vector<std::string> opciones;
    std::map<char, std::string> mapaSalidas;
    char opcionActual = 'a';

    // Opciones Específicas
    if (!guardiaVencido) {
        opciones.push_back("Observar la sala"); // A
        opciones.push_back("Sacar la espada");   // B
    } else if (!espadaRecogida) {
        // El guardia está vencido, ahora se puede tomar
        opciones.push_back("Tomar la Espada de Bruma"); // A
    }

    //Opciones Genéricas (Salidas)
    opcionActual = 'a' + opciones.size();

    opciones.push_back("Avanzar (a E)");
    mapaSalidas[opcionActual] = "E";
    opcionActual++;

    opciones.push_back("Devolverse de sala (a B1)");
    mapaSalidas[opcionActual] = "B1";
    opcionActual++;

    // Leer Input
    char eleccion = presentarOpcionesYLeerInput(opciones);

    // Procesar
    if (!guardiaVencido && eleccion == 'a') {
        std::cout << "Miras con atención. Notas un Guardia Pesado inmóvil en la penumbra." << std::endl;
        this->jugadorYaObservo = true;
    }
    else if (!guardiaVencido && eleccion == 'b') {
        // Lógica de emboscada
        Enemigo* guardia = game->findPersonaje<Enemigo*>("Guardia Pesado", this);
        if (!guardia) { std::cout << "El guardia ya no está." << std::endl; return; }

        if (this->jugadorYaObservo) {
            std::cout << "Anticipándote al peligro, ¡atacas primero al Guardia!" << std::endl;
            game->iniciarCombate(jugador, guardia, true); // true = jugador ataca primero
        } else {
            std::cout << "¡La espada no sale! ¡El Guardia Pesado te ataca por sorpresa!" << std::endl;
            game->iniciarCombate(jugador, guardia, false); // false = enemigo ataca primero
        }
        // Cuando el combate termina, revisamos si ganó
        if (guardia->hp <= 0) {
            this->guardiaVencido = true;
            std::cout << "El guardia cae. La Espada de Bruma se suelta." << std::endl;
        }
    }
    else if (guardiaVencido && !espadaRecogida && eleccion == 'a') {
        game->transferirItemDeSalaAInventario("Espada de Bruma", this, jugador);
        this->espadaRecogida = true;
    }
    else if (mapaSalidas.count(eleccion)) {
        game->cambiarSala(mapaSalidas[eleccion]);
    }
    else {
        std::cout << "Opción no válida." << std::endl;
    }
}