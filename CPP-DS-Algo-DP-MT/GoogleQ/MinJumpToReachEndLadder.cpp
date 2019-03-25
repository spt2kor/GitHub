//
//  MinJumpToReachEndLadder.cpp
//  GoogleQ
//
//  Created by Shailendra Pratap Singh Rajput on 24/03/19.
//  Copyright © 2019 Shailendra Pratap Singh Rajput. All rights reserved.
//

#include <iostream>
using namespace std;

int GetMinJump(int arr[] , int size)
{
	int* dp = new int[size+1]{INT_MAX};
	for(int i=1;i<size+1;++i) dp[i] = INT_MAX;
	dp[0]=0;
	for(int i=1 ; i <= size ;++i)
	{
		//cout<<"\n i="<<i<<", a[i]= "<<arr[i]<<", dp[i]="<<dp[i]<<endl;
		
		for( int j = 0 ; j < i ; ++j)
		{
			//cout<<"\n \t\t\t j="<<j<<", a[j]= "<<arr[j]<<", dp[j]="<<dp[j]<<endl;
			if( ( j + arr[j] >= i) && ( dp[i] > dp[j]+1 ) )
			{
				dp[i] = dp[j]+1;
			}
		}
		//cout<<"\n i="<<i<<", a[i]= "<<arr[i]<<", dp[i]="<<dp[i]<<endl;
	}
	//cout<<"\n all dp[]"<<endl;
	//for(int i=0;i<size+1;++i) cout<<"\t "<<dp[i];
	
	return dp[size];
}

int main()
{
	cout<<"\n program stated: minimum jump required"<<endl;
	//int arr[] = {1, 3, 6, 1, 0, 9};
	//int size = 6;
	int arr[] = {2,3,1,1,4};
	int size = 5;
	
	
	int jump = GetMinJump(arr,size);
	cout<<"\n minimum jump required : ="<<jump<<endl;
	
	cout<<"\n program ENDED: minimum jump required"<<endl;
}
