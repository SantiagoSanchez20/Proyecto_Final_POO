#include "Sala.h"
#include "../Controller/GameManager.h"
#include "Player.h"
#include "Inventario.h"
#include <limits>
#include <cctype>

void Sala::manejarTurno(GameManager* game, Player* jugador) {

    std::vector<std::string> opciones;
    std::map<char, std::string> mapaSalidas;
    char opcionActual = 'a';

    for (auto const& [textoOpcion, idSala] : this->salidas) {
        opciones.push_back(textoOpcion);
        mapaSalidas[opcionActual] = idSala;
        opcionActual++;
    }

    opciones.push_back("Ver Inventario");
    char opcionInventario = opcionActual;
    opcionActual++;

    opciones.push_back("Salir del Juego");
    char opcionSalir = opcionActual;
    opcionActual++;


    char eleccion = presentarOpcionesYLeerInput(opciones);


    if (mapaSalidas.count(eleccion)) {
        game->cambiarSala(mapaSalidas[eleccion]);
    }
    else if (eleccion == opcionInventario) {
        jugador->inventario->mostrar();
        std::cout << "(Presiona Enter para continuar...)";
        std::cin.get();
    }
    else if (eleccion == opcionSalir) {
        //
        game->terminarJuego(false);
    }
    else {
        std::cout << "Opción no válida." << std::endl;
    }
}

char Sala::presentarOpcionesYLeerInput(const std::vector<std::string>& opciones) {
    std::cout << "\n¿Qué haces?" << std::endl;
    char letra = 'a';
    for (const std::string& opcion : opciones) {
        std::cout << "  " << (char)toupper(letra) << ". " << opcion << std::endl;
        letra++;
    }
    std::cout << "> ";

    char eleccion;
    std::cin >> eleccion;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return std::tolower(eleccion);
}