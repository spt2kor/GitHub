#include <iostream>
using namespace std;

void main()
{
	/*
	int x = -5;
	unsigned int y = (unsigned int)x;
	int z = (int)y;

	*/
	int x = -5;
	unsigned int y = x;
	int z = y;
	cout<<"\n x = "<<x;
	cout<<"\n y = "<<y;
	cout<<"\n z = "<<z<<endl;

}
/*

 x = -5
 y = 4294967291
 z = -5
Press any key to continue . . .

*/