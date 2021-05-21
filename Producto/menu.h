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

void menu_busqueda() {
  unsigned aux, n_resultados;
  do{
    std::cout << "-----------------------Menú-----------------------\n"
              << " [1] Búsqueda por ID de producto\n"
              << " [2] Búsqueda por Nombre de producto\n"
              << " [3] Búsqueda por Categoría\n"
              << " [4] Búsqueda por Precio máximo\n"
              << " [5] Búsqueda Avanzada\n"
              << " [0] Salir\n"
              << "--------------------------------------------------\n";
    std::cin >> aux;
    unsigned id, category;
    float price;
    std::string nombre;
    std::vector<producto> resultados;

    switch (aux) {
    case 1:
      system("clear");
      std::cout << "Introduzca ID del producto: ";
      std::cin >> id;
      Busqueda_id(id).print();
      n_resultados = 1;
      break;

    case 2:
      system("clear");
      std::cout << "Introduzca Nombre del producto: ";
      std::cin >> nombre;
      resultados = Busqueda(nombre);
      n_resultados = print(resultados);
      break;

    case 3:
      system("clear");
      std::cout << "Introduzca Categoría del producto: ";
      std::cin >> category;
      resultados = Busqueda("No_product_name", category);
      n_resultados = print(resultados);
      break;

    case 4:
      system("clear");
      std::cout << "Introduzca precio máximo: ";
      std::cin >> price;
      resultados = Busqueda("No_product_name", 404, price);
      n_resultados = print(resultados);
      break;

    case 5:
      system("clear");
      std::cout << "Introduzca Nombre del producto: ";
      std::cin >> nombre;
      std::cout << "Introduzca Categoría del producto: ";
      std::cin >> category;
      std::cout << "Introduzca precio máximo: ";
      std::cin >> price;
      n_resultados = print(Busqueda(nombre, category, price));
      break;
    
    default:
      break;
    }

    product_menu(resultados, n_resultados);

  } while(aux != 0);
}