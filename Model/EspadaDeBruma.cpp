#include "EspadaDeBruma.h"
EspadaDeBruma::EspadaDeBruma()
    : Arma(
        "Espada de Bruma",                 // Nombre
        "Una espada clavada en un bloque...", // Descripción
        15,                                // Daño Adicional
        "10% probabilidad de aturdir",     // Texto Efecto
        0,                                 // Chance Crítico
        10                                 // Chance Aturdir (10%)
      )
{
}