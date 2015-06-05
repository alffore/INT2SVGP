#ifndef ESCALAP_HPP
#define ESCALAP_HPP

#include <vector>
#include <string>
#include <algorithm>
#include <math>


#include "Poligonal.h"
#include "Punto.h"

using namespace std;


class EscalaP{

private:
	vector<Poligonal> vPol;
	int dimx;
	int dimy;

	double dimXP;
	double dimYP;
	double dimMP;

	double escala;

	double corx;
	double cory;

	int obtenDimPol();
	void escalaPoligono(Poligonal& pol);


public:
	EscalaP(vector<Poligonal>& vPol, int dimx, int dimy);

};


#endif