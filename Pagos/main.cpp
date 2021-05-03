#include "pago.h"
#include <iostream>

int main()  
{
    Pago pag;
    std::string nombre = "Pablo";
    pag.setNombre(nombre);
    pag.MenuPago();
}