#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>

/**
 * @class Personaje
 * @brief DECLARACIÓN de la clase base Personaje.
 * Contiene los datos y comportamientos comunes a todos los personajes.
 */
class Personaje {
protected:
    // Protected: Accesible para esta clase y para las clases que hereden de ella.
    std::string nombre;
    int hp;

public:
    // Constructor
    Personaje(const std::string& nombre, int hp);

    // Destructor virtual: CRUCIAL para el polimorfismo.
    // Asegura que se llame al destructor correcto (ej. ~Mago()) cuando
    // se hace delete a un puntero de tipo Personaje*.
    virtual ~Personaje() = default;

    //---Booleano para saber si esta vivo o no
    bool estaVivo() const;

    // Para acceder al nombre
    std::string getNombre() const;

    //Para acceder a la vida actual
    int getHP() const;

    //----Metodo virtual  de recibirDano para las clases hijas
    virtual void recibirDano(int cantidad) = 0;

};

#endif //PERSONAJE_H
