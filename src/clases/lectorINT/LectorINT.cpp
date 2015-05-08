#include <iostream>
#include <fstream>
#include <string>

#include <vector>

#include "LectorINT.h"

using namespace std;

 LectorINT::LectorINT(string sarchivo){
	this->sarchivo=sarchivo;
}

/**
*
*/
void LectorINT::lectorINT(){

string sline;
	ifstream miarch(sarchivo);

	if(miarch.open()){
		while(getline(miarch,sline)){


		}
		miarch.close();
	}else{
		cerr << "Imposible abrir archivo: "<< sarchivo<<endl;
	}

}


