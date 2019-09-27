#include "Integer.h"

int main() {
	string numeroAEvaluar = "15896347258";
	int numeroDigitos = 700;
	Integer* _myInteger = new Integer(numeroAEvaluar);
	cout << _myInteger->getDetalles();
	//int ranuras = _myInteger->calcularNumeroOptimoDeRanuras(numeroDigitos);
	////int stacks = _myInteger->calcularNumeroOptimoDeStacks(numeroDigitos);
	//cout << "Digitos del numero: " << numeroDigitos << endl;
	//cout << "Numero optimo de ranuras por stack: "<< ranuras << endl;
	//cout << "Numero optimo de stacks: " << stacks << endl;
	//cout << "Total de ranuras aplicadas: " << (ranuras * stacks) << endl;
	//cout << "Capacidad total de digitos que se pueden almacenar: " << (ranuras * stacks) * 9 << endl;
	return 0;
}