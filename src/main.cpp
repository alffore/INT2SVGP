#include <iostream>

#include <cstdlib>
#include <vector>
#include <math>


#include "Poligonal.h"
#include "LectorINT.h"
#include "EscalaP.hpp"



using namespace std;



int main(int argc, char *argv[]){
	
vector<Poligonal> vPol;
int c1=0;
int c2=0;

int dimx=0;
int dimy=0;


if (argc < 3) {

        cout << "Falta lista con archivo a procesar: polígonos-INT c1 c2 dimx dimy" << endl;
        return 1;
}

c1=atoi(argv[2]);
c2=atoi(argv[3]);
dimx=atoi(argv[4]);
dimy=atoi(argv[5]);


cout << "Archivo INT: "<< argv[1]<<endl;

LectorINT lint(string(argv[1],c1,c2), vPol);


return 0;
}

