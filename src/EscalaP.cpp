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

	obtenDimPol();

	escalaPoligonal();

}

/**
*
*/
void EscalaP::escalaPoligonal(Poligonal & pol){

	vector<Punto> vp=pol.vp;

	for (vector<Punto>::iterator it = pol.vp.begin(); it != pol.vp.end(); ++it) {
        
		double xant=(*it).x;
		double yant=(*it).y;




    }


}

/**
*
*/
int EscalaP::obtenDimPol(){

	int cuenta=0;

	double xmin,xmax;
	double ymin,ymax;

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



		cuenta++;

	}	

	dimXP=xmax-xmin;
	dimYP=ymax-ymin;

	dimMP=(dimXP<dimYP)?dimYP:dimXP;



	return cuenta;
}