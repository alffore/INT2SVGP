#include "EscalaP.hpp"

using namespace std;

/**
*
*
*/
EscalaP::EscalaP(vector<Poligonal>& vPol, int dimx, int dimy){

	this->vPol=vPol;
	this->dimx=dimx;
	this->dimy=dimy;


	obtenDimPols();

	escalaPoligonales();

}


/**
* @brief Metodo para escalar todas las poligonales 
*/
void EscalaP::escalaPoligonales(){

	for(std::vector<Poligonal>::iterator it=vPol.begin(); it !=vPol.end(); ++it){

		escalaPoligonal(*it);
	}

}


/**
* @brief Metodo que escala la poligonal
*/
void EscalaP::escalaPoligonal(Poligonal & pol){

	vector<Punto> vp=pol.vp;

	for (vector<Punto>::iterator it = pol.vp.begin(); it != pol.vp.end(); ++it) {

		(*it).x=escala *((*it).x - xmin) + corx;
		(*it).y=-escala*((*it).y - ymin) + cory;

    }


}


/**
* @brief Metodo que determina las dimensiones propias de los poligonos y calcula la escala y las correcciones
*/
void EscalaP::obtenDimPols(){

	int cuenta=0;
	

	for(std::vector<Poligonal>::iterator it=vPol.begin(); it !=vPol.end(); ++it){

		obtenDimPol(*it,cuenta);
		cuenta++;
	}


	dimXP=xmax-xmin;
	dimYP=ymax-ymin;

	dimMP=(dimXP<dimYP)?dimYP:dimXP;


	if(dimMP==dimXP){

		escala=dimx/dimXP;

	}else{

		escala=dimy/dimYP;

	}

	corx = (dimx / 2 - escala * ((xmax + xmin) / 2 - xmin));
    cory = (dimy / 2 + escala * ((ymax + ymin) / 2 - ymin));

}


/**
*
*/
void EscalaP::obtenDimPol(Poligonal & pol, int cuenta){
	

	for (vector<Punto>::iterator it = pol.vp.begin(); it != pol.vp.end(); ++it) {
		
		if(cuenta==0){
			xmin=(*it).x;
			ymin=(*it).y;

			xmax=xmin;
			ymax=ymin;
		}


		if((*it).x<xmin)xmin=(*it).x;
		if((*it).y<ymin)ymin=(*it).y;

		if((*it).x>xmax)xmax=(*it).x;
		if((*it).y>ymax)ymax=(*it).y;

	}	


}

