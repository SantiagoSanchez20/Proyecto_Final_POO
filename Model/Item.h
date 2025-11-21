#ifndef CLASE18POO_ITEM_H
#define CLASE18POO_ITEM_H
#include <string>

#include <iostream>
/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
class Player;
class Item
{
    protected:
    std::string nombre;
    std::string descripcion;
public:
    //constructor para item
    Item(const std::string& nombre, const std::string& descripcion);
    virtual ~Item() = default;
    //Metodo virtual para puro, obliga que las clases hijas creen su propio implementación

    virtual void usar(Player* jugador) = 0;
    //Usamos los getters(para poder leer los datos protegidos de esta clase).
    std::string getNombre() const ;
    std::string getDescripcion() const ;

};
#endif //CLASE18POO_ITEM_H