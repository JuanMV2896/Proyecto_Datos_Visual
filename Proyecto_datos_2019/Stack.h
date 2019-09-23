#pragma once
#include <exception>
#include <iostream>
#include <sstream>
using namespace std;

#define MAX_ELEMENTS 20

template <class T>
class Stack {
public:
	Stack(int = MAX_ELEMENTS);
	Stack(const Stack<T>&);
	virtual ~Stack();
	Stack<T>& operator=(const Stack<T>&);

	virtual int is_empty() const;
	virtual int max_size() const;
	virtual int count() const;
	virtual T top() const;

	virtual void push(T);
	virtual T pop();

	virtual std::string toString() const;

private:
	int _n;
	T* _v;
	int _k;
};

template <class T>
Stack<T>::Stack(int n) : _n(n), _v(new T[n]), _k(0) {
}

template <class T>
Stack<T>::Stack(const Stack<T>& s) : _n(s._n), _v(new T[s._n]), _k(0) {
	for (int i = 0; i < s._k; i++) {
		_v[_k++] = s._v[i];
	}
}

template <class T>
Stack<T>::~Stack() {
	if (_v != NULL) {
		delete _v;
	}
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& s) {
	if (this != &s) {
		if (_v != NULL) {
			delete _v;
		}

		_n = s._n;
		_v = new T[s._n];
		_k = 0;

		for (int i = 0; i < s._k; i++) {
			_v[_k++] = s._v[i];
		}
	}
	return *this;
}

template <class T>
int Stack<T>::is_empty() const {
	return count() == 0;
}

template <class T>
int Stack<T>::max_size() const {
	return _n;
}

template <class T>
int Stack<T>::count() const {
	return _k;
}

template <class T>
T Stack<T>::top() const {
	if (!is_empty()) {
		return _v[_k - 1];
	}
	else {
		throw exception();
	}
}

template <class T>
void Stack<T>::push(T x) {
	if (_k < _n) {
		_v[_k++] = x;
	}
	else {
		throw exception(_fullStackException_);
	}
}

template <class T>
T Stack<T>::pop() {
	if (!is_empty()) {
		return _v[--_k];
	}
	else {
		throw exception(_nullPointerException_);
	}
}

template <class T>
string Stack<T>::toString() const {
	stringstream r;
	r << "[";
	for (int i = 0; i < _k; i++) {
		r << _v[i];
		if (i < (_k - 1)) {
			r << ", ";
		}
	}
	r << "]";
	return r.str();
}