#ifndef LECTORINT_H
#define LECTORINT_H

using namespace std;

class LectorINT{


public:
 LectorINT(string sarchivo);


private:

	string sarchivo;

	vector<Poligonal> vPol;

	void lectorINT();

	void parserLINT(string slinea);


};

#endif
