#include <iostream>

#include <cstdlib>
#include <vector>



#include "Poligonal.h"
#include "LectorINT.h"
#include "EscalaP.hpp"



using namespace std;


/**
*
*/
int main(int argc, char *argv[]){
		
	vector<Poligonal> vPol;
	int c1=0;
	int c2=0;
	int cv;

//dimensiones para el mapa
	int dimx=0;
	int dimy=0;


	if (argc < 3) {

	        cout << "Falta lista con archivo a procesar: polígonos-INT c1 c2 cv dimx dimy" << endl;
	        return 1;
	}

	c1=atoi(argv[2]);
	c2=atoi(argv[3]);

	cv=atoi(argv[4]);
	dimx=atoi(argv[5]);
	dimy=atoi(argv[6]);

	cout << "Archivo INT: "<< argv[1]<<endl;

	LectorINT lint(string(argv[1]), vPol,c1,c2,cv);


	return 0;
}

