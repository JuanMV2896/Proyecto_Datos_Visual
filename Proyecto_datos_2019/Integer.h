#pragma once
#include"Lista.h"
#include"Stack.h"
#include"ObjetoBase.h"

#define ZERO 0
#define ONE 1

using namespace std;
template<class T>
class Integer : public ObjetoBase{
public:
	Integer();
	Integer(Lista<T>*, Stack<T>*);
	Integer(const Integer<T>& orig);
	virtual ~Integer();
	virtual Integer<T>& operator=(const Integer<T>&);
	//    virtual Integer<T>* sumar(Integer<T>*);
	//    virtual Integer<T>* restar(Integer<T>*);
	//    virtual Integer<T>* division(Integer<T>*);
	//    virtual Integer<T>* multiplicacion(Integer<T>*);
	//    virtual Integer<T>& operator==(const Integer<T>&);
	//    virtual Integer<T>& operator*(const Integer<T>&);
	//    virtual Integer<T>& operator/(const Integer<T>&);
	//    virtual Integer<T>& operator+(const Integer<T>&);
	//    virtual Integer<T>& operator-(const Integer<T>&);

	//    virtual Integer<T>& operator+=(const Integer<T>&);
	//    virtual Integer<T>& operator-=(const Integer<T>&);
	//    virtual Integer<T>& operator*=(const Integer<T>&);
	//    virtual Integer<T>& operator/=(const Integer<T>&);
	//    virtual Integer<T>& operator!=(const Integer<T>&);
	//    virtual Integer<T>& operator<(const Integer<T>&);
	//    virtual Integer<T>& operator<=(const Integer<T>&);
	//    virtual Integer<T>& operator>(const Integer<T>&);
	//    virtual Integer<T>& operator>=(const Integer<T>&);
	//    virtual Integer<T>& operator<<(const Integer<T>&);
	//    virtual long* parse(string);
	//    virtual int* parse(string);
	virtual void setLista(Lista<T>*);
	virtual Lista<T>* getLista();
	virtual void setStack(Stack<T>*);
	virtual Stack<T>* getStack();
	virtual string toString()const;

private:
	//Lista<Stack<T>>* _lista;
	Lista<T>* _lista;
	Stack<T>* _stack;
};

template<class T>
inline Integer<T>::Integer():_lista(new Lista<T>()),_stack(new Stack<T>())
{
}

template<class T>
inline Integer<T>::Integer(Lista<T>* x, Stack<T>* y)
{
	_lista = x;
	_stack = y;
}

template<class T>
inline Integer<T>::Integer(const Integer& orig)
{
	//Copiando Stack, como el stack ya tiene implementado el operador
	//de asignacion entonces se realiza directamente.
	*_stack = *orig.getStack();
	//Copiando Lista, como la lista ya tiene implementado el operador 
	//de asignacion entonces se realiza directamente.
	*_lista = *orig.getLista();
}

template<class T>
inline Integer<T>::~Integer()
{
	if(!_lista->vacia())
		delete _lista;
	delete _stack;	
}

template<class T>
inline Integer<T>& Integer<T>::operator=(const Integer<T>& s)
{
	if (this != &s) {
		if (_lista != nullptr && _stack!= nullptr) {
			delete _lista;
			delete _stack;
		}
		_stack = s._stack;
		_lista = s._lista;
	}
	return *this;
}

template<class T>
inline void Integer<T>::setLista(Lista<T>* lista)
{
	_lista = lista;
}

template<class T>
inline Lista<T>* Integer<T>::getLista()
{
	return _lista;
}

template<class T>
inline void Integer<T>::setStack(Stack<T>* stack)
{
	if (_stack->is_empty())
		_stack = stack;
	else
		throw exception(_canNotOverrideException_);
}

template<class T>
inline Stack<T>* Integer<T>::getStack()
{
	return _stack;
}

template<class T>
inline string Integer<T>::toString() const
{
	stringstream s;	
		s << "El objeto declarado tiene: " << endl;
		s << _stack->count() << " elementos en el stack.\n";
		s << _lista->numElementos() << " elementos en la lista.\n";
	return s.str();
}