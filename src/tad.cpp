#include <iostream>

using namespace std;

#include "tcomplejo.h"

int
main(void)
{
	TComplejo nuevo0 (10,15);
	TComplejo nuevo1 (15,6);
	TComplejo nuevo2 = (nuevo0 * nuevo1);
	cout<<nuevo2.Re()<<","<<nuevo2.Im()<<endl;
	cout<<nuevo2<<endl;
}
