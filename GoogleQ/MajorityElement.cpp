//
//  MajorityElement.cpp
//  GoogleQ
//
//  Created by Shailendra Pratap Singh Rajput on 22/03/19.
//  Copyright © 2019 Shailendra Pratap Singh Rajput. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool checkMajor(int arr[] , int size, int no)
{
	int c=0; int mid = size/2;
	for(int i=0;i<size;++i)
	{
		if(arr[i] == no)
		{
			c++;
			if(c > mid)
				return true;
		}
	}
		
	return false;
}
int findMajor(int arr[] , int size)
{
	int maj = 0;

	int c = 1;
	for(int i=1;i<size; ++i)
	{
		if( arr[i] == arr[maj])
			++c;
		else
			--c;

		if(c==0)	{maj = i;c=1;}
	}
	return maj;
}
int main()
{
	cout<<"\n Program started"<<endl;
	//int arr[] = {2,2,1,2,3,2,1,2,3,2,1}; int size = 11;
	
	int arr[] = {2,2,1,2,3,2,1,4,3,2,1}; int size = 11;
	
	int maj = findMajor(arr, size);
	int check = checkMajor(arr,size,arr[maj]);
	
	if( (maj >= 0) && check )
		cout<<"\n found major : "<<arr[maj]<< ", check ="<<check<<endl;
	else
		cout<<"\n  major not possible: "<<maj<< ", check ="<<check<<endl;
	
	cout<<"\n Program ended"<<endl;
	return 0;
}
