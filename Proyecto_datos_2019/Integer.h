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
	Integer(Lista*, Stack*);
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
	virtual void setlista(Lista*);
	virtual Lista* getlista();
	virtual void setsatck(Stack*);
	virtual Stack* getsatck();

private:
	Lista* _lista;
	Stack* _stack;
};