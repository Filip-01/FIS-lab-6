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

    std::string passwd;
    std::cout << "Introduzca la contraseña.\n";
    std:.cin >> passwd;
  
    usuario.SetPasswd(passwd);
  
    usuario.WritePasswd(passwd);
  
    usuario.WriteName(nombre);
    
    std::cout << "Introduzca contraseña errónea o correcta";
    std::cin >> passwd;
    if (usuario.CheckUser(nombre))  {
      std::cout << "ok\n";
      if (usuario.CheckPasswd(passwd))  {
        std::cout << "contraseña ok";
      }
      else {
        std:.cout << "Contraseña no ok"
      }
    }
    else {
      std::cout << "no ok\n";
    }
  return 0;
}
