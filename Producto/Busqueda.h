/************************************************
 * No hay clase búsqueda, es solo una función.
 * Creado en un .h distinto a producto por orden.
*************************************************/

#include <vector>
#include "producto.h"


// Funcion para método de busqueda directa por id
producto producto::Busqueda_id(unsigned search_id) {
  // abrir archivo
  // if(getline == id) devolver
  // else no encontrado
  if (product_list_.is_open())
    product_list_.close();

  product_list_.open("../Producto/product_list_.txt");
  if (product_list_.is_open()) {
    std::string product_line, id = std::to_string(search_id);
    std::string name = "";
    unsigned category = 0;
    float price = 0.0;
    while (!product_list_.eof()) {

      std::getline(product_list_, product_line, ':');
        if (product_line == id) {
          std::getline(product_list_, product_line, ':');
          if (product_line != "")
            category = std::stoi(product_line);
          std::getline(product_list_, product_line, ':');
          if (product_line != "")
            name = product_line;
          std::getline(product_list_, product_line);
          if (product_line != "")
            price = std::stof(product_line);
          product_list_.close();
          return create(name, category, price);
        }
        else
          std::getline(product_list_, product_line);
    }
    product_list_.close();
  }
  else
    std::cout << "Error al abrir el archivo de ficheros.\n";

  return create("Default", 0, 0.0);
}