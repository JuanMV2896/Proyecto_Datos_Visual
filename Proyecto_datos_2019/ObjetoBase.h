#pragma once
#include <iostream>
#include <sstream>
#include <exception>
//#include "Utiles.h"
using namespace std;
//Definicion de excepciones
static bool _acarreo_ = false;
#define _nullPointerException_ "nullPointerException"
#define _fullStackException_ "fullStackException"
#define _canNotOverrideException_ "canNotOverride"
#define _objectOverflow_ "objectOverflow"
class ObjetoBase {
public:
	virtual ~ObjetoBase();
	static ObjetoBase* leerData(std::ifstream&);
	virtual bool operator==(const ObjetoBase&) const;
	virtual std::string toString() const = 0;
};
std::ostream& operator<<(std::ostream&, const ObjetoBase&);