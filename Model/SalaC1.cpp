#include "SalaC1.h"
#include "GameManager.h" // <--- Ajusta la ruta si lo tienes en otra carpeta
#include "Player.h"
#include "Trampa.h" // Importante: Incluimos la clase Trampa

// Constructor
SalaC1::SalaC1() : Sala(
    "C1",
    "Camara de las Reliquias. Estanterias con reliquias; una daga antigua brilla en la penumbra."
), puzzleResuelto(false), dagaRecogida(false)
{
    // 1. Definimos las salidas
    salidas["Avanzar hacia la Camara del Acolito"] = "C2";
    salidas["Regresar al Vestibulo"] = "S";

    // 2. Creamos la trampa ("Trampas menores" según PDF [cite: 81])
    trampasEnSala.push_back(new Trampa("Dardos Ocultos", 10));
}

// Evento al entrar: ¡La trampa salta si no has resuelto el puzzle!
void SalaC1::alEntrar(GameManager* game, Player* jugador) {
    // Llamamos al padre para mostrar la descripción básica
    Sala::alEntrar(game, jugador);

    // Si el puzzle no está resuelto, la trampa se activa
    if (!puzzleResuelto) {
        std::cout << "\n¡CLICK! Pisas una placa de presion en el suelo..." << std::endl;
        if (!trampasEnSala.empty()) {
            trampasEnSala[0]->activar(jugador);
        }
    }
}

// Menú de opciones específico de esta sala
void SalaC1::manejarTurno(GameManager* game, Player* jugador) {

    std::vector<std::string> opciones;
    std::map<char, std::string> mapaSalidas;
    char opcionActual = 'a';

    // --- 1. Opciones Específicas (Mecánica del Puzzle y Daga [cite: 77, 80]) ---

    if (!puzzleResuelto) {
        opciones.push_back("Resolver puzzle de las estanterias"); // Opción A
    }
    else if (!dagaRecogida) {
        opciones.push_back("Tomar la Daga de Velo"); // Opción A (si puzzle resuelto)
    }

    // --- 2. Opciones Genéricas (Salidas) ---
    char inicioSalidas = 'a' + opciones.size();

    for (auto const& [texto, id] : this->salidas) {
        opciones.push_back(texto);
        mapaSalidas[inicioSalidas] = id;
        inicioSalidas++;
    }

    // Agregamos Inventario y Salir
    opciones.push_back("Ver Inventario");
    char opcionInventario = inicioSalidas++;
    opciones.push_back("Salir del Juego");
    char opcionSalir = inicioSalidas++;

    // --- 3. Leer Input ---
    char eleccion = presentarOpcionesYLeerInput(opciones);

    // --- 4. Procesar Input ---

    // A: Resolver Puzzle
    if (!puzzleResuelto && eleccion == 'a') {
        std::cout << "\nMueves los libros en el orden correcto..." << std::endl;
        std::cout << "¡CLICK! Escuchas los mecanismos de las trampas desactivarse." << std::endl;
        this->puzzleResuelto = true;
    }
    // A: Tomar Daga
    else if (puzzleResuelto && !dagaRecogida && eleccion == 'a') {
        game->transferirItemDeSalaAInventario("Daga de Velo", this, jugador);
        this->dagaRecogida = true;
    }
    // Salidas (Movimiento)
    else if (mapaSalidas.count(eleccion)) {
        game->cambiarSala(mapaSalidas[eleccion]);
    }
    // Ver Inventario
    else if (eleccion == opcionInventario) {
        jugador->inventario->mostrar();
        std::cout << "(Enter para continuar)";
        std::cin.get(); std::cin.get();
    }
    // Salir
    else if (eleccion == opcionSalir) {
        game->terminarJuego(false);
    }
    else {
        std::cout << "Opcion no valida." << std::endl;
    }
}