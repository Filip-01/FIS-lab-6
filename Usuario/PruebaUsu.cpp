//Compila con g++ -o prueba PruebaUsu.cpp Usuario.cpp
#include "Usuario.h"

int main(int argc, char const *argv[])  {
  Usuario usuario;
  bool option;

  std::string nombre;
  std::cout << "Introduzca nombre.\n";
  std::cin >> nombre;

  usuario.SetName(nombre);

  std::string passwd;
  std::cout << "Introduzca la contraseña.\n";
  std::cin >> passwd;

  usuario.SetPasswd(passwd);

  if (!usuario.AddName())  {
    std::cout << "El usuario ya existe.\n";
  }
  
  char y_n = ' ';
  bool ok = false;
  while (y_n != 'y' && y_n != 'n')  {
    std::cout << "¿Quiere cambiar nombre y/o contraseña?(y/n).\n";
    std::cin >> y_n;
  }
  if (y_n == 'y')
    ok = true;
  else
    ok = false;
    
  if (ok)  {
    std::cout << "Introduzca nuevo nombre.\n";
    std::cin >> nombre;
  
    usuario.WriteName(nombre);

    std::cout << "Introduzca nuevo passwd.\n";
    std::cin >> passwd;
    usuario.WritePasswd(passwd);
  }

  std::cout << "Introduzca contraseña errónea o correcta.\n";
  std::cin >> passwd;

  if (usuario.CheckUser(nombre))  {
    std::cout << "ok\n";
    if (usuario.CheckPasswd(passwd))  {
      std::cout << "contraseña ok\n";
    }
    else {
      std::cout << "Contraseña no ok\n";
    }
  }
  else {
    std::cout << "no ok\n";
  }

  return 0;
}
