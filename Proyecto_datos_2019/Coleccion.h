#pragma once
#include "ObjetoBase.h"

using std::string;
template <class T> class Coleccion;
template <class T> class iterador;

template <class T>
class Coleccion : public ObjetoBase {
public:
	Coleccion();
	virtual ~Coleccion();

	virtual bool vacia() const;
	virtual int numElementos() const = 0;

	virtual void agregar(T*) = 0;
	virtual void agregar(const Coleccion<T>&);
	virtual void insertar(T*, int = -1) = 0;

	virtual T* extraer(int) = 0;
	virtual T* extraerUltimo() = 0;
	virtual void extraerTodos(bool = false);

	virtual T* recuperar(int) const = 0;

	virtual Coleccion<T>& operator+=(const Coleccion<T>&);

	virtual iterador<T>* obtenerIterador() const = 0;
	virtual string toString() const;
	virtual string toString(bool) const;
};

template <class T>
class iterador {
public:
	virtual ~iterador();
	virtual void reiniciar() = 0;
	virtual bool masElementos() const = 0;
	virtual T* proximoElemento() = 0;
};

template <class T>
Coleccion<T>::Coleccion() {
}

template <class T>
Coleccion<T>::~Coleccion() {
}

template <class T>
bool Coleccion<T>::vacia() const {
	return (numElementos() == 0);
}

template <class T>
void Coleccion<T>::agregar(const Coleccion<T>& otra) {
	iterador<T>* i = otra.obtenerIterador();
	while (i->masElementos()) {
		T* e = i->proximoElemento();
		agregar(e);
	}
	delete i;
}

template <class T>
void Coleccion<T>::extraerTodos(bool eliminar) {
	while (!vacia()) {
		T* e = extraerUltimo();
		if (eliminar) {
			delete e;
		}
	}
}

template <class T>
Coleccion<T>& Coleccion<T>::operator+=(const Coleccion<T>& otra) {
	agregar(otra);
	return *this;
}

template <class T>
string Coleccion<T>::toString() const {
	return toString(true);
}

template <class T>
string Coleccion<T>::toString(bool f) const {
	std::stringstream r;
	r << "Coleccion: [";

	bool primerElemento = true;
	iterador<T>* i = obtenerIterador();
	while (i->masElementos()) { // O(1)        
		if (!primerElemento) {
			r << ", ";
		}
		if (f) {
			r << "\n\t";
		}
		r << *i->proximoElemento(); // O(1)
		primerElemento = false;
	}
	delete i;

	r << (f ? "\n" : "") << "]";
	return r.str();
}

template <class T>
iterador<T>::~iterador() {
}