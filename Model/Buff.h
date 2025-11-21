#ifndef CLASE18POO_BUFF_H
#define CLASE18POO_BUFF_H
#include <string>
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
/**
 * @brief Estructura ligera para manejar efectos temporales (Buffs).
 * * En C++, usamos 'struct' en lugar de 'class' cuando queremos un objeto simple
 * que solo guarda datos y donde todo es público por defecto.
 * Es ideal para "paquetes de datos" como este estado alterado.
 */
struct Buff {
    // --- Atributos (Públicos por defecto en un struct) ---

    std::string nombre;      // El nombre del efecto (Ej: "Bendicion de Iria")
    int aumentoAtaque;       // Cuánto daño extra se suma al ataque base del jugador
    int turnosRestantes;     // Cuántos turnos durará el efecto antes de desaparecer

    // --- Constructor ---
    // Recibe los datos necesarios para crear el buff.
    //
    // Sintaxis ": nombre(nombre)..." -> Esto se llama "Lista de Inicialización de Miembros".
    // Es la forma más eficiente en C++ de dar valor a las variables antes de que se cree el objeto.
    Buff(const std::string& nombre, int aumentoAtaque, int turnosRestantes) :
        nombre(nombre),
        aumentoAtaque(aumentoAtaque),
        turnosRestantes(turnosRestantes)
    {
        // El cuerpo del constructor está vacío porque toda la asignación
        // ya se realizó arriba en la lista de inicialización.
    };
};

#endif //CLASE18POO_BUFF_H