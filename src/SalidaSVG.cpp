#include "SalidaSVG.hpp"

using namespace std;

/**
*
*/
SalidaSVG::SalidaSVG(string sarchivo){


	this->sarchivo=sarchivo;

	presicion=1;

	abreArchivo();

}



void SalidaSVG::imprimePoligonales(vector<Poligonal>& vPol){

	for(vector<Poligonal>::iterator it=vPol.begin();it!= vPol.end();++it){
		imprimePoligonal(*it);
	}


}



/**
*
*/
void SalidaSVG::imprimePoligonal(Poligonal& Pol){

	int cuenta=0;

	double xa=0;
	double ya=0;

	for(vector<Punto>::iterator itp=Pol.vp.begin(); itp != Pol.vp.end(); ++itp){

		if(cuenta==0){

			xa=(*itp).x;
			ya=(*itp).y;

			fssal.precision(presicion);

			fssal << "\"" << Pol.vcad[4]<< "\":\"";

			fssal<< "M "<< fixed <<xa<<","<<ya<<" C";

		}

		if(!checaIgD(xa,(*itp).x) || !checaIgD(ya,(*itp).y)){

			fssal << " "<<(*itp).x<<","<< (*itp).y;

			xa=(*itp).x;
			ya=(*itp).y;

		}

		cuenta++;

	}


	if(cuenta>0){
		fssal<<" z\""<<endl;
	}


}


/**
*
*/
void SalidaSVG::abreArchivo(){
	fssal.open(sarchivo.c_str());
}


/**
*
*/
void SalidaSVG::cierraArchivo(){
	fssal.close();
}


/**
*
*/
SalidaSVG::~SalidaSVG(){

	cierraArchivo();

}


/**
*
*/
bool SalidaSVG::checaIgD(double d1,double d2){

	return (round(d1*pow(10.0,(double)presicion))-round(d2*pow(10.0,(double)presicion))==0)?true:false;

}