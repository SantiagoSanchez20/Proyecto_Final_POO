#ifndef CLASE18POO_PLAYER_H
#define CLASE18POO_PLAYER_H
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
#include "Personaje.h"
#include "Inventario.h"
#include "Item.h"
#include "Buff.h"
#include <iostream>
#include <vector>
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
// Declaramos clases adelantadas
class Enemigo;
class Arma;

class Player : public Personaje {
private:
    // --- Atributos Privados ---
    Arma* armaEquipada; // Puntero al arma. 'nullptr' significa desarmado.

    // Guardamos el HP máximo para la lógica de curación
    const int hpMax;

public:
    int ataqueBase;

    Inventario* inventario;
    // -------------------------

    // Vector para guardar los buff activos
    std::vector<Buff> buffsActivos;

    // Constructor
    Player();

    // Destructor (Importante para borrar el inventario)
    virtual ~Player();

    // Añadimos un metodo agregarBuff cuando se encuentre con la alma iria
    void agregarBuff(const Buff& buff);

    // Actualiza la Duracion de todos los buffs
    void actualizarBuff();

    // Calcula el daño total
    int getDanoAtaqueTotal() const;

    // Metodos de interaccion del sistema
    void atacar(Enemigo* objetivo);

    // Funcion para usar item
    void usarItem(Item* item);

    // Funcion para mover
    void mover();

    // --- Gestion de armas ---
    void equiparArma(Arma* nuevaArma);
    Arma* getArmaEquipada() const;

    // --- Gestion de curas ---
    void curar(int cantidad);

    // Recibir daño
    virtual void recibirDano(int cantidad) override;
};

#endif //CLASE18POO_PLAYER_H