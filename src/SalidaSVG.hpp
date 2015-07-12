#ifndef SALIDA_SVG_HPP
#define SALIDA_SVG_HPP

#include <string>
#include <iostream>
#include <sstream> 
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

    SalidaSVG(string sarchivo,int ce);

    void imprimePoliPathCB(vector<Poligonal>& vPol);

    void imprimePoliPathL(vector<Poligonal>& vPol);

    virtual ~SalidaSVG();

private:

    string sarchivo;
    ofstream fssal;

    int precision;

    int ce;
    
    void abreArchivo();

    void cierraArchivo();


    void imprimePoligonoPathCB(Poligonal& Pol);

    void imprimePoligonoPathL(Poligonal& Pol);

    bool checaIgD(double d1, double d2);
};




#endif