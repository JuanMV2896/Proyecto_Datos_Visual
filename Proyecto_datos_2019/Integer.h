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
	Integer(Lista<Stack<T>>*);
	Integer(const Integer<T>& orig);
	virtual ~Integer();
	virtual Integer<T>& operator=(const Integer<T>&);
	virtual Integer<T>& operator==(const Integer<T>&);
	virtual Integer<Stack<T> >& operator+(const Integer<Stack<T>>&);
	//    virtual Integer<T>* sumar(Integer<T>*objeto);
	//    virtual Integer<T>* restar(Integer<T>*);
	//    virtual Integer<T>* division(Integer<T>*);
	//    virtual Integer<T>* multiplicacion(Integer<T>*);
	
	//    virtual Integer<T>& operator*(const Integer<T>&);
	//    virtual Integer<T>& operator/(const Integer<T>&);
    
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
	virtual void setLista(Lista<Stack<T>>*);
	virtual Lista<Stack<T>>* getLista();
	//virtual void setStack(Stack<T>*);
	//virtual Stack<T>* getStack();
	virtual string toString()const;

private:
	//Lista<Stack<T>>* _lista;
	Lista<Stack<T>>* _lista;
	//Stack<T>* _stack;
};

template<class T>
inline Integer<T>::Integer():_lista(new Lista<Stack<T>>())
{
}

template<class T>
inline Integer<T>::Integer(Lista<Stack<T>>* x)
{
	_lista = x;
}

template<class T>
inline Integer<T>::Integer(const Integer& orig)
{
	//Copiando Lista, como la lista ya tiene implementado el operador 
	//de asignacion entonces se realiza directamente.
	*_lista = *orig.getLista();
}

template<class T>
inline Integer<T>::~Integer()
{
	if(!_lista->vacia())
		delete _lista;
}

template<class T>
inline Integer<T>& Integer<T>::operator=(const Integer<T>& s)
{
	if (this != &s) {
		if (_lista != nullptr) {
			delete _lista;
		}
		_lista = s._lista;
	}
	return *this;
}

template<class T>
inline Integer<T>& Integer<T>::operator==(const Integer<T>& objeto)
{

}

template<class T>
inline void Integer<T>::setLista(Lista<Stack<T>>* lista)
{
	_lista = lista;
}

template<class T>
inline Lista<Stack<T>>* Integer<T>::getLista()
{
	return _lista;
}

template<class T>
inline Integer<Stack<T>>& Integer<T>::operator+(const Integer<Stack<T>>& x) {
	int accarreo = 0;
	int num1 = 0;
	int num2 = 0;
	//while (this->getLista()->recuperar(0)!=NULL && !this->getLista()->recuperar(0)->is_empty()) {

	//}
	return *this;
}

template<class T>
inline string Integer<T>::toString() const
{
	stringstream s;	
		s << "El objeto declarado tiene: " << endl;
		s << _lista->numElementos() << " elementos en la lista.\n";
		//s << _lista->toString();
	return s.str();
}