#ifndef SALIDA_SVG_HPP
#define SALIDA_SVG_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>


#include "Poligonal.h"
#include "Punto.h"

using namespace std;


class SalidaSVG {


public:

	SalidaSVG(string sarchivo);

	void imprimePoligonales(vector<Poligonal>& vPol); 

	virtual ~SalidaSVG();

private:

	string sarchivo;
	ofstream fssal;

	int presicion;

	void abreArchivo();

	void cierraArchivo();


	void imprimePoligonal(Poligonal& Pol);


	bool checaIgD(double d1,double d2);
};




#endif