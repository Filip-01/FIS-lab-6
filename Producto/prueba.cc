#include "Busqueda.cc"

int main() {
  unsigned id;
  std::cout << "introduzca la id: ";
  std::cin >> id;
  Busqueda_id(id).print();
}