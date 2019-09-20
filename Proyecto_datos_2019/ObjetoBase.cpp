#include "ObjetoBase.h"

ObjetoBase::~ObjetoBase() {
}
ObjetoBase* ObjetoBase::leerData(std::ifstream&) {
	return NULL;
}
bool ObjetoBase::operator==(const ObjetoBase& obj) const {
	return this == &obj;
}

ostream& operator<<(ostream& salida, const ObjetoBase& obj) {
	salida << obj.toString();
	return salida;
}