/* 
 * File:   GenCU.cpp
 * Author: alfonso
 * 
 * Created on 5 de julio de 2015, 11:04 AM
 */

#include <sstream>

#include "GenCU.h"

GenCU::GenCU(string sarchivo, int campoId) {

    this->sarchivo = sarchivo;
    this->campoId = campoId;

    
}


GenCU::~GenCU() {
}

/**
 * 
 * @param vPol
 */
void GenCU::generaCUPol(vector<Poligonal>& vPol) {

    int valor;
    int cuenta;

    for (vector<Poligonal>::iterator it = vPol.begin(); it != vPol.end(); ++it) {


        valor = atoi((it->vcad[campoId]).c_str());

        cuenta = existeCU(valor);
        stringstream ss;
        ss << atoi(it->vcad[3].c_str())*1000 + valor << "-" << cuenta;

        it->sclave_uni = ss.str();
    }
}

/**
 * Método que escribe el archivo con los poligonos duplicadosy su conteo
 */
void GenCU::escribeArchivo() {
    ofstream fssal;
    fssal.open(sarchivo.c_str());


    fssal.close();
}

int GenCU::existeCU(int clave) {

    if (vcla.size() == 0) {
        ClaveU caux(clave);
        vcla.push_back(caux);
        return caux.cantidad;
    }


    for (vector<ClaveU>::iterator it = vcla.begin(); it != vcla.end(); ++it) {
        if (it->clave == clave) {
            it->cantidad++;
            return it->cantidad;
        } else {
            ClaveU caux(clave);
            vcla.push_back(caux);
            return caux.cantidad;
        }
    }

    return 0;
}
