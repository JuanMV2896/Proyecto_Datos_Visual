#pragma once
#include"Lista.h"
#include"Stack.h"
#include"ObjetoBase.h"

#define _MAXNUMPERSTACK_ 9

using namespace std;
class Integer : public ObjetoBase{
public:
	//Constructor por defecto
	Integer();
	//Constructor que recibe el numero a almacenar como un string
	//y luego lo va almacenando por partes en la lista<stack<int>>
	Integer(string x);
	//Constructor que recibe una Lista, no se utiliza mucho.
	Integer(Lista<Stack<int>>*);
	//Destructor
	virtual ~Integer();
	//Sobrecarga del operador=
	virtual Integer& operator=(const Integer&);
	//Sobrecarga del operador+
	virtual Integer* operator+(const Integer&);
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

	//Metodos accesores y mutadores
	virtual void setLista(Lista<Stack<int>>*);
	virtual Lista<Stack<int>>* getLista();
	string getValor()const;
	//Metodo toString()
	virtual string toString()const;

	//...Mas metodos...
	//Este metodo se encarga de calcular el numero optimo de ranuras X stack
	int calcularNumeroOptimoDeRanuras(int _tam);
	//Este metodo se encarga de calcular el numero optimo de stacks X Lista
	int calcularNumeroOptimoDeStacks(int _tam);
	//Este metodo se encarga de detallar el desperdicio de memoria en la implementacion
	//de un objeto Integer.
	string getDetalles();
	
private:
	Lista<Stack<int>>* _lista;
	string _valor;
};

