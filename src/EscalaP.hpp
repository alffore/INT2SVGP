#ifndef ESCALAP_HPP
#define ESCALAP_HPP

#include <vector>
#include <string>
#include <math>


using namespace std;


class EscalaP{

private:
	vector<Poligonal> vPol;
	int dimx;
	int dimy;

	void escalaPoligono(Poligonal& pol);


public:
	EscalaP(vector<Poligonal>& vPol, int dimx, int dimy);

};


#endif