/************************************************
 * No hay clase búsqueda, es solo una función.
 * Creado en un .h distinto a producto por orden.
*************************************************/

#include <vector>
#include "producto.h"

// Funcion para búsqueda por parámetros del producto
std::vector<producto> Busqueda(unsigned category, std::string name = "", float price = -1);
//orden de prioridad de productos? category > nombre > precio.


void Muestra(std::vector<producto>);

// Funcion para método de busqueda directa por id
producto producto::Busqueda_id(unsigned search_id) {
  // abrir archivo
  // if(getline == id) devolver
  // else no encontrado

  product_list_.open("../Producto/product_list_.txt");
  if (product_list_.is_open()) {
    std::string product_line, id = std::to_string(search_id);

    while (!product_list_.eof()) {

      std::getline(product_list_, product_line, ':');
        if (product_line == id) {
          /*
          Parte incompleta:
          obtener parámetros del getline
          return create(parametros)
          */
        }
    }
  }
}