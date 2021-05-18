//Función menú que muestra REQUESITOS 
//Por Jorge Hernández Toledo. El que no sabe programar
//Compilación g++ -w -o main main.cc ../Usuario/Usuario.cpp ../Pagos/pago.cc

#include <iostream>
#include "../Usuario/Usuario.h"
#include "../Pagos/pago.h"

Usuario user;
Pago pagar;

int logMenu();
void logmenuOptions();
int mainMenu();
void mainmenuOptions();
void separation();
void userRegister();
bool userLogin();
void GestPerfil();


int main() {
    std::cout << "\nBienvenido a PapaGayo Store" << std::endl;
    logmenuOptions();
    return 0;
}


int logMenu() {
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


void logmenuOptions() {
    int option = 0;
    while (option != 3 && option != 2) {
        option = logMenu();
        switch (option) {
            case 1: 
                userRegister();
            break;

            case 2:
                if (userLogin())
                    mainmenuOptions(); 
                else {
                    std::cout << "No se pudo iniciar sesión.\n";
                }
                    
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


int mainMenu() {
    int selection;
    separation();
    std::cout << "[1] Buscar productos." << std::endl;
    std::cout << "[2] Publicar un producto." << std::endl;
    std::cout << "[3] Comprar un producto." << std::endl; 
    std::cout << "[4] Carrito de compra." << std::endl
              << "[5] Modificar perfil." << std::endl;
    std::cout << "[6] SALIR." << std::endl;
    std::cout << "Seleccione una opcion -> ";
    std::cin >> selection;
    return selection;
}


void mainmenuOptions() {  // podria recibir la variable nombre para poder inicializarla en la clase pago
    int option = 0;
    pagar.SetNombre(user.GetName());
    while (option != 6) {
        option = mainMenu();
        switch (option) {
            case 1: 
                separation();
            break;

            case 2:
                separation();
            break;
                
            case 3:
                separation();
                pagar.MenuPago();
                //separation();
            break;

            case 4:
                separation();
            break;

            case 5:
                separation();
                GestPerfil();
            break;

            case 6: 
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
    std::string name;
    std::string aux;
    std::string passwd;
    
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
        std::cout << "Usuario añadido." << std::endl;
      }

      else  {
          std::cout << "El nombre de usuario ya existe." << std::endl;
          logmenuOptions();
      }
}


bool userLogin() {
    std::string name;
    std::string passwd;
    separation();
    std::cout << "Introduce un nombre de usuario: " << std::endl;
    std::cin >> name;
    user.SetName(name);
    int contador = 0;
    if (!user.CheckUser(name))
      std::cout << "El usuario no existe.\n";
    else  {
      do  {
          std::cout << "Introduce una contraseña: " << std::endl;
          std::cin >> passwd;
          user.SetPasswd(passwd);

          if (user.CheckUser(name) && user.CheckPasswd(passwd)) {
              separation();
              std::cout << "¡Login correcto!" << std::endl;
              return true;
          }
          else {
              std::cout << "Login incorrecto." << std::endl;   
              contador++;
          }     
      } while(contador < 3);
      std::cout << "Has sobrepasado el número de intentos de poner la contraseña.\n";
    }
    return false;
}


void GestPerfil()  {
  int option = 0;
  while (option != 3)  {
    std::cout << "[1] Cambiar nombre de usuario.\n"
              << "[2] Cambiar contraseña.\n"
              << "[3] Salir.\n"
              << "Elija una opción:";
    std::cin >> option;
    switch (option)  {
    case 1:  {
      while (1)  {
        std::string new_name;
        char s_n = 's';
        std::cout << "Introduzca el nuevo nombre de usuario:";
        std::cin >> new_name;

        if (new_name == user.GetName())  {
          std::cout << "El nombre nuevo es el mismo que el antiguo. ¿Quiere continuar? (s/n):";
          do  {
          if (s_n != 's' || s_n != 'n')
            std::cout << "Responda sí(s) o no(n):";
          std::cin >> s_n;
          } while (s_n != 's' && s_n != 'n');
        }
        else if (user.CheckUser(new_name))
          std::cout << "El nombre de usuario ya existe, seleccione otro.\n";
        else if (s_n != 'n')  {
          user.WriteName(new_name);
          user.SetName(new_name);
          break;
        }
      }
      break;
    }
    case 2:  {
      std::string pass;
      std::cout << "Escriba su contraseña actual:";
      std::cin >> pass;
      if (user.CheckPasswd(pass))  {
        while (1)  {
          std::cout << "Introduzca la nueva contraseña:";
          std::cin >> pass;

          if (user.CheckPasswd(pass))
            std::cout << "La contraseña es la misma que la anterior. Por favor, ponga una distinta.\n";
          else  {
            user.WritePasswd(pass);
            user.SetPasswd(pass);
            break;
          }
        }
      }
      else
        std::cout << "Contraseña incorrecta.\n";  // Estaría bien salir al menu principal aqui.
      break;
    }
    case 3:
      break;
    default:
      std::cout << "Elija una opción válida.\n";
      break;
    }
  }
  


}