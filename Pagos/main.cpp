#include "pago.h"
#include <iostream>

int main()  
{
    Pago pag;
    std::string nombre = "Lucas";
    pag.setNombre(nombre);
    pag.MenuPago();
}