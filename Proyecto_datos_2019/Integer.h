#pragma once
#include"Lista.h"
#include"Stack.h"
#include"ObjetoBase.h"
#include "Utiles.h"
#define ZERO 0
#define ONE 1
#define _MAXNUMPERSTACK_ 9

using namespace std;
class Integer : public ObjetoBase{
public:
	Integer();
	Integer(string x);
	Integer(Lista<Stack<int>>*);

	virtual ~Integer();
	virtual Integer& operator=(const Integer&);
	virtual Integer& operator+(const Integer&);
	//virtual Integer& operator==(const Integer&);
	//Integer(const Integer& orig);
	//    virtual Integer* sumar(Integer*objeto);
	//    virtual Integer* restar(Integer*);
	//    virtual Integer* division(Integer*);
	//    virtual Integer* multiplicacion(Integer*);	
	//    virtual Integer& operator*(const Integer&);
	//    virtual Integer& operator/(const Integer&);    
	//  virtual Integer* operator-(const Integer&);
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
	virtual void setLista(Lista<Stack<int>>*);
	virtual Lista<Stack<int>>* getLista();
	virtual string toString()const;

	//Mas metodos...
	int calcularNumeroOptimoDeRanuras(int _tam);
	int calcularNumeroOptimoDeStacks(int _tam);
	string getDetalles();
	string getValor()const;
private:
	Lista<Stack<int>>* _lista;
	string _valor;
};

