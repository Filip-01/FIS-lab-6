/************************************************
 * No hay clase búsqueda, es solo una función.
*************************************************/

#include <vector>
#include "producto.h"


// Funcion para método de busqueda directa por id
producto Busqueda_id(unsigned search_id) {
  // abrir archivo
  // if(getline == id) devolver
  // else no encontrado
  std::fstream product_list;
  product_list.open("../Producto/product_list_.txt");
  producto aux;
  if (product_list.is_open()) {
    std::string product_line, id = std::to_string(search_id);
    std::string name = "";
    unsigned category = 0;
    float price = 0.0;
    
    while (!product_list.eof()) {

      std::getline(product_list, product_line, ':');
        if (product_line == id) {
          std::getline(product_list, product_line, ':');
          if (product_line != "")
            category = std::stoi(product_line);
          std::getline(product_list, product_line, ':');
          if (product_line != "")
            name = product_line;
          std::getline(product_list, product_line);
          if (product_line != "")
            price = std::stof(product_line);
          product_list.close();
          aux.create(name, category, price);
          return aux;
        }
        else
          std::getline(product_list, product_line);
    }
    product_list.close();
  } else {
    std::cout << "Error al abrir el archivo de ficheros.\n";
  }
  aux.create("Default", 0, 0.0);
  return aux;
}

// Busqueda basada en la lista de argumentos de productos
std::vector<producto> Busqueda(std::string product_name = "No_product_name", unsigned product_type = 404, float product_price = 99999999) {
  // abrir archivo  
  // if(Nombre || Tipo || Precio(<)) añadir al vector
  // devolver vector
  std::vector<producto> results;
  std::fstream product_list;
  product_list.open("../Producto/product_list_.txt");
  producto aux;
  if (product_list.is_open()) {
    std::string product_line;
    std::string name = "";
    unsigned category = 0;
    float price = 0.0;
    
    while (!product_list.eof()) {

      std::getline(product_list, product_line, ':');
      std::getline(product_list, product_line, ':');
      if (product_line != "") {
        category = std::stoi(product_line);
      }
      std::getline(product_list, product_line, ':');
      if (product_line != "") {
        name = product_line;
      }
      std::getline(product_list, product_line);
      if (product_line != "") {
        price = std::stof(product_line);
      }
      product_list.close();

      if(name == product_name || category == product_type || price <= product_price) {
        aux.create(name, category, price);
        results.push_back(aux);
      }
    }
    product_list.close();
  } else {
    std::cout << "Error al abrir el archivo de ficheros.\n";
  }
  return results;
}