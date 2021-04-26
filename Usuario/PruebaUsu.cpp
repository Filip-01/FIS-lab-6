//Compila con g++ -o prueba PruebaUsu.cpp Usuario.cpp
#include "Usuario.h"

int main(int argc, char const *argv[])  {
  Usuario usuario;
  bool option;

    std::string nombre;
    std::cout << "Introduzca nombre.\n";
    std::cin >> nombre;

    usuario.SetName(nombre);

    std::cout << "Introduzca nuevo nombre.\n";
    std::cin >> nombre;

    usuario.WriteName(nombre);
    
    if (usuario.CheckUser(nombre))  {
      std::cout << "ok\n";
    }
    else {
      std::cout << "no ok\n";
    }
  return 0;
}
