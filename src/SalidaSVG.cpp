#include "SalidaSVG.hpp"

using namespace std;

/**
 *
 */
SalidaSVG::SalidaSVG(string sarchivo) {


    this->sarchivo = sarchivo;

    precision = 0;

    abreArchivo();

}

/**
 *
 */
void SalidaSVG::imprimePoliPathCB(vector<Poligonal>& vPol) {

    for (vector<Poligonal>::iterator it = vPol.begin(); it != vPol.end(); ++it) {
        imprimePoliPathCB(*it);
    }

}

void SalidaSVG::imprimePoliPathL(vector<Poligonal>& vPol) {

    for (vector<Poligonal>::iterator it = vPol.begin(); it != vPol.end(); ++it) {
        imprimePoliPathL(*it);
    }

}

/**
 * 
 * @param Pol
 */
void SalidaSVG::imprimePoliPathCB(Poligonal& Pol) {

    int cuenta = 0;

    double xa = 0;
    double ya = 0;
    //	double x0=0;
    //	double y0=0;

    for (vector<Punto>::iterator itp = Pol.vp.begin(); itp != Pol.vp.end(); ++itp) {

        if (cuenta == 0) {

            xa = (*itp).x;
            ya = (*itp).y;

            //			x0=xa;
            //			y0=ya;

            fssal.precision(precision);

            int clave = atoi(Pol.vcad[3].c_str())*1000 + atoi(Pol.vcad[4].c_str());

            fssal << "\"" << clave << "\":\"";

            fssal << "M " << fixed << xa << "," << ya << " C";

        }

        if (!checaIgD(xa, (*itp).x) || !checaIgD(ya, (*itp).y)) {

            fssal << " " << ((*itp).x) << "," << ((*itp).y);

            xa = (*itp).x;
            ya = (*itp).y;

        }

        cuenta++;

    }


    if (cuenta > 0) {
        fssal << " z\"," << endl;
    }


}

void SalidaSVG::imprimePoliPathL(Poligonal& Pol) {

    int cuenta = 0;

    double xa = 0;
    double ya = 0;


    for (vector<Punto>::iterator itp = Pol.vp.begin(); itp != Pol.vp.end(); ++itp) {

        if (cuenta == 0) {

            xa = (*itp).x;
            ya = (*itp).y;

            fssal.precision(precision);

            int clave = atoi(Pol.vcad[3].c_str())*1000 + atoi(Pol.vcad[4].c_str());

            fssal << "\"" << clave << "\":\"";

            fssal << "M " << fixed << xa << " " << ya << " ";

        }

        if (!checaIgD(xa, (*itp).x) || !checaIgD(ya, (*itp).y)) {

            fssal << " L" << ((*itp).x) << " " << ((*itp).y);

            xa = (*itp).x;
            ya = (*itp).y;

        }

        cuenta++;

    }


    if (cuenta > 0) {
        fssal << " z\"," << endl;
    }


}

/**
 *
 */
void SalidaSVG::abreArchivo() {
    fssal.open(sarchivo.c_str());
}

/**
 *
 */
void SalidaSVG::cierraArchivo() {
    fssal.close();
}

/**
 *
 */
SalidaSVG::~SalidaSVG() {
    cierraArchivo();
}

/**
 *
 */
bool SalidaSVG::checaIgD(double d1, double d2) {

    return (round(d1 * pow(10.0, (double) precision)) - round(d2 * pow(10.0, (double) precision)) == 0) ? true : false;

}