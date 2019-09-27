#include "Integer.h"

Integer::Integer(string valor)
{
	_valor = valor;
	_lista = new Lista<Stack<int>>();
	Stack<int>* _myStack = nullptr;
	int ranuras = calcularNumeroOptimoDeRanuras(valor.length());
	int stacks = calcularNumeroOptimoDeStacks(valor.length());
	for (int i = 0; i < stacks; i++) {
		_myStack = new Stack<int>(ranuras);
		for (int j = 0; j < ranuras; j++) {
			if (valor.length() > 9) {
				_myStack->push(convertirInt(valor.substr(valor.length() - 9, valor.length())));
				valor = valor.substr(0, valor.length() - 9);
			}
			else {
				_myStack->push(convertirInt(valor));
				valor.clear();
			}
		}		
		_lista->agregar(_myStack);
	}
}

 Integer::Integer() :_lista(new Lista<Stack<int>>())
{
}

Integer::Integer(Lista<Stack<int>>* x)
{
	_lista = x;
	_valor = x->obtenerValor(); 
}

Integer::~Integer()
{
	if (!_lista->vacia())
		delete _lista;
}

Integer& Integer::operator=(const Integer& s)
{
	if (this != &s) {
		if (_lista != nullptr) {
			delete _lista;
		}
		_valor = s._valor;
		_lista = s._lista;
	}
	return *this;
}

void Integer::setLista(Lista<Stack<int>>* lista)
{
	_lista = lista;
}

Lista<Stack<int>>* Integer::getLista()
{
	return _lista;
}

Integer* Integer::operator+(const Integer& x)
{
	Integer* _nuevo = nullptr;
	_nuevo = new Integer(*_lista + *x._lista);
	return _nuevo;
}

string Integer::toString() const
{
	stringstream s;
	s << "El objeto declarado tiene: " << endl;
	s << _lista->numElementos() << " elementos en la lista.\n";
	return s.str();
}

int Integer::calcularNumeroOptimoDeRanuras(int size)
{
	float valor = 0;
	float _vec[9];
	int _vecOptimo[9];
	int casosOptimos = 0;
	int pos = 0;
	for (int i = 0; i < 9; i++) {
		_vec[i] = (float)(size / (float)_MAXNUMPERSTACK_) / (float)(i + 1);
	}
	for (int i = 0; i < 9; i++) {
		if ((_vec[i] - (int)_vec[i]) == 0) {
			pos = i;
			_vecOptimo[casosOptimos++] = i;
		}
		if ((_vec[i] - (int)_vec[i]) > valor) {
			valor = _vec[i] - (int)_vec[i];
			pos = i;
		}
	}
	if (casosOptimos != 0)
		return _vecOptimo[casosOptimos - 1] + 1;
	return pos + 1;
}

int Integer::calcularNumeroOptimoDeStacks(int size)
{
	float valor = 0;
	float _vec[9];
	int _vecOptimo[9];
	int casosOptimos = 0;
	int pos = 0;
	for (int i = 0; i < 9; i++) {
		_vec[i] = (float)(size / (float)_MAXNUMPERSTACK_) / (float)(i + 1);
	}
	for (int i = 0; i < 9; i++) {
		if ((_vec[i] - (int)_vec[i]) == 0) {
			pos = i;
			_vecOptimo[casosOptimos++] = _vec[i];
		}
		if ((_vec[i] - (int)_vec[i]) > valor) {
			valor = _vec[i] - (int)_vec[i];
			pos = i;
		}
	}
	if (casosOptimos != 0)
		return _vecOptimo[casosOptimos - 1];
	if ((_vec[pos] - (int)_vec[pos]) == 0)
		return _vec[pos];
	else
		return (int)((_vec[pos] - (_vec[pos] - (int)_vec[pos])) + 1);
}

string Integer::getDetalles() 
{
	int numStacks = calcularNumeroOptimoDeStacks(_valor.length());
	int numRanuras = calcularNumeroOptimoDeRanuras(_valor.length());
	stringstream s;
	s << "El numero con el que se va a trabajar es: \n";
	s << _valor << endl;
	s << "============================================ \n"
		"          Datos de Optimizacion\n"
	 	"==============================================\n";
	s << "Digitos totales del numero: " << _valor.length() << "\n";
	s << "Numero de Stacks utilizados: "<< numStacks <<"\n";
	s << "Numero de ranuras de cada Stack: " << numRanuras << "\n";
	s << "Numero de ranuras TOTALES: " << numStacks * numRanuras << "\n";
	s << "Numero TOTAL de digitos que se pueden guardar: " << numStacks * numRanuras * 9 << endl;
	s << "==============================================\n";
	return s.str();
}

string Integer::getValor() const
{
	return _valor;
}
