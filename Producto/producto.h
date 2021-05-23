/*
 *  Clase Producto
 *  
 * 
 * 
 * 
 */
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#define IDLENGHT 5

// categorias
#define C_SPORT 1
#define C_HOME 2
#define C_CLOTHES 3
#define C_CAR 4
#define C_TECH 5
#define C_OTHER 6
#define C_NONE 0


int countDigit(unsigned n) {
  return floor(log10(n) + 1);
}

class producto {
  protected:
    unsigned id_ = C_NONE;
    std::string name_ = "Default";
    unsigned category_ = 0;
    float price_ = -1;
    bool available_;
  public:
    producto()  {}
    /* ************************************************************************************
    * Necesario para devolver objetos producto.
    * Posiblemente hay que rellenar para que haga una copia (probar antes codigo con create)
    * Es posible que return create de Búsqueda_id no funcione bien, que devuelva algo vacío.
    * ************************************************************************************/
    producto(const producto& prod) : id_(prod.id_), name_(prod.name_), category_(prod.category_),
                                     price_(prod.price_), available_(prod.available_) {}  
    ~producto()  {}
    producto& create(std::string name, unsigned category, float price);
    void AddProduct();
    std::string get_name() { return name_; }
    unsigned get_category() { return category_; }
    float get_price() { return price_; }
    unsigned get_id() { return id_; }
    bool get_available() { return available_; }
    void print();
    bool IsEqual(producto prod);
};


// Yo usaría esto en el constructor, pasandole al constructor los parametros name, category, price.
producto& producto::create(std::string name, unsigned category, float price) {
  name_ = name;
  category_ = category; 
  price_ = price;
  int aux = 0;
  int seed = (*(int *)name_.c_str() + category_);
  srand(seed);
  for(unsigned i = 0; i < IDLENGHT; i++) {
    aux += rand() % 10;
    aux *= 10;
  }
  
  if(countDigit(aux) > IDLENGHT) {
    aux /= 10;
  }

  id_ = aux;
  return *this;
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
  std::cout << "\nPrecio: " << price_ << "$\n";
}

void
producto::AddProduct()  {
  std::fstream file;
    file.open( "../Producto/product_list_.txt", std::fstream::out | std::fstream::app);
    if (file.is_open())  {
      file << id_ << ":" << category_ << ":" << name_ << ":" << price_ << "\n";
      file.close();
    }
    else  {
      std::cout << "No se pudo abrir el fichero.\n";
    }
}


bool
producto::IsEqual(producto prod)  {
  return (category_ == prod.category_) && (id_ == prod.id_) && 
         (name_ == prod.name_) && (price_ == prod.price_);
}