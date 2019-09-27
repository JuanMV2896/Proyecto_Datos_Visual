#include <iostream>
//#include "Integer.h"
#define _STACKMAXSIZE_ 5
#define _STACKMEDIUMPLUSIZE_ 4
#define _STACKMEDIUMSIZE_ 3
#define _STACKMEDIUMLOWSIZE_ 2
#define _STACKMINSIZE 1
#define _MAXNUMPERSTACK_ 9

using namespace std;
int calcularNumeroOptimoDeRanuras(int size);
int calcularNumeroOptimoDeStacks(int size);

int main() {
	string numeroAEvaluar = "3825709324859034825973248905238593240509324759043858934758932489042850429578324594238590824590832409583249058324905832";

	int numeroDigitos = 700;
	int ranuras = calcularNumeroOptimoDeRanuras(numeroDigitos);
	int stacks = calcularNumeroOptimoDeStacks(numeroDigitos);
	cout << "Digitos del numero: " << numeroDigitos << endl;
	cout << "Numero optimo de ranuras por stack: "<< ranuras << endl;
	cout << "Numero optimo de stacks: " << stacks << endl;
	cout << "Total de ranuras aplicadas: " << (ranuras * stacks) << endl;
	cout << "Capacidad total de digitos que se pueden almacenar: " << (ranuras * stacks) * 9 << endl;
	return 0;
}
int calcularNumeroOptimoDeRanuras(int size){
	float valor = 0;
	float _vec[9];
	int _vecOptimo[9];
	int casosOptimos = 0;
	int pos = 0;
	for (int i = 0; i < 9; i++) {
		_vec[i]= (float)(size / (float)_MAXNUMPERSTACK_) / (float)(i+1);
	}
	for (int i = 0; i < 9; i++) {
		if ((_vec[i] - (int)_vec[i]) == 0) {
			pos = i;
			_vecOptimo[casosOptimos++] = i;
		}
		if ((_vec[i] - (int)_vec[i]) > valor ) {
			valor = _vec[i] - (int)_vec[i];
			pos = i;
		}
	}
	if (casosOptimos != 0)
		return _vecOptimo[casosOptimos-1] + 1;
	return pos+1;
}

int calcularNumeroOptimoDeStacks(int size){
	float valor = 0;
	float _vec[9];
	int _vecOptimo[9];
	int casosOptimos = 0;
	int pos = 0;
	for (int i = 0; i < 9; i++) {
		_vec[i] = (float)(size / (float)_MAXNUMPERSTACK_) / (float)(i + 1);
	}
	for (int i = 0; i < 9; i++) {
		if ((_vec[i] - (int)_vec[i]) == 0) {
			pos = i;
			_vecOptimo[casosOptimos++] = _vec[i];
		}
		if ((_vec[i] - (int)_vec[i]) > valor) {
			valor = _vec[i] - (int)_vec[i];
			pos = i;
		}
	}
	if (casosOptimos != 0)
		return _vecOptimo[casosOptimos - 1];
	if ((_vec[pos] - (int)_vec[pos]) == 0)
		return _vec[pos];
	else
		return ((_vec[pos]-(_vec[pos] - (int)_vec[pos]))+1);
}