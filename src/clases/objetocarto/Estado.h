#ifndef ESTADO_H
#define ESTADO_H


class Estado : public Poligonal{

public:
	string sEstado;
	string sid;
	int id;

/**
*
*/
Estado(string snombre,int id,int x[],int y[], int npuntos): Poligonal(x,y,npuntos){

	this->sEstado=snombre;
	this->id=id;
	sid="";
}

private:

/**
*
*/
	string generaSID(){
		string saux="edo_"+string(itoa(this->id));
		return saux;
	}

};

#endif
