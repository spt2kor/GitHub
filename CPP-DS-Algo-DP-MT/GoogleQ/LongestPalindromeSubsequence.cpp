//
//  LongestPalindromeSubsequence.cpp
//  GoogleQ
//
//  Created by Shailendra Pratap Singh Rajput on 22/03/19.
//  Copyright © 2019 Shailendra Pratap Singh Rajput. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int max(int l, int r)
{
	return l>r ? l : r;
}

int LongestPalindrome(string& str)
{
	size_t size = str.size();
	vector< vector<int>> dp(size) ;
	for(int i=0;i<size;++i)
	{
		dp[i] = vector<int>(size);
		dp[i][i] = 1;
	}
	for(int len=2; len<=size ; ++len)
	{
		for( int s=0 ; s<=size-len; ++s)
		{
			int e = s+len -1;
			
			if(str[s] == str[e])
			{
				if(s+1 == e)
					dp[s][e] =  2;
				else
					dp[s][e] = dp[s+1][e-1] + 2;
			}
			else
				dp[s][e] = max(dp[s][e-1],dp[s+1][e]);
		}
	}
	return dp[0][size-1];
}

int main()
{
	cout<<"\n Program started"<<endl;
	string seq = "GEEKS FOR GEEKS";
	
	int size = LongestPalindrome(seq);
	cout<<"\n LongestPalindrome = "<<size <<endl;
	cout<<"\n Program ended"<<endl;
	return 0;
}
