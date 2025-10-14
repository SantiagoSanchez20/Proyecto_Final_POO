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
    int vida;

public:
    // Constructor
    Personaje(std::string nombre);

    // Destructor virtual: CRUCIAL para el polimorfismo.
    // Asegura que se llame al destructor correcto (ej. ~Mago()) cuando
    // se hace delete a un puntero de tipo Personaje*.
    virtual ~Personaje() = default;

    // Método virtual para el ataque. La palabra 'virtual' permite que las clases
    // hijas (derivadas) proporcionen su propia implementación.
    virtual void atacar() const;

    // Métodos comunes no virtuales.
    void recibirDanio(int danio);
    std::string getNombre() const;
};

#endif //PERSONAJE_H
