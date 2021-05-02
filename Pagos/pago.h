/*********************************
 * Clase Pago, que tiene los métodos relacionados con los pagos
 * y las características del mismo.
 * 
 **********************************/

#include <iostream>
#include <string>
#include <fstream>

class Pago {
    public:
    Pago() {}
    ~Pago() {}

    void MenuPago();
    void setNombre(std::string nombre) {nombre = nombre_;}

    
    void Card(long numero);
    void Paypal();
    void Paysafecard(long numero);
    void Banco();

    std::string Check_card();       // esta función detecta si hay una tarjeta asociada al usuario
    bool Add_card();

    private:
    long numero;
    std::string nombre_;
    std::fstream file_card_;

};