#include "pago.h"

void Pago::Card(long numero) {
    std::string respuesta;
    do {
        std::cout << "[";
        std::cin >> numero;
        std::cout << "]\n";
    
        do {
            std::cout << "¿Es su numero: " << numero << "?\n"
                      << "¿Si o no?";
            std::cin >> respuesta;
            if (respuesta == "no") {
                std::cout << "Vuelva a introducir el número\n";
                break;
            }
        
        } while ((respuesta != "Si") || (respuesta != "si"));
    }while(numero != 24);
}

void Pago::Paypal() {
    std::string cuenta, dominio1 = "gmail.com", dominio2 = "hotmail.com";
    do {
        std::cout << "Ingrese la cuenta de paypal: \n Nota, debe de ser un gmail.com o hotmail.com\n";
        std::cin >> cuenta;
    } while ((cuenta != dominio1) && (cuenta != dominio2)); //ola@gmail.com
    std::cout << "Su cuenta " << cuenta << " fue ingresada con exito!\n";
}

void Pago::Paysafecard(long numero) {
    std::string respuesta;
    do {
        std::cout << "[";
        std::cin >> numero;
        std::cout << "]\n";
    
        do {
            std::cout << "¿Es su PIN: " << numero << "?\n"
                      << "¿Si o no?";
            std::cin >> respuesta;
            if (respuesta == "no") {
                std::cout << "Vuelva a introducir el PIN\n";
                break;
            }
        
        } while ((respuesta != "Si") || (respuesta != "si"));
    }while(numero != 16);
}

void Pago::Banco() {
    std::string codigo, IBAN1, IBAN2, IBAN3, IBAN4;
    std::cout << "Introduzca sus 2 digitos de control\n"
              << "ES";
    std::cin >> codigo;

    std::cout << "Ingrese el IBAN de su cuenta bancaria (20 digitos): \n"
              << "Introduzca los numeros de 4 digitos en 4)\n";
    std::cin >> IBAN1 >> IBAN2 >> IBAN3 >> IBAN4;

    std::cout << "Cuenta introducida:\n"
              << "IBAN: ES" << codigo << " " << IBAN1 << " " 
              << IBAN2 << " " << IBAN3 << " " << IBAN4
              << " con exito\n";
}

void Pago::MenuPago() {
    int opcion;
    long numero;

    std::cout << "Elija un metodo de pago\n" // lo pongo sin tilde para que en la ejecución se vea bien.
              << "1 -> Tarjeta de Credito\n"
              << "2 -> Cuenta de Paypal\n"
              << "3 -> Cuenta de Paysafecard\n"
              << "4 -> Transferencia bancaria\n";
    std::cin >> opcion;
    
    switch (opcion)
    {
    case 1:
        std::cout << "Ingrese el número de la tarjeta (24 digitos): \n";
        std::cin >> numero;
        Card(numero);
        break;
    case 2:
        Paypal();
        break;
    case 3:
        std::cout << "Ingrese el PIN de Paysafecard (16 digitos): \n";
        std::cin >> numero;
        Paysafecard(numero);
        break;

    case 4:
        Banco();
        break;
    
    default:
        std::cout << "Ingrese una de las opciones disponibles\n";
        break;
    }
}