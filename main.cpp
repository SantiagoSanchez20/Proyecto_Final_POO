#include <iostream>
#include <vector>
#include "Personaje.h"
#include "Mago.h"
#include "Guerrero.h"

/**
 * @file main.cpp
 * @brief Programa principal para demostrar Herencia y Polimorfismo.
 */
int main() {
    std::cout << "===== DEMOSTRACIoN DE HERENCIA Y POLIMORFISMO =====" << std::endl;

    // 1. Creamos un vector de punteros a la clase BASE (Personaje*).
    // Esto nos permite almacenar en la misma lista objetos de diferentes
    // clases derivadas (Mago, Guerrero), tratándolos a todos como "Personajes".
    std::vector<Personaje*> compania;

    // 2. Creamos los objetos en memoria dinámica (Heap) y guardamos sus punteros.
    std::cout << "\n--- Reclutando la compannia ---" << std::endl;
    compania.push_back(new Mago("Gandalf"));
    compania.push_back(new Guerrero("Aragorn"));
    compania.push_back(new Guerrero("Gimli"));
    compania.push_back(new Mago("Saruman"));

    // 3. POLIMORFISMO EN ACCIoN.
    // Recorremos el vector y llamamos al mismo método 'atacar()' para todos.
    // Gracias a 'virtual' y 'override', C++ sabe qué version especifica del
    // método llamar en tiempo de ejecucion para cada objeto.
    std::cout << "\n--- !La compannia entra en accion! ---" << std::endl;
    for (const auto* personajePtr : compania) {
        // La misma linea de codigo produce diferentes resultados.
        personajePtr->atacar();
    }

    // 4. LIBERACIoN DE MEMORIA.
    // Es CRUCIAL liberar la memoria que solicitamos con 'new'.
    std::cout << "\n--- Disolviendo la compannia (liberando memoria) ---" << std::endl;
    for (auto* personajePtr : compania) {
        delete personajePtr; // Se llama al destructor correcto gracias al destructor virtual.
    }
    compania.clear(); // Se vacia el vector de punteros.

    std::cout << "\n==============================================" << std::endl;
    std::cout << "Simulacion finalizada." << std::endl;

    return 0;
}

