/* 
 * File:   GenCU.h
 * Author: alfonso
 *
 * Created on 5 de julio de 2015, 11:04 AM
 */

#ifndef GENCU_H
#define	GENCU_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


#include "Poligonal.h"
#include "ClaveU.h"



using namespace std;

class GenCU {
    
    
    
    
public:
    GenCU(string sarchivo,int campoId);

    virtual ~GenCU();
    
    void generaCUPol(vector<Poligonal>& vPol);
    void escribeArchivo();
private:
    string sarchivo;
    int campoId;
   
    
    
    
    int existeCU(int clave);
    
    vector<ClaveU> vcla;
};

#endif	/* GENCU_H */

