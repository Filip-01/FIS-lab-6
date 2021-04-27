#include "Usuario.h"

Usuario::Usuario()  {
}


Usuario::~Usuario()  {
  file_passwd_.close();
  file_name_.close();
}


bool
Usuario::CheckUser(std::string nombre)  {
  file_name_.open("Usuarios.txt", std::fstream::in);
  if (file_name_.is_open() )  {
    std::string nombre_en_linea;

    // Se comprueba linea por línea si un usuario existe o no.
    while (file_name_ >> nombre_en_linea ) {
    if (nombre == nombre_en_linea)
      return true;
    }

    return false;
  }
  else  {
    std::cout << "Error al comprobar fichero de nombres.\n"; // Momentaneo.
    //throw "Error";
  }
  
}


bool
Usuario::CheckPasswd(std::string passwd)  {
  file_passwd_.open("Passwords.txt", std::fstream::in);
  if (file_passwd_.is_open() )  {
    std::string passwd_linea;


    while (std::getline(file_passwd_, passwd_linea, ' '))  {

      if (passwd_linea == nombre_)  {
        std::getline(file_passwd_,passwd_linea);
        if (passwd == passwd_linea)
          return true;
        else
          return false;
      }
      else 
        std::getline(file_passwd_, passwd_linea);
    }

    return false;
  }
  else  {
    std::cout << "Error al comprobar fichero de passwd.\n"; //Momentaneo
    //throw "Error";
  }
  
}


void
Usuario::WriteName(std::string new_name)  {
  std::string name;
  file_name_.open("Usuarios.txt", std::fstream::in | std::fstream::out);
  std::fstream temp_file;
  temp_file.open("Temp.txt", std::fstream::out);
  if (file_name_.is_open() && temp_file.is_open())  {
    int contador = 0;
    while (file_name_ >> name)  {
        if (name == nombre_)  {
          name = new_name;
          contador++;
        }
        temp_file << name << "\n";
    }
    file_name_.close();
    remove("Usuarios.txt");
    if (contador != 0)  {
      
    }
    else {
      temp_file << new_name << "\n";
      temp_file.close();
    }
    rename("Temp.txt", "Usuarios.txt");

  }
  else {
    std::cout << "Error al cambiar el nombre\n";
  }
  
}


// La estructura en el fichero será del nombre del usuario seguido de un espacio y la contraseña en cada línea.
void
Usuario::WritePasswd(std::string new_passwd)  {
  std::string passwd;
  file_passwd_.open("Passwords.txt", std::fstream::in | std::fstream::out);
  std::fstream temp_file;
  temp_file.open("Temp.txt", std::fstream::out);
  if (file_passwd_.is_open() && temp_file.is_open())  {
    int contador = 0;
    while (std::getline(file_passwd_, passwd, ' '))  {
      if (passwd == nombre_)  {
        contador++;
        temp_file << passwd << " ";
        file_passwd_ >> passwd;  
        if (passwd == passwd_)  {
          passwd = new_passwd;
        }
        temp_file << passwd << "\n";
      }
      else  {
        temp_file << passwd << " ";
        file_passwd_ >> passwd;
        temp_file << passwd << "\n;      
      }
    file_name_.close();
    remove("Usuarios.txt");
    if (contador == 0)  {
      temp_file << nombre_<< " " << new_passwd << "\n";
      temp_file.close();
    }
    rename("Temp.txt", "Usuarios.txt");

  }
  else {
    std::cout << "Error al cambiar el nombre\n";
  }
  
}
