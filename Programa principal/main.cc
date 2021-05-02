//Función menú que muestra REQUESITOS 
//Por Jorge Hernández Toledo. El que no sabe programar
//Compilación g++ -o main main.cc ../Usuario/Usuario.cpp

#include <iostream>
#include "../Usuario/Usuario.h"

int menu();
void opciones();
void separation();
void userRegister();
void userLogin();

int main()
{
    opciones();
    return 0;
}

int menu() {
    int selection;
    separation();
    std::cout << "[1] ¿No tienes cuenta? ¡REGÍSTRATE YA!" << std::endl;
    std::cout << "[2] ¿Ya tienes cuenta? ¡INICIA SESIÓN!" << std::endl; 
    std::cout << "[3] SALIR" << std::endl;
    std::cout << "Seleccione una opcion -> ";
    std::cin >> selection;
    return selection;
}

void separation() {
    std::cout << "________________________________________" << std::endl;
    std::cout << std::endl;
}

void opciones() {
    int option = 0;
    std::cout << "Bienvenido a PapaGayo Store" << std::endl;
    Usuario user;
    std::string name;
    std::string aux;
    std::string passwd;
    while (option != 3) {
        option = menu();
        switch (option) {
            case 1:  {
                userRegister();
            break;
            }
            case 2:
                userLogin();
            break; 
        
            case 3: 
                separation();
                std::cout << "Vuelva pronto." << std::endl;
            break; 
        
            default:
                separation();
                std::cout << "Por favor, introduzca una opción válida" << std::endl;
            break;
        }
    }

}

void userRegister() {
    separation();
    Usuario user;
    std::string name;
    std::string aux;
    std::string passwd;
    bool end = true;
    do  {
        std::cout << "Introduce un nombre de usuario: " << std::endl;
        std::cin >> name;
        if (!user.CheckUser(name))  {
            user.SetName(name);
            do  {
                std::cout << "Introduce una contraseña: " << std::endl;
                std::cin >> passwd;
                std::cout << "Verifica la contraseña: " << std::endl;
                std::cin >> aux;
            if (passwd != aux)
                std::cout << "Las contraseñas no coinciden." << std::endl;
                    
        } while(passwd != aux);
        
        user.SetPasswd(passwd);
        user.AddName();
        user.AddPasswd();
      }

      else  {
          std::cout << "El nombre de usuario ya existe." << std::endl;
          end = false;
      }
    } while (!end);
    std::cout << "Usuario añadido." << std::endl;
}

void userLogin() {
    Usuario user;
    std::string name;
    std::string aux;
    std::string passwd;
    separation();
    std::cout << "Introduce un nombre de usuario: " << std::endl;
    std::cin >> name;
    user.SetName(name);

    std::cout << "Introduce una contraseña: " << std::endl;
    std::cin >> passwd;
    user.SetPasswd(passwd);
                
    if (user.CheckUser(name) && user.CheckPasswd(passwd))
        std::cout << "¡Login correcto!" << std::endl;
    else
        std::cout << "Login incorrecto." << std::endl;
}