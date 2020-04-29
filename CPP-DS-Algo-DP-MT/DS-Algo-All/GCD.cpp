#include <iostream>
using namespace std;

void FactorsOfNo(int no)
{
	cout<<"\n factors of no : "<<no <<", are : ";
	int check = 1;
	for (int i = 2 ; no>1 ; )
	{
		while (no%i == 0) 
		{
			check *= i;
			cout <<" "<< i;
			no /= i; 
		}
		if(i==2) ++i;
		else i+=2;
	}
	cout<<"\t check = "<<check<<endl;
}

void GCDPrint(int& no1 , int& no2)
{
	cout<<"\n GCDPrint : no1 = "<<no1<<", no2 = "<<no2<<endl;
	FactorsOfNo(no1);
	FactorsOfNo(no2);
	cout<<"\n Devisors are : ";
	while ( (no1%2 == 0) && (no2%2 == 0) )
	{
		cout <<" "<< 2;
		no1 /= 2; 
		no2 /= 2; 
	}
	while (no1%2 == 0)
		no1 /= 2; 
	
	while (no2%2 == 0)
		no2 /= 2; 

	cout<<"\n no's remaining : no1 = "<<no1<<", no2 = "<<no2<<endl;

	cout<<"\n aditional Devisors are : ";
	for (int i = 3 ; no1>1 && no2>1 ; i+=2)
	{
		while ( (no1%i == 0) && (no2%i == 0) )
		{
			cout <<" "<< i;
			no1 /= i; 
			no2 /= i; 
		}
	}
	cout<<"\n======================================================="<<endl;
}

void main()
{
	cout<<"\n Program Started : "<<__FILE__<<endl;
	int no1[5] = {200,543,647,234,984};
	int no2[5] = {247,173,873,789,423};

	for(int i = 0 ; i < 5 ; ++i)
		GCDPrint(no1[i] , no2[i]);




	cout<<"\n Program Ended : "<<__FILE__<<endl;
}