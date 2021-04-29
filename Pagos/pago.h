/*********************************
 * Clase Pago, que tiene los métodos relacionados con los pagos
 * y las características del mismo.
 * 
 **********************************/

#include <iostream>
#include <string>

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

    private:
    long numero;
    std::string nombre_;
};