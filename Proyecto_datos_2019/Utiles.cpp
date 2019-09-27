#include "Utiles.h"

int convertirInt(std::string s) {
	std::stringstream r(s);
	int v;
	r >> v;
	return v;
}
double convertirDouble(std::string s) {
	std::stringstream r(s);
	double v;
	r >> v;
	return v;
}
int convertirCharaInt(char s) {
	std::stringstream r(s);
	int v;
	r >> v;
	return v;
}

int removerPrimerDigito(int n)
{
	if (n < 10) return 0;
	else return n % 10 + removerPrimerDigito(n / 10) * 10;
}

//int calcularNumeroOptimoDeStacks(int size)
//{
//	float valor = 0;
//	float _vec[5];
//	int pos = 0;
//	_vec[0] = (float) (size / _MAXNUMPERSTACK_)/_STACKMAXSIZE_;
//	_vec[1] = (float)(size / _MAXNUMPERSTACK_) / _STACKMEDIUMPLUSIZE_;
//	_vec[2] = (float)(size / _MAXNUMPERSTACK_) / _STACKMEDIUMSIZE_;
//	_vec[3] = (float)(size / _MAXNUMPERSTACK_) / _STACKMEDIUMLOWSIZE_;
//	_vec[4] = (float)(size / _MAXNUMPERSTACK_) / _STACKMINSIZE;
//	for(int i=0;i<5;i++){
//		if ((_vec[i] - (int)_vec[i]) > valor) {
//			valor = _vec[i] - (int)_vec[i];
//			pos = i;
//		}
//	}
//	return pos;
//}
