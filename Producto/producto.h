/*
 *  Clase Producto
 *  
 * 
 * 
 * 
 */
#include <stdlib.h>
#include <iostream>
#define IDLENGHT 10

// categorias
#define C_SPORT 1
#define C_HOME 2
#define C_CLOTHES 3
#define C_CAR 4
#define C_TECH 5
#define C_OTHER 6
#define C_NONE 0

class producto {
  protected:
    unsigned id_ = C_NONE;
    std::string name_ = "Default";
    unsigned category_ = 0;
    float price_ = -1;
    bool available_;
  public:
    int create(std::string name, unsigned category, float price);
    std::string get_name() { return name_; }
    unsigned get_category() { return category_; }
    float get_price() { return price_; }
    unsigned get_id() { return id_; }
    bool get_available() { return available_; }
    void print();
};

int producto::create(std::string name, unsigned category, float price) {
  name_ = name;
  category_ = category_; 
  price_ = price;

  int seed = (stoi(name_) + category_);
  srand(seed);
  for(unsigned i = 1; i < IDLENGHT; i++) {
    rand();
  }
  id_ = rand();
}

void producto::print() {
  std::cout << "ID: " << id_ 
            << "\nNombre: " << name_ 
            << "\nCategoria: ";
  switch (category_) {

    case C_SPORT:
      std::cout << "Deportes";
      break;

    case C_HOME:
      std::cout << "Articulos del hogar";
      break;

    case C_CLOTHES:
      std::cout << "Ropa y calzado";
      break;

    case C_CAR:
      std::cout << "Articulos para el coche";
      break;

    case C_TECH:
      std::cout << "Tecnología y electrónica";
      break;

    case C_OTHER:
      std::cout << "Otros";
      break;

    case C_NONE:
      std::cout << "Ninguna";
      break;

    default:
      std::cout << "ERROR";
      break;
  }
  std::cout << "\nPrecio: " << price_ << "\n";
}
