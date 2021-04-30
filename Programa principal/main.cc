//Función menú que muestra REQUESITOS 
//Por Jorge Hernández Toledo. El que no sabe programar
//Compilación g++ -o main main.cc

#include <iostream>


int menu();
void opciones();
void separation();

int main()
{
    opciones();
    return 0;
}

int menu() {
    int selection;
    separation();
    std::cout << "[1] ¿Nuevo Usuario? ¡REGÍSTRATE YA!" << std::endl;
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
    std::cout << "Esto es un menu de PapaGay Store" << std::endl;

    while (option != 3) {
        option = menu();
        switch (option) {
            case 1:
                separation();
                std::cout << "Introduce un nombre de usuario: " << std::endl;
                std::cout << "Verifica el nombre de usuario: " << std::endl;
                std::cout << "Introduce una contraseña: " << std::endl;
                std::cout << "Verifica la contraseña: " << std::endl;
            break;
        
            case 2:
                separation();
                std::cout << "Introduce un nombre de usuario: " << std::endl;
                std::cout << "Introduce una contraseña: " << std::endl;
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