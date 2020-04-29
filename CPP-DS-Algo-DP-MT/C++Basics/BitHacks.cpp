/*
//
http://graphics.stanford.edu/~seander/bithacks.html


*/
#include <iostream>
using namespace std;

template <typename T>
void PrintBits( T no)
{
	cout<<"\n PrintBit : no ="<<no<<" , is : ";
	for(int i = sizeof(no)*8-1 ; i>=0 ; --i)
		cout<<( ( (no>>(i)) & 1 )? "1" : "0");

	cout<<endl;
}
void main()
{
	cout<<"\n Program started"<<__FILE__<<endl;
	int pos = 20;
	int neg = -30;
	
	cout<<"\n abs(neg) = "<< ( (neg>0 ) ? neg : (neg * -1) )<<endl;
	
	int mask = neg>>(sizeof(int)*8 -1);
	PrintBits(mask);
	int abs = (neg +mask) ^ mask;
	cout<<"\n abs(neg) = "<< abs<<endl;
	PrintBits(mask);
	cout<<"\n\n\n\n****\n\n\n\n";
	
	
	cout<<"\n pos = "<<pos<<" - sign = "<<(pos > 0)<<endl;
	PrintBits(pos);												//	PrintBit : no =20 , is : 00000000000000000000000000010100
	cout<<"\n neg = "<<neg<<" - sign = "<<(neg > 0)<<endl;
	PrintBits(neg);												//PrintBit : no =-30 , is : 11111111111111111111111111100010
	PrintBits(neg>>1);											//PrintBit : no =-15 , is : 11111111111111111111111111110001
	PrintBits(neg>>2);											//PrintBit : no =-8 , is : 11111111111111111111111111111000
	PrintBits(neg>>3);											//PrintBit : no =-4 , is : 11111111111111111111111111111100

	cout<<"\n\n\n\n****\n\n\n\n";

	int sign = pos >> (sizeof(int)*8 -1);
	cout<<"\n pos = "<<pos<<" - sign = "<<sign<<endl;
	PrintBits(sign);											//PrintBit : no =0 , is : 00000000000000000000000000000000	

	sign = neg >> (sizeof(int)*8 -1);
	cout<<"\n neg = "<<neg<<" - sign = "<<sign<<endl;
	PrintBits(sign);											//PrintBit : no =-1 , is : 11111111111111111111111111111111
	PrintBits(sign>>6);											//PrintBit : no =-1 , is : 11111111111111111111111111111111
	PrintBits(sign>>50);										//PrintBit : no =-1 , is : 11111111111111111111111111111111
	PrintBits(sign>>100);										//PrintBit : no =-1 , is : 11111111111111111111111111111111
	PrintBits(sign>>512);										//PrintBit : no =-1 , is : 11111111111111111111111111111111



	cout<<"\n Program ended"<<__FILE__<<endl;
}







