#ifndef POLIGONAL_H
#define POLIGONAL_H


#include <vector>
#include <string>


#include "Punto.h"



using namespace std;

class Poligonal {


public:

	vector<string> vcad;

	vector<Punto> vp;

	Poligonal(vector<Punto> vp,vector<string> vcad);

};


#endif
