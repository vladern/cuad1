#include <iostream>

using namespace std;

#include "tcomplejo.h"

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
}
