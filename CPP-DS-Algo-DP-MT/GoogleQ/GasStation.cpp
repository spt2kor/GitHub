//
//  GasStation.cpp
//  GoogleQ
//
//  Created by Shailendra Pratap Singh Rajput on 22/03/19.
//  Copyright © 2019 Shailendra Pratap Singh Rajput. All rights reserved.
//
///https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
//https://www.interviewbit.com/problems/gas-station/
//queue DS

#include <iostream>
#include <vector>
using namespace std;

int findTour(int gas[] , int dist[] , int size)
{
	int f=0 , r=0 , c=0;
	int sum = 0;
	vector<int> fuel(size);
	cout<<"\n fuel arra :: ";
	for(int i=0;i<size;++i)
	{
		fuel[i]=gas[i]-dist[i];
		cout<<"\t"<<fuel[i];
	}
	cout<<endl;
	
	while(c!=size)
	{
		sum+=fuel[r]; c++;			//NOTE: to make constant space, replace fuel[i] >>>   gas[i]-dist[i];
		if(sum >= 0)
			r=(r+1)%size;
		else
		{
			sum= 0; c= 0;
			r=f=(r+1)%size;
			if(f==0)
				return -1;
		}
	}
	
	return f;
}

int main()
{
	cout<<"\n Program started"<<endl;
	/*int gas[] = {6,3,7};
	int dist[]= {4,6,3};
	int start = findTour(gas, dist,3);
	*/
	int gas[] = {7,4,9,2,5,3,2};
	int dist[]= {6,2,10,5,3,5,1};
	int start = findTour(gas, dist,7);
	
	if(start>0)
		cout << "\n found the starting point of tour: " << start << endl;
	else
		cout << "\n no tour possible: " << start << endl;
	cout<<"\n Program ended"<<endl;
	return 0;
}
