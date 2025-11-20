#include "SalaInicio.h"

SalaInicio::SalaInicio() : Sala(
    "S", // Nombre clave
    "Vestíbulo Quebrado. Puerta principal del castillo; antorchas apagadas; un corredor que se bifurca."
) {
    // Definimos las salidas
    salidas["Salir del castillo"] = "SALIR"; //
    salidas["Ir hacia la puerta de la derecha"] = "B1";
    salidas["Ir hacia la puerta de la izquierda"] = "C1";
}
