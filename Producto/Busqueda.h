/************************************************
 * No hay clase búsqueda, es solo una función.
 * Creado en un .h distinto a producto por orden.
*************************************************/

#include <vector>
#include "producto.h"

//tipo = category
std::vector<producto> Busqueda(unsigned category, std::string name = "", float price = -1);
//orden de prioridad de productos? category > nombre > precio.


void Muestra(std::vector<producto>);

