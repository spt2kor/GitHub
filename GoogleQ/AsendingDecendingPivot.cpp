//
//  AsendingDecendingPivot.cpp
//  GoogleQ
//
//  Created by Shailendra Pratap Singh Rajput on 26/03/19.
//  Copyright © 2019 Shailendra Pratap Singh Rajput. All rights reserved.
//
/*
1 ,5, 8, 22 ,4 ,1

35, 24 ,3 ,1, 0, 3, 4


1,20,19,18,17,16
1,2,3,4,5,6,4
1,2,3,4,5,6,7,1,2
'
2,1,2,3,4,5,6,7
,
*/
#include <iostream>
#include <vector>
using namespace std;

int GetPivot(vector<int> & in)
{
	int pivot = -1;
	if(in.size() <=2)
		return -1;
	else
	{
		for( int i=1 ; i<=in.size()-2 ; ++i )
		{
			if(!  (( in[i-1]<in[i] && in[i] < in[i+1]) || ( in[i-1]>in[i] && in[i] > in[i+1]) )  )
				pivot = i;
		}
	}
	return pivot;
}

int GetPivotBin(vector<int> & in)
{
	int pivot = -1;
	if(in.size() <= 2 )
		return -1;
	else
	{
		size_t size = in.size();
		int dir = in[0] < in[1] ? 0 : 1; //0 = =as, 1-des
		
		size_t mid = -1;
		size_t l=0 , r=size-1;
		while(l<r)
		{
			mid = l+r/2;
			if(dir == 0) //l--r
			{
				if ( (in[mid-1]<in[mid]) && (in[mid] < in[mid+1]) )
					l = mid; // mid-r
				else if(( in[mid-1]>in[mid]) && (in[mid] > in[mid+1]))
					r = mid;
				else
					break;
			}
			else
			{
				if(( in[mid-1]>in[mid]) && (in[mid] > in[mid+1]))
					r = mid;
				else if(( in[mid-1]<in[mid]) && (in[mid] < in[mid+1]))
					l = mid;
				else
					break;
			}
		}
		pivot= mid;

	}
	return pivot;
}
int main()
{
	vector<int> in = {1,2,3,4,5,6,7,8,9,1,2};
	int p = GetPivot(in);
	cout<<"\n "<<p<<", in[p] = "<<in[p]<<endl;
	p = GetPivotBin(in);
	cout<<"\n "<<p<<", in[p] = "<<in[p]<<endl;
	
	
	vector<int> in1 = {3,2,1,2,3,4,5,6,7,8,9,10,11};
	p = GetPivot(in1);
	cout<<"\n "<<p<<", in[p] = "<<in1[p]<<endl;
	p = GetPivotBin(in1);
	cout<<"\n "<<p<<", in[p] = "<<in1[p]<<endl;
	
	return 0;
}
						
