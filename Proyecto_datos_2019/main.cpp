#include <iostream>
#include "Integer.h"

using namespace std;

int main() {
	string p;
	Stack<int>* s0 = new Stack<int>();
	Stack<int>* s1 = new Stack<int>();
	s0->push(15);
	s0->push(34);
	s0->push(7);
	s0->push(5);
	s0->push(3);
	s0->push(8);
	s0->push(23);
	s0->push(12);
	cout << "s0: " << s0->toString() << endl;
	s1->push(15);
	s1->push(34);
	s1->push(7);
	s1->push(5);
	s1->push(3);
	s1->push(8);
	s1->push(23);
	s1->push(12);
	if (*s0 == *s1) {
		cout << "-------------------Son iguales----------------\n";
	}
	else {
		cout << "-------------------NO Son iguales----------------\n";
	}
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