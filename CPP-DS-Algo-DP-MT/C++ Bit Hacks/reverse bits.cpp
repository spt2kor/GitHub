#include <iostream>
using namespace std;

template<typename T>
void printBits(T& x)
{
	int len = sizeof(x)*8 ;
	cout<<"\n PrintBits x = "<<x<<" is = ";
	for ( int i = 0 ; i < len ; ++i)
	{
		if( x & 1<<(len-i-1))
			cout<<"1";
		else
			cout<<"0";
	}
	cout<<endl<<endl;
}
int reverseNo(int& x)
{
	int len = sizeof(x)*8;
	int revNo = 0;
	int count= 0;
	for(int i =0 ; i < len ; ++i)
	{
		count++;
		if(x>>i & 1)
		{
			revNo |= ( 1<<(len-i-1) );
		}
		if(x>>i == 0 )
			break;
	}
	cout<<"\n reverseNo - x = "<<x <<", reverseNo = "<<reverseNo <<", count = "<<count<<endl;
	return revNo;
}

//https://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/
unsigned int reverseBits(unsigned int num) 
{ 
    unsigned int count = sizeof(num) * 8 - 1; 
    unsigned int reverse_num = num; 
      
    num >>= 1;  
	int run=0;
    while(num) 
    { 
       reverse_num <<= 1;        
       reverse_num |= num & 1; 
       num >>= 1; 
       count--; 
	   ++run;
    } 
    reverse_num <<= count; 

	cout<<"\n reverseBits - num = "<<num <<", reverse_num = "<<reverse_num <<", run = "<<run<<endl;
    return reverse_num; 
} 

//https://aticleworld.com/5-way-to-reverse-bits-of-an-integer/
unsigned int ReverseTheBits(register unsigned int x)
{
 x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
 x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
 x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
 x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
 
 unsigned int y;
 cout<<"\n ((x & 0xaaaaaaaa) >> 1) = "; printBits( y = ((x & 0xaaaaaaaa) >> 1 ));
 cout<<"\n ((x & 0x55555555) << 1) = "; printBits( y = ((x & 0x55555555) << 1 ));
 cout<<"\n ((x & 0xcccccccc) >> 2) = "; printBits( y = ((x & 0xcccccccc) >> 2 ));
 cout<<"\n ((x & 0x33333333) << 2) = "; printBits( y = ((x & 0x33333333) << 2 ));
 cout<<"\n ((x & 0xf0f0f0f0) >> 4) = "; printBits( y = ((x & 0xf0f0f0f0) >> 4 ));
 cout<<"\n ((x & 0x0f0f0f0f) << 4) = "; printBits( y = ((x & 0x0f0f0f0f) << 4 ));
 cout<<"\n ((x & 0xff00ff00) >> 8) = "; printBits( y = ((x & 0xff00ff00) >> 8 ));
 cout<<"\n ((x & 0x00ff00ff) << 8) = "; printBits( y = ((x & 0x00ff00ff) << 8 ));
 cout<<"\n (x >> 16) = "; printBits( y = (x >> 16));
 cout<<"\n ((x << 16)) = "; printBits( y = (x << 16) );

return((x >> 16) | (x << 16));
 
}

void main()
{
	int x = 245;
	x = INT_MAX;
	//x= 256;
	printBits(x);
	/*{
		int x1 = -5;
		printBits(x1);
		unsigned int y = x1;
		printBits(y);
		int z = y;
		printBits(z);
	}*/
	cout<<"\n**********************************\n";
	int revNo = reverseNo(x);
	cout<<"\n reverse No is , ";
	printBits(revNo);
	/*

	x = INT_MAX;
	x= 256;
	x = 1;
	printBits(x);

	revNo = reverseNo(x);
	cout<<"\n reverse No is , ";
	printBits(revNo);*/
	//====================================
	cout<<"\n**********************************\n";
	revNo = reverseBits(x);
	cout<<"\n reverse No is , ";
	printBits(revNo);
	cout<<"\n**********************************\n";
	revNo = ReverseTheBits(x);
	cout<<"\n reverse No is , ";
	printBits(revNo);
	cout<<"\n**********************************\n";
}



