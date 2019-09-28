#include "Integer.h"
#include<cmath> 
#include"bigint.h"

using namespace Dodecahedron;

Integer* fib(int n);

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
	_mySuma = *_myInteger + *_mySecondInteger;
	cout <<_mySuma->getDetalles();

	system("cls");
	cout << "---------Calculando la serie de Fibonacci-----------" << endl;
	Integer* _myFibonacci = nullptr;
	int n = 1100;
	_myFibonacci = fib(n);
	std::cout << _myFibonacci->getDetalles()<< std::endl;
	cout << "\n--------Calculando el factorial---------" << endl;
	Stack<int>* s0 = new Stack<int>();
	s0->push(4567);
	s0->push(4321);
	Stack<int>* s1 = new Stack<int>();
	s1->push(345);
	s1->push(7563);
	cout << "**********Comprobando resta de stacks*******" << endl;
	cout << s0->toString()<<endl;
	cout << s1->toString()<<endl;
	Stack<int>* s2 = new Stack<int>();
	s2 = *s0 - *s1;
	cout << "Restando ->" << s2->toString() << endl;
	return 0;
}


Integer* fib(int n) {
	double phi = (1 + sqrt(5)) / 2;
	return new Integer(std::to_string(round(pow(phi, n) / sqrt(5))));
}