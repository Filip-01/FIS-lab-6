#include "pago.h"

std::string Pago::Card() {
    std::string respuesta;
    std::string tarjeta_;
    do {
        std::cout << "Ingrese los 24 digitos de la tarjeta: \n";
        std::cin >> tarjeta_;
        std::cout << "¿Es " << tarjeta_ << " tu numero de tarjeta? \n";
        std::cin >> respuesta;
    }
    while ((respuesta != "si") || (tarjeta_.size() != 24));
    return tarjeta_;
}

void Pago::Paypal() {
    std::string cuenta, dominio1 = "gmail.com", dominio2 = "hotmail.com";
    do {
        std::cout << "Ingrese la cuenta de paypal: \nNota, debe de ser un gmail.com o hotmail.com\n";
        std::cin >> cuenta;
    } while ((cuenta == dominio1) || (cuenta == dominio2)); //ola@gmail.com
    std::cout << "Su cuenta " << cuenta << " fue ingresada con exito!\n";
}

void Pago::Paysafecard() {
    std::string respuesta;
    std::string pin;
    do {
        std::cout << "Ingrese los 16 digitos del PIN de Paysafecard: \n";
        std::cin >> pin;
        std::cout << "¿Es " << pin << " correcto? \n";
        std::cin >> respuesta;
    }
    while ((respuesta != "si") || (pin.size() != 16));
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

std::string Pago::Check_card(){             
    std::string comparation = "no_card_";  
    file_card_.open("file_card_.txt", std::fstream::in);
    if (file_card_.is_open())  {
        std::string card_linea;

        while (!file_card_.eof())  {
            std::getline(file_card_, card_linea,':');
            if (card_linea == nombre_)  {
                std::getline(file_card_,card_linea);
                if (card_linea == comparation)  {          // no_card_ es un string que indica si el usuario tiene una tarjeta guardada o no
                    file_card_.close();
                    card_linea = "0";
                    return card_linea;
                }
                else  {
                    file_card_.close();
                    return card_linea;
                }
            }
            else 
                std::getline(file_card_, card_linea);
        }

        file_card_.close();
        return card_linea;
    }
    else  {
        std::cout << "Error al comprobar fichero de usuarios y tarjetas.\n"; 
    }
}

bool Pago::Add_card(std::string tarjeta_){ //falta completar la funcion que introduce las tarjetas en el fichero
    
}

void Pago::MenuPago() {
    int opcion;
    std::string numero;
    std::string respuesta;

    std::cout << "Elija un metodo de pago\n" // lo pongo sin tilde para que en la ejecución se vea bien.
              << "1 -> Tarjeta de Credito\n"
              << "2 -> Cuenta de Paypal\n"
              << "3 -> Cuenta de Paysafecard\n"
              << "4 -> Transferencia bancaria\n";
    std::cin >> opcion;
    
    switch (opcion)
    {
    case 1:
        if (Check_card() != "0"){                                                               
            std::cout << "Tiene la tarjeta " << Check_card() << " guardada. ¿Desea usarla? \n";       
            std::cin >> respuesta;                                                              
            if ((respuesta == "si") || (respuesta == "Si")){                                    
                std::cout << "Pago realizado con la tarjeta guardada";                                                                                                          //
                break; 
            }
            else {                                                             
                Card();
                break;
            }                                                                          
        }                                                                                       
        else                                                                                                                             
            numero = Card();
            std::cout << "¿Desea guardar su tarjeta?";                                          
            std::cin >> respuesta;                                                              
            if ((respuesta == "si") || (respuesta == "Si")){                                    
                Add_card(numero);                                                                     
                break;                                                                           
            }                                                                                   
            else                                                                                
                break;
    case 2:
        Paypal();
        break;

    case 3:
        Paysafecard();
        break;

    case 4:
        Banco();
        break;
    
    default:
        std::cout << "Ingrese una de las opciones disponibles\n";
        break;
    }
}