#include "pago.h"
#include <iostream>

int main()  
{
    Pago pag;
    std::string nombre = "Pepe";
    pag.setNombre(nombre);
    pag.MenuPago();
}