#include <iostream>
#include "Integer.h"

using namespace std;

int main() {
	string p;
	Stack<int>* s0 = new Stack<int>();
	s0->push(15);
	s0->push(34);
	s0->push(7);
	s0->push(5);
	s0->push(3);
	s0->push(8);
	s0->push(23);
	s0->push(12);
	cout << "s0: " << s0->toString() << endl;
	//s0->~Stack();
	/*
	Integer<double>* _myInteger = new Integer<double>(73187498132748917);/
	*/
	Integer<int>* _myInteger = new Integer<int>();
	_myInteger->getLista()->agregar(s0);
	//Integer<int>* _mySecondInteger = nullptr;	
	cout << _myInteger->toString() << endl;
	cout << _myInteger->getLista()->toString() << endl;
	//_mySecondInteger = _myInteger;
	//cout << _myInteger->toString() << endl;
	//cout << _mySecondInteger->toString() << endl;
	delete _myInteger;
	return 0;
}