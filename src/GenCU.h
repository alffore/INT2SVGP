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




using namespace std;

class GenCU {
public:
    GenCU();
    GenCU(const GenCU& orig);
    virtual ~GenCU();
    
    void generaCUPol(vector<Poligonal>& vPol);
    
private:

};

#endif	/* GENCU_H */

