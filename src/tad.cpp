#include <iostream>

using namespace std;

#include "tcomplejo.h"
#include "tvectorcom.h"
#include "tlistacom.h"

int
main(void)
{
	TComplejo nuevo0 (10,15);
	TComplejo nuevo1 (15,6);
	TComplejo nuevo2;
	nuevo2 = nuevo0 * nuevo1;
	cout<<nuevo0<<"*"<<nuevo1<<"="<<nuevo2<<endl;
	nuevo2 = nuevo0 + nuevo1;
	cout<<nuevo0<<"+"<<nuevo1<<"="<<nuevo2<<endl;
	nuevo2 = nuevo0 - nuevo1;
	cout<<nuevo0<<"-"<<nuevo1<<"="<<nuevo2<<endl;
	cout<<"arg:"<<nuevo2.Arg()<<endl;
	cout<<"mod:"<<nuevo2.Mod()<<endl;
	TComplejo c1(1,0.5);
	TComplejo c2(3,0.5);
	TVectorCom v1(2);
	v1[1] = c1;
	v1[2] = c2;
	v1.MostrarComplejos(1);
	cout<<v1<<endl;
	cout<<"Pruebas del complejo"<<endl;
	TComplejo c3(1,0.5);
	TListaCom l1;
	if(l1.InsCabeza(c3))
	{
		cout<<"Se ha insertado"<<endl;
	}else
	{
		cout<<"No se ha insertado"<<endl;
	}
	cout << l1;
}
