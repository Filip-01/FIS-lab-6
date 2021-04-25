//Función menú que muestra REQUESITOS 
//Por Jorge Hernández Toledo. El que no sabe programar

#include <iostream>


int menu();
void opciones(int option);

int main()
{
    int option = menu();
    return 0;
}

int menu() {
    int option;
    do {
    std::cout << "Esto es un menu\nSeleccione una opción: " << std::endl;
    std::cout << "________________________________________" << std::endl;
    std::cout << "[1] ¿Nuevo Usuario? ¡REGÍSTRATE YA!" << std::endl;
    std::cout << "[2] ¿Ya tienes cuenta? ¡INICIA SESIÓN!" << std::endl; 
    std::cout << "[3] SALIR" << std::endl;
    std::cout << "________________________________________" << std::endl;
    std::cin >> option;
    opciones(option);
    } while (option != 3);
}

void opciones(int option) {
    switch (option) {
        case 1:
        std::cout << "________________________________________" << std::endl;
        std::cout << "Introduce un nombre de usuario: " << std::endl;
        std::cout << "Verifica el nombre de usuario: " << std::endl;
        std::cout << "Introduce una contraseña: " << std::endl;
        std::cout << "Verifica la contraseña: " << std::endl;
        std::cout << "________________________________________" << std::endl;
        break;
        
        case 2:
        std::cout << "________________________________________" << std::endl;
        std::cout << "Introduce un nombre de usuario: " << std::endl;
        std::cout << "Introduce una contraseña: " << std::endl;
        std::cout << "________________________________________" << std::endl;
        break; 
        
        case 3: 
        std::cout << "________________________________________" << std::endl;
        std::cout << "Vuelva pronto." << std::endl;
        
        default:
        std::cout << "________________________________________" << std::endl;
        std::cout << "Por favor, introduce una opción válida" << std::endl;
        std::cout << "________________________________________" << std::endl;
        break;
    }
}