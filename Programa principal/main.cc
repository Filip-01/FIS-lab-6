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
                    std::cout << "Has sobrepasado el número de intentos de poner la contraseña.\n";
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
    std::cout << "[1] Buscar productos" << std::endl;
    std::cout << "[2] Publicar un producto" << std::endl;
    std::cout << "[3] Comprar un producto" << std::endl; 
    std::cout << "[4] Carrito de compra" << std::endl;  
    std::cout << "[5] SALIR" << std::endl;
    std::cout << "Seleccione una opcion -> ";
    std::cin >> selection;
    return selection;
}


void mainmenuOptions() {  // podria recibir la variable nombre para poder inicializarla en la clase pago
    int option = 0;
    pagar.SetNombre(user.GetName());
    while (option != 5) {
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
    return false;
}


