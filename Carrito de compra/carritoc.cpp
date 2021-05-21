// LIBRERIAS
#include "iostream"
#include <stdio.h>
#include <string.h> 
using namespace std;

// VARIABLES GLOBALES
int opc; //opcion del usuario del articulo que quiere comprar
float sumaTotal;
float listaPrecios[] = { 50 , 10 , 80 , 0 };
string cupon = "fis"; // CODIGO DEL CUPON
string cuponUser; // LO QUE EL USUARIO DIGITE
 
// PROTOTIPOS
void menu();
void compraConDescuento();
 
 
// FUNCION PRINCIPAL
int main() {
	menu();
}
 
void menu() {
	// MENU DE OPCIONES DE ARTICULOS
	cout << "0. Monitor 50 euros" << endl;
	cout << "1. Teclado 10 euros" << endl;
	cout << "2. Impresora 80 euros" << endl;
	cout << "3. Finalizar la compra" << endl;
 
	do {
	cout << "Introduzca el numero del articulo: ";
	cin >>opc;
 
	// SUMA ITERATIVA
	sumaTotal += listaPrecios[opc];
 
	} while (opc != 3 );

	if (opc==3) { 
		compraConDescuento();
	} // SI LA OPCION ES 3, FINALZIAMOS LA COMPRA Y VAMOS A LOS DETALLES DE LA MISMA
}

void compraConDescuento() {
	int tieneCupon;
 
	// PREGUNTAMOS SI TIENE CUPON 
	cout << "Tenes un cupon de descuento? SI=1 | NO=0" << endl;
	cin >> tieneCupon;
 
	// SI NO TIENE CUPON
	if (tieneCupon == 0) { // NO TIENE
		cout << "No tienes un cupon, debes pagar el total de " << sumaTotal << " euros" << endl; // EL TOTAL A PAGAR SIN CUPON
	}
 
	// SI TIENE UN CUPON
	if (tieneCupon == 1) {
		cout << "Introduzca el cupon de descuento: ";
		cin >> cuponUser; // ALMACENAMOS EL CUPON QUE TIENE EL USUARIO
 
		// CONDICIONAL ANIDADO PARA COMPARAR AMBOS CUPONES
		if ( cupon == cuponUser) { // COINCIDEN Y APLICAMOS EL DESCUENTO
			float sumaTotalDescuento = sumaTotal * 0.90; // aplicamos el 10%
			cout << "Tu descuento ha sido aplicado, en lugar de pagar " << sumaTotal << " euros pagaras " << sumaTotalDescuento << " euros" << endl;
		}
 
		else { // SI EL CUPON DIGITADO NO ES VALIDO
			cout << "El cupon introducido es invalido, pagaras el original de " << sumaTotal << " euros" << endl;
		}
	}
}