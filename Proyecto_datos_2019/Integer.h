#pragma once
#include"Lista.h"
#include"Stack.h"
#include"ObjetoBase.h"

#define ZERO 0
#define ONE 1

using namespace std;
class Integer : public ObjetoBase {
public:
	Integer();
	Integer(Lista<int>*, Stack<int>*);
	Integer(const Integer& orig);
	virtual ~Integer();
	//    virtual Integer* sumar(Integer*);
	//    virtual Integer* restar(Integer*);
	//    virtual Integer* division(Integer*);
	//    virtual Integer* multiplicacion(Integer*);
	//    virtual Integer& operator==(const Integer&);
	//    virtual Integer& operator*(const Integer&);
	//    virtual Integer& operator/(const Integer&);
	//    virtual Integer& operator+(const Integer&);
	//    virtual Integer& operator-(const Integer&);
	//    virtual Integer& operator=(const Integer&);
	//    virtual Integer& operator+=(const Integer&);
	//    virtual Integer& operator-=(const Integer&);
	//    virtual Integer& operator*=(const Integer&);
	//    virtual Integer& operator/=(const Integer&);
	//    virtual Integer& operator!=(const Integer&);
	//    virtual Integer& operator<(const Integer&);
	//    virtual Integer& operator<=(const Integer&);
	//    virtual Integer& operator>(const Integer&);
	//    virtual Integer& operator>=(const Integer&);
	//    virtual Integer& operator<<(const Integer&);
	//    virtual long* parse(string);
	//    virtual int* parse(string);
	virtual void setlista(Lista<int>*);
	virtual Lista<int>* getlista();
	virtual void setsatck(Stack<int>*);
	virtual Stack<int>* getsatck();

private:
	Lista<int>* _lista;
	Stack<int>* _stack;
};