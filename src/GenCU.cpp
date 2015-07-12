/* 
 * File:   GenCU.cpp
 * Author: alfonso
 * 
 * Created on 5 de julio de 2015, 11:04 AM
 */

#include <sstream>

#include "GenCU.h"

/**
 * 
 * @param sarchivo
 * @param campoId
 */
GenCU::GenCU(string sarchivo, int campoId) {

    this->sarchivo = sarchivo;
    this->campoId = campoId;

}

GenCU::~GenCU() {
}

/**
 * 
 * @param pvPol
 */
void GenCU::generaCUPol(vector<Poligonal>* pvPol) {
    cout << "DEBUG: generaCUPol"<<endl;
    int valor;
    int cuenta;

    for (vector<Poligonal>::iterator it = pvPol->begin(); it != pvPol->end(); ++it) {       
        
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

    for (vector<ClaveU>::iterator it = vcla.begin(); it != vcla.end(); ++it) {
        fssal << it->clave << "|" << it->cantidad << endl;
    }

    fssal.close();
}

/**
 * Metodo que determina si existe una clave regresando la posición acumulada de la actual clave, en su caso crea al objeto ClaveU
 * @param clave
 * @return La cantidad de veces que exite la clave
 * @see ClaveU
 */
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
        }
    }

    ClaveU caux(clave);
    vcla.push_back(caux);
    return caux.cantidad;
}
