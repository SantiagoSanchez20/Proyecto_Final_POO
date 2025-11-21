#ifndef CLASE18POO_BUFF_H
#define CLASE18POO_BUFF_H
#include <string>

struct Buff {
    std::string nombre;
    int aumentoAtaque;
    int turnosRestantes;

    Buff(const std::string& nombre, int aumentoAtaque, int turnosRestantes) :
    nombre(nombre), aumentoAtaque(aumentoAtaque), turnosRestantes(turnosRestantes) {};
};


#endif //CLASE18POO_BUFF_H