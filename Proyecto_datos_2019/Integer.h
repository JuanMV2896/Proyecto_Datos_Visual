#pragma once
#include"Lista.h"
#include"Stack.h"
#include"ObjetoBase.h"

#define ZERO 0
#define ONE 1

using namespace std;
template<class T>
class Integer : public ObjetoBase {
public:
	Integer();
	Integer(Lista<T>*, Stack<T>*);
	Integer(const Integer<T>& orig);
	virtual ~Integer();
	//    virtual Integer<T>* sumar(Integer<T>*);
	//    virtual Integer<T>* restar(Integer<T>*);
	//    virtual Integer<T>* division(Integer<T>*);
	//    virtual Integer<T>* multiplicacion(Integer<T>*);
	//    virtual Integer<T>& operator==(const Integer<T>&);
	//    virtual Integer<T>& operator*(const Integer<T>&);
	//    virtual Integer<T>& operator/(const Integer<T>&);
	//    virtual Integer<T>& operator+(const Integer<T>&);
	//    virtual Integer<T>& operator-(const Integer<T>&);
	//    virtual Integer<T>& operator=(const Integer<T>&);
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
	virtual void setsatck(Stack<T>*);
	virtual Stack<T>* getStack();
	virtual string toString()const;

private:
	Lista<T>* _lista;
	Stack<T>* _stack;
};

template<class T>
inline Integer<T>::Integer():_lista(nullptr),_stack(nullptr)
{
}

template<class T>
inline Integer<T>::Integer(Lista<T>*, Stack<T>*)
{
}

template<class T>
inline Integer<T>::Integer(const Integer& orig)
{
}

template<class T>
inline Integer<T>::~Integer()
{
	if (_stack)
		_stack->~Stack;
	if (_lista)
		_lista->~Lista;
}

template<class T>
inline void Integer<T>::setLista(Lista<T>*)
{
}

template<class T>
inline Lista<T>* Integer<T>::getLista()
{
	return NULL;
}

template<class T>
inline void Integer<T>::setsatck(Stack<T>*)
{
}

template<class T>
inline Stack<T>* Integer<T>::getStack()
{
	return NULL;
}

template<class T>
inline string Integer<T>::toString() const
{
	return string();
}
