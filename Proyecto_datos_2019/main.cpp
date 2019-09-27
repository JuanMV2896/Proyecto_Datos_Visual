#include "Integer.h"

int main() {
	string numeroAEvaluar = "6541655615456156491561456194891951489984561561951894561561564561564650564161"
		"5614165445615645618915615464655614891564566415615645615604900498006416509180465456404564434063103105340386540684040510453105340410"
		"63840863105640175410531537040683410633100";
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