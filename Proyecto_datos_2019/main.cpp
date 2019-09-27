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
	cout << "Dgitos del numero: " << numeroDigitos << endl;
	cout << "Numero optimo de ranuras por stack: "<< ranuras << endl;
	cout << "Numero optimo de stacks: " << stacks<<endl;
	cout << "Total de ranuras aplicadas: " << (ranuras * stacks) << endl;
	cout << "Capacidad total de digitos que se pueden almacenar: "<< (ranuras * stacks) *9<<endl;
	
	//string p;
	//Stack<int>* s0 = new Stack<int>();
	//Stack<int>* s1 = new Stack<int>();
	//Stack<int>* s2 = nullptr;
	//s0->push(2);
	//s0->push(4);
	//s0->push(6);
	//s0->push(7);
	//s0->push(8);
	//s0->push(3);
	//s0->push(1);
	//s0->push(3);
	//cout << "s0: " << s0->toString() << endl;
	////s1->push(2);
	////s1->push(4);
	////s1->push(6);
	////s1->push(7);
	////s1->push(8);
	////s1->push(3);
	////s1->push(1);
	////s1->push(3);
	//s1->push(3);
	//s1->push(5);
	//s1->push(2);
	//s1->push(6);
	//s1->push(8);
	//s1->push(3);
	//s1->push(4);
	//s1->push(1);
	//cout << "s1: " << s1->toString() << endl;
	//if (*s0 == *s1) {
	//	cout << "-------------------Son iguales----------------\n";
	//}
	//else {
	//	cout << "-------------------NO Son iguales----------------\n";
	//}
	//Lista<Stack<int>>* list = new Lista<Stack<int>>();
	//Lista<Stack<int>>* list2 = new Lista<Stack<int>>();
	//Lista<Stack<int>>* list3 = nullptr;
	//list->agregar(s0);
	//list2->agregar(s1);
	//cout << "Imprimiendo Lista 1 y Lista 2\n";
	//cout << list->toString();
	//cout << list2->toString();
	////cout << "\nSuma es: \n";
	////list3 = *list + *list2;
	//cout << "\nResta es: \n";
	////list3 = *list - *list2;
	//*list -= *list2;
	//cout << list->toString();
	//cout << "\nfin de prueba\n";
	//cout << "Probando suma de lista/n";
	//cout << "**************Integers*******" << endl;
	////Integer<Lista<Stack<int>>>* in = new Integer<Lista<Stack<int>>>(list);
	//cout << "**************Integers*******" << endl;
	//cout << "RESTANDO STACKS\n";
	//s2 =*s0 - *s1;
	//cout << "s0: " << s2->toString() << endl;
	//Stack<int>* comodin = nullptr;
	//try {
	//	cout << "Sumando STACKS\n";
	//	*s0 += *s1;
	//}
	//catch (exception ex) {
	//	cerr << "Exception: " << ex.what() << endl;
	//}
	//cout << "s0: " << s0->toString() << endl;

	//cout << "\nSUMANDO STACKS\n";
	//*s0 + *s1;
	//cout << "s0: " << s0->toString() << endl;
	//s0->~Stack();
	/*
	Integer<double>* _myInteger = new Integer<double>(73187498132748917);/
	*/
	//Integer<int>* _myInteger = new Integer<int>();
	//_myInteger->getLista()->agregar(s0);
	//_myInteger->getLista()->agregar(s1);
	////Integer<int>* _mySecondInteger = nullptr;	
	//cout << _myInteger->toString() << endl;
	//cout << _myInteger->getLista()->toString() << endl;
	//while (!_myInteger->getLista()->recuperar(0)->is_empty()) {
	//	//cout << _myInteger->getLista()->recuperar(0)->pop() << endl;//imprimo los elementos del stack
	//_myInteger->getLista()->recuperar(1)->push(_myInteger->getLista()->recuperar(0)->pop());//paso los elementos del stack a otro
	//}
	//cout << _myInteger->getLista()->toString();

	////_mySecondInteger = _myInteger;
	////cout << _myInteger->toString() << endl;
	////cout << _mySecondInteger->toString() << endl;
	//delete _myInteger;
	return 0;
}
int calcularNumeroOptimoDeRanuras(int size)
{
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

int calcularNumeroOptimoDeStacks(int size)
{
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
