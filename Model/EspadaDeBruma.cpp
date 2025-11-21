#include "EspadaDeBruma.h"


/**Hecho por Santiago Sanchez y
 *Alejandro Botero
 */
EspadaDeBruma::EspadaDeBruma()
    : Arma(
        "Espada de Bruma",                 // Nombre
        "Una espada clavada en un bloque...", // Descripción
        15,                                // Daño Adicional
        "20% probabilidad de aturdir",     // Texto Efecto
        0,                                 // Chance Crítico
        20                                // Chance Aturdir (20%)
      )
{
}