#pragma once
#include <exception>
#include <iostream>
#include <sstream>
using namespace std;

#define MAX_ELEMENTS 20

template <class T>
class Stack: public ObjetoBase {
public:
	Stack(int = MAX_ELEMENTS);
	Stack(const Stack<T>&);
	virtual ~Stack();
	Stack<T>& operator=(const Stack<T>&);
	bool operator==(const Stack<T>&);
	Stack<T>* operator+(const Stack<T>&);
	Stack<T>* operator-(const Stack<T>&);
	void operator-=(const Stack<T>&);
	void operator+=(const Stack<T>&);
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
std::ostream& operator<<(std::ostream& salida, const Stack<T>& obj) {
	salida << obj.toString();
	return salida;
}

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
			_v[_k++] = s._v[i-1];	//se modifico el s._v[i] que era el original... para eliminar el warning..
		}
	}
	return *this;
}

template<class T>
inline bool Stack<T>::operator==(const Stack<T>& object)
{
	if (object.count() == count()) {
		for (int i = 0; i < count() - 1; i++) {
			if (this->_v[i] != object._v[i])
				return false;
		}
		return true;
	}
	return false;
}

template<class T>
inline Stack<T>* Stack<T>::operator+(const Stack<T>& objeto)
{
	Stack<T>* nuevo = nullptr;
	if (count() == objeto.count()) {
		nuevo = new Stack<T>(_n);
		T acarreo = 0;
		bool siAcarrea = false;
		for (int i = 0; i < count(); i++) {
			if (siAcarrea) {
				nuevo->push(_v[i] + objeto._v[i] + acarreo);
				siAcarrea = false;
			}
			else {
				nuevo->push(_v[i] + objeto._v[i]);
			}
			if (nuevo->top() > 9 && i != count() - 1) {
				nuevo->push(nuevo->pop() % 10);
				acarreo = 1;
				siAcarrea = true;
			}
		}
		if (nuevo->top() > 9)
			throw exception(_objectOverflow_);
	}
	return nuevo;
}

template<class T>
inline Stack<T>* Stack<T>::operator-(const Stack<T>& objeto)
{
	Stack<T>* nuevo = nullptr;
	if (count() == objeto.count()) {
		nuevo = new Stack<T>(_n);
		T acarreo = 0;
		bool _siacarrea = false;
		for (int i = count() - 1; i >= 0; i--) {
			if (_v[i] < objeto._v[i] && _v[i - 1]>0) {
				_v[i - 1] -= 1;
				acarreo = 10;
				_v[i] += acarreo;
				_siacarrea = true;
			}
			nuevo->_v[i] = _v[i] - objeto._v[i];
			nuevo->_k++;
		}
	}
	return nuevo;
}

template<class T>
inline void Stack<T>::operator-=(const Stack<T>& objeto)
{
	T acarreo = 0;
	bool _siacarrea = false;
	if (count() == objeto.count()) {
		acarreo = 0;
		_siacarrea = false;
		for (int i = count() - 1; i >= 0; i--) {
			if (_v[i] < objeto._v[i] && _v[i - 1]>0) {
				_v[i - 1] -= 1;
				acarreo = 10;
				_v[i] += acarreo;
				_siacarrea = true;
			}
			_v[i] -= objeto._v[i];
		}
	}
}

template<class T>
inline void Stack<T>::operator+=(const Stack<T>& objeto)
{
	Stack<T>* comodin = new Stack<T>(_n);
	*comodin = *this;
	if (count() == objeto.count()) {
		T acarreo = 0;
		bool siAcarrea = false;
		for (int i = 0; i < count(); i++) {
			if (siAcarrea) {
				_v[i] += objeto._v[i] + acarreo;
				siAcarrea = false;
			}
			else {
				_v[i] += objeto._v[i];
			}
			if (_v[i] > 9 && i!=count()-1) {
				_v[i] = _v[i] % 10;
				acarreo = 1;
				siAcarrea = true;
			}
		}
		if (_v[count() - 1] > 9) {
			*this = *comodin;
			delete comodin;
			throw exception(_objectOverflow_);
		}
	}
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
		throw exception(_nullPointerException_);
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
string Stack<T>::toString() const{
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