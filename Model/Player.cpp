#include "Player.h"
#include "Enemigo.h"
#include "Arma.h"
#include "Item.h"
#include "Inventario.h" // <--- ¡IMPORTANTE! Necesario para crear el inventario
#include <cstdlib> // Se incluye esta libreria para que se una la funcion Rand()

Player::Player()
: Personaje("Jugador",100),
ataqueBase(8),
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
    //Calcular daño ( Base + buff )
    int danoTotal = this->getDanoAtaqueTotal();
    std::string nombreArma = "sus punos";

    bool esCritico = false;
    bool aturde = false;

    // Verifica el arma y efectos
    if (this->armaEquipada != nullptr) {
        danoTotal += this->armaEquipada->danioAdicional;
        nombreArma =  "su " + this->armaEquipada->getNombre();

        //Se usa Rand para genera numero del 0 - 100
        //Probabilidad de critico
        if (rand() % 100 < this->armaEquipada->chanceCritico) {
            esCritico = true;
            danoTotal *= 2;
        }

        if (rand() % 100 < this->armaEquipada->chanceAturdir) {
            aturde = true;
        }
    }

    std::cout << "[Jugador] " << this->nombre << " ataca a " << objetivo->getNombre()
          << " con " << nombreArma;

    if (esCritico) std::cout << " ¡GOLPE CRITICO! ";
    std::cout<< " inflige " << danoTotal << " de dano." << std::endl;

    if (aturde) {
        std::cout << "[Efecto] ¡" << objetivo->getNombre() << " ha quedado ATURDIDO!" << std::endl;
    }

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
        // item->usar(this);
        std::cout << "Usando item: " << item->getNombre() << std::endl;
    }
}





