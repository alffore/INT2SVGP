#ifndef LECTORINT_H
#define LECTORINT_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>


#include "Poligonal.h"

#define DELIMITER       "|"

using namespace std;


class LectorINT{


public:
 	LectorINT(string sarchivo,vector<Poligonal>& vPol);


private:

	string sarchivo;

	vector<Poligonal> vPol;

	void inicializador(void);
	
	void parser(string scad);

	void split(vector<string>& theStringVector, const string& theString, const string& theDelimiter);
	
	void parserSPunto(vector<Punto>& vP, const string & scad);	

};

#endif
