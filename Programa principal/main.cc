//Función menú que muestra REQUESITOS 
//Por Jorge Hernández Toledo. El que no sabe programar
//Compilación  
//g++ -w -o main main.cc ../Usuario/Usuario.cpp ../Pagos/pago.cc 

#include <iostream>
#include "../Producto/menu.h"
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
void MostrarPago(std::vector<producto> vector);

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
    std::vector<producto> lista(0);
    std::vector<producto> carrito(0);
    while (option != 6) {
        option = mainMenu();
        switch (option) {
            case 1: 
                separation();
                lista = menu_busqueda();
                print(lista);
            break;

            case 2:  {
                separation();
                producto producto1;
                unsigned category = 0;
                float price = 0.0;
                std::string nombre = ".";
                std::cout << "Escriba el nombre del producto: ";
                std::cin >> nombre;
                std::cout << "1. Deportes.\n"
                          << "2. Hogar.\n"
                          << "3. Ropa.\n"
                          << "4. Coches.\n"
                          << "5. Tecnología.\n"
                          << "6. Otras.\n"
                          << "0. Ninguna.\n"
                          << "Escriba la categoría del producto (Número):\n";
                std::cin >> category;
                do {
                  std::cout << "Escriba el precio: ";
                  std::cin >> price;
                  if (price < 0.0)
                    std::cout << "El precio no puede ser negativo.\n";
                } while (price < 0.0);
                producto1.create(nombre, category, price);
                producto1.AddProduct();
             break;
            }   
            case 3:
                separation();
                MostrarPago(carrito);
                pagar.MenuPago();
                //separation();
            break;

            case 4:
                separation();
                int opcion;
                if (lista.size() == 0)
                  std::cout << "No se ha buscado ningún producto.\n";
                else  {
                  std::cout << "Objetos a escoger (añadidas en la búsqueda):\n";
                  print(lista);
                  do {
                    std::cout << "[0] Añadir objeto.\n"
                            << "[1] Eliminar objeto.\n"
                            << "[2] Ver carrito.\n"
                            << "[3] Ver lista de objetos buscados.\n"
                            << "[4] Eliminar productos repetidos.\n"
                            << "[5] Salir (se guardará el carrito)\n"
                            << "Elija una opción: ";
                    std::cin >> opcion;
                    switch (opcion)  {
                      case 0: {
                        int objeto;
                        std::cout << "Elija un objeto (número) de la lista para añadir al carrito: ";
                        std::cin >> objeto;
                        objeto--;
                        if (objeto < lista.size() && objeto >= 0)
                          carrito.push_back(lista[objeto]);
                        else
                          std::cout << "Escoja un producto que esté en la lista.\n";
                        break;
                      }
                      case 1: {
                        int objeto;
                        std::cout << "Elija un objeto (número) de la lista para eliminar del carrito: ";
                        std::cin >> objeto;
                        if (objeto >= carrito.size() && objeto < 0)
                          std::cout << "No está en el carrito.\n";
                        else
                          EliminaProduct(carrito, objeto);
                        break;
                      }
                      case 2: {
                        print(carrito);
                        break;
                      }
                      case 3: {
                        print(lista);
                        break;
                      }
                      case 4: {
                        BorraRepetedProduct(carrito);
                        break;
                      }
                      case 5:
                        break;
                      default:
                        std::cout << "Elija una opción válida.\n";
                        break;
                    }
                  } while (opcion != 5);
                }
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

void MostrarPago(std::vector<producto> vector)  {
  float total = 0;
  for (unsigned i = 0; i < vector.size(); i++)
    total += vector[i].get_price();
  
  std::cout << "Precio total del carrito: " << total << "\n";
}