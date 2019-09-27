#include "Integer.h"

int main() {
	string numeroAEvaluar = "15896347258";
	Integer* _myInteger = new Integer(numeroAEvaluar);
	numeroAEvaluar = "615564564889894546848618";
	Integer* _mySecondInteger = new Integer(numeroAEvaluar);
	Integer* _mySuma = nullptr;
	cout << "Detalles del primer Integer\n";
	cout << _myInteger->getDetalles();
	cout << "\nDetalles del segundo Integer\n";
	cout << _mySecondInteger->getDetalles();
	cout << "Suma de ambos objetos Integer:\n";
	_mySuma = *_myInteger + *_mySecondInteger  ;
	cout <<_mySuma->getDetalles();
	return 0;
}