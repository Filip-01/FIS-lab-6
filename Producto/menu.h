/*
 * Funcionalidades:
 * 1. Búsqueda (revisar disponibilidad)
 *  1.1 Por ID
 *  1.2 Categoría
 *  1.3 Nombre
 *  1.4 Precio (?)
 * 2. Recoleccion de resultados
 *  vvvvvvvvvvvvvvvvvvvvvvvvvvv     Queda por hacer
 * 3. Menu de acciones de productos
 *  3.1 Añadir al carrito
 *  3.2 elegir otro producto, "I change my mind"
 *        ACTUALMENTE TRABAJANDO EN ESTE ARCHIVO: SAÚL, JORGE_G, 
 */

#include "Busqueda.cc"
#pragma once

void BorraRepetedProduct(std::vector<producto> &vector);
void EliminaProduct(std::vector<producto> &vector, int pos);

unsigned print(std::vector<producto> resultados) {
  for(int i = 0; i < resultados.size(); i++) {
    std::cout << " [" << i + 1 << "] ----------\n";
    resultados[i].print();
  }
  return resultados.size();
}

void product_menu(std::vector<producto> resultados, unsigned n_resultados) {
  // Menú de acciones de producto
}

std::vector<producto> menu_busqueda() {
  unsigned aux, n_resultados;
  std::vector<producto> resultados(0);
  do{
    std::cout << "-----------------------Menú-----------------------\n"
              << " [1] Búsqueda por ID de producto\n"
              << " [2] Búsqueda por Nombre de producto (Not Working)\n"
              << " [3] Búsqueda por Categoría (Not working)\n"
              << " [4] Búsqueda por Precio máximo (Not working)\n"
              << " [5] Búsqueda Avanzada (Not Working)\n"
              << " [0] Salir\n"
              << "--------------------------------------------------\n";
    std::cin >> aux;
    unsigned id, category;
    float price;
    std::string nombre;
    std::vector<producto> vector;

    switch (aux) {
    case 1:
      system("clear");
      std::cout << "Introduzca ID del producto: ";
      std::cin >> id;
      Busqueda_id(id).print();
      resultados.push_back(Busqueda_id(id));
      n_resultados = 1;
      break;

    case 2:
      system("clear");
      break;
      std::cout << "Introduzca Nombre del producto: ";
      std::cin >> nombre;
      vector = Busqueda(nombre);
      for (unsigned i = 0; i < vector.size(); i++)  {
        resultados.push_back(vector[i]);
      }
      n_resultados = print(resultados);
      break;

    case 3:
      system("clear");
      break;
      std::cout << "Introduzca Categoría del producto: ";
      std::cin >> category;
      vector = Busqueda("No_product_name", category);
      for (unsigned i = 0; i < vector.size(); i++)  {
        resultados.push_back(vector[i]);
      }
      n_resultados = print(resultados);
      break;

    case 4:
      system("clear");
      break;
      std::cout << "Introduzca precio máximo: ";
      std::cin >> price;
      vector = Busqueda("No_product_name", 404, price);
      for (unsigned i = 0; i < vector.size(); i++)  {
        resultados.push_back(vector[i]);
      }
      n_resultados = print(resultados);
      break;

    case 5:
      system("clear");
      break;
      std::cout << "Introduzca Nombre del producto: ";
      std::cin >> nombre;
      std::cout << "Introduzca Categoría del producto: ";
      std::cin >> category;
      std::cout << "Introduzca precio máximo: ";
      std::cin >> price;
      vector = Busqueda(nombre, category, price);
      for (unsigned i = 0; i < vector.size(); i++)  {
        resultados.push_back(vector[i]);
      }
      n_resultados = print(Busqueda(nombre, category, price));
      break;
    
    default:
      break;
    }

    product_menu(resultados, n_resultados);

  } while(aux != 0);
  BorraRepetedProduct(resultados);
  return resultados;
}


void BorraRepetedProduct(std::vector<producto> &vector)  {
  for (unsigned i = 0; i < vector.size(); i++)  {
    for (unsigned j = i + 1; j < vector.size(); j=j)  {
      if (vector[i].IsEqual(vector[j]))  {
        producto aux = vector[j];
        vector[j] = vector[vector.size() - 1];
        vector[vector.size() - 1] = aux;
        vector.pop_back();
      }
      else
        j++;
    }
  }
}

void EliminaProduct(std::vector<producto> &vector, int pos)  {
  if (pos > (vector.size() - 1))
    return;
  
  producto aux = vector[pos];
  vector[pos] = vector[vector.size() - 1];
  vector[vector.size() - 1] = aux;
  vector.pop_back();
}