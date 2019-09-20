#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
	string p;
	stack<int>* s0 = new stack<int>();

	s0->push(15);
	s0->push(34);
	s0->push(7);
	s0->push(5);
	s0->push(3);
	s0->push(8);
	s0->push(23);
	s0->push(12);
	cout << "s0: " << s0->toString() << endl;
	return 0;
}