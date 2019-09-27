#pragma once
#include <iostream>
#include <sstream>
#include <exception>
using namespace std;

//Definicion de excepciones
#define ZERO 0
#define ONE 1
#define UNDEFINE -1
#define _nullPointerException_ "nullPointerException"
#define _fullStackException_ "fullStackException"
#define _canNotOverrideException_ "canNotOverride"
#define _objectOverflow_ "objectOverflow"

//VARIABLES GLOBALES
static bool _acarreo_ = ZERO;
static int _sectorDelAcarreo_ = UNDEFINE;

class ObjetoBase {
public:
	virtual ~ObjetoBase();
	static ObjetoBase* leerData(std::ifstream&);
	virtual bool operator==(const ObjetoBase&) const;
	virtual std::string toString() const = 0;
};
std::ostream& operator<<(std::ostream&, const ObjetoBase&);