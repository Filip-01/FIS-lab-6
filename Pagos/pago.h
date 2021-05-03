/*********************************
 * Clase Pago, que tiene los métodos relacionados con los pagos
 * y las características del mismo.
 * 
 **********************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

class Pago {
    public:
    Pago() {}
    ~Pago() {}

    void MenuPago();
    void setNombre(std::string nombre) {nombre_ = nombre;}

    
    std::string Card();
    void Paypal();
    void Paysafecard();
    void Banco();

    std::string Check_card();       // esta función detecta si hay una tarjeta asociada al usuario
    bool Add_card(std::string tarjeta_);
    void Add_user();

    private:
    long numero;
    std::string nombre_;
    std::fstream file_card_;

};