#include "pago.h"
#include <iostream>

int main()  
{
    Pago pag;
    std::string nombre = "Luis";
    pag.setNombre(nombre);
    pag.MenuPago();
}