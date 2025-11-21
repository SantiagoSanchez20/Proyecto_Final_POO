#include "Player.h"
#include "Enemigo.h"
#include "Arma.h"
#include "Item.h"
#include "Inventario.h" //
#include <cstdlib> // Se incluye esta libreria para que se una la funcion Rand()
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
Player::Player()
: Personaje("Jugador",100),
ataqueBase(12),
hpMax(100),
armaEquipada(nullptr)
{
    // Como 'inventario' es un puntero, debemos inicializarlo con 'new'
    this->inventario = new Inventario();
}

// Destructor: Se llama automáticamente cuando el Player deja de existir.
Player::~Player() {
    delete this->inventario;
}

//Implementacion de añadir buff al jugador
void Player::agregarBuff(const Buff &buff) {
    this->buffsActivos.push_back(buff);
    std::cout << "[Jugador] Sientes un nuevo poder: " << buff.nombre
    << " (+" << buff.aumentoAtaque << " Atk, " << buff.turnosRestantes << " turnos)"  << std::endl;
}

//Implementacion de actualizar el buff
void Player::actualizarBuff() {

    //Usamos un iterador 'while' por que es mas seguro
    //al borrrar elementos de un vector mientras se itera.
    auto it = this->buffsActivos.begin();
    while (it != this->buffsActivos.end()) {
        it->turnosRestantes--;

        //Comprabacion si el buff expiro en la turnos correspondientes
        if (it->turnosRestantes <= 0) {
            std::cout << "[Jugador] El efecto "
            << it->nombre << " se ha disipado." << std::endl;

            //Borramos el buff del vector
            //'erase' devuelve el iterador al "siguiente" elemento
            it = this->buffsActivos.erase(it);

        } else {
            //Sigue activo si no ha expirado la cantidad de turno que lleva el buff por encima
            it++;
        }
    }
}

int Player::getDanoAtaqueTotal() const {
    int total = this->ataqueBase;

    for (const Buff& buff : this->buffsActivos) {
        total += buff.aumentoAtaque;
    }
    return total;
}

//Implementacion de la Herencia recibiDano
void Player::recibirDano(int cantidad) {

    this->hp -=cantidad;

    if (this->hp < 0) {
        this->hp = 0; //Colocamos esto para evitar que haya vida negativa
    }
    std::cout << "[Jugador] "<< this->nombre << " recibe "<< cantidad <<
        " de daño. Vida restante: " << this->hp << std::endl;

    if (!this->estaVivo()) {
        std::cout << "[Jugador] "<< this->nombre << " ha sido derrotado."<<std::endl;
    }
}

//Metodos de interaccion
void Player::atacar(Enemigo* objetivo) {
    if (!this->estaVivo()) {
        std::cout << "[Jugador] No puedes atacar, estas muerto." << std::endl;
        return;
    }
    if (!objetivo->estaVivo()) {
        std::cout << "[Jugador] El objetivo " << objetivo->getNombre() << " ya esta derrotado." << std::endl;
        return;
    }

    // 1. Calcular daño base (Stats + Buffs)
    int danoTotal = this->getDanoAtaqueTotal();
    std::string nombreArma = "su Espada de Hierro";

    bool esCritico = false;
    bool aturde = false;

    // 2. Verificar bonos del arma (Aquí ocurre la magia del azar)
    if (this->armaEquipada != nullptr) {
        danoTotal += this->armaEquipada->danioAdicional;
        nombreArma = "su " + this->armaEquipada->getNombre();

        // --- CÁLCULO DE CRÍTICO ---
        // Generamos un número del 0 al 99. Si es menor que el porcentaje, es crítico.
        if ((rand() % 100) < this->armaEquipada->chanceCritico) {
            esCritico = true;
            danoTotal *= 2; // El crítico duplica el daño final
        }

        // --- CÁLCULO DE ATURDIR ---
        if ((rand() % 100) < this->armaEquipada->chanceAturdir) {
            aturde = true;
        }
    }

    // 3. Imprimir resultado limpio
    std::cout << "[Jugador] " << this->nombre << " ataca a " << objetivo->getNombre()
        << " con " << nombreArma;

    if (esCritico) {
        std::cout << " ¡GOLPE CRITICO!";
    }

    std::cout << " e inflige " << danoTotal << " de daño." << std::endl;

    if (aturde) {
        std::cout << "[Efecto] ¡" << objetivo->getNombre() << " ha quedado ATURDIDO por el golpe!" << std::endl;
    }

    // 4. Aplicar el daño calculado
    objetivo->recibirDano(danoTotal);
}

//Implementamos el mover al player.
void Player::mover() {
    // Implementar en esta funcion de player cuando se este en salas
    std::cout << "[Jugador] " << this->nombre << " se mueve..." << std::endl;
}

//----Gestion de Estado----
void Player::equiparArma(Arma* nuevaArma) {
    this->armaEquipada = nuevaArma;
    if (nuevaArma != nullptr) {
        std::cout << "[Jugador] " << this->nombre << " ha equipado "
            << nuevaArma->getNombre() << "." << std::endl;
    } else {
        std::cout << "[Jugador] " << this->nombre << " ha desequipado su arma" << std::endl;
    }
}

Arma* Player::getArmaEquipada() const {
    return this->armaEquipada;
}

void Player::curar(int cantidad) {
    this->hp += cantidad;
    if (this-> hp > this->hpMax) {
        this->hp = this->hpMax;
    }
    std::cout << "[Jugador] " << this->nombre << " se cura " << cantidad
        << " de vida. Vida actual: " << this->hp << std::endl;
}

// Implementación de usarItem (declarado en el .h)
void Player::usarItem(Item* item) {
    if (item != nullptr) {
        // Aquí asumimos que la clase Item tiene un método usar(Player*)
        item->usar(this);
        std::cout << "Usando item: " << item->getNombre() << std::endl;
    }
}





