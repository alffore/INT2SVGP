#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>



#include "Poligonal.h"
#include "LectorINT.h"
#include "EscalaP.hpp"
#include "SalidaSVG.hpp"
#include "GenCU.h"

#define SPATH "/home/alfonso/devel/INTS_MEXICO/jsvg/"

using namespace std;


/**
*
*/
int main(int argc, char *argv[]){
		
	//campos y valor para filtro
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


	//leemos el archivo INT 
	cout << "Archivo INT: "<< argv[1]<<endl;

	LectorINT lint(string(argv[1]),c1,c2,cv);

	cout << "Cantidad de poligonos recuperados: "<< lint.vPol.size() << endl;

	//escalamos las poligonales
	EscalaP escala(&lint.vPol,dimx,dimy);

        //identificamos de manera única
        GenCU mgencu(string(SPATH)+string(argv[4])+string(".bdrep"),c2);        
       mgencu.generaCUPol(&lint.vPol);
        mgencu.escribeArchivo();

	//generamos la salida
	SalidaSVG ssvg(string(SPATH)+string(argv[4])+string(".jsvg"));



	//ssvg.imprimePoliPathCB(lint.vPol);
	ssvg.imprimePoliPathL(lint.vPol);



	return 0;
}

