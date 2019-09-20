#pragma once
#include <iostream>
#include <sstream>
#include <exception>
using namespace std;

class ObjetoBase {
public:
	virtual ~ObjetoBase();
	static ObjetoBase* leerData(std::ifstream&);
	virtual bool operator==(const ObjetoBase&) const;
	virtual std::string toString() const = 0;
};
std::ostream& operator<<(std::ostream&, const ObjetoBase&);