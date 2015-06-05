#ifndef POLIGONAL_H
#define POLIGONAL_H


#include <vector>
#include <algorithm>

#include "Punto.h"



using namespace std;

class Poligonal {


public:

	vector<Punto> vp;
	int ce;
	int cm;

	Poligonal(vector<Punto> vp);

};


#endif
