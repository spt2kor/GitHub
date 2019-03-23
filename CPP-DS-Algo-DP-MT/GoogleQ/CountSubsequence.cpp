//
//  CountSubsequence.cpp
//  GoogleQ
//
//  Created by Shailendra Pratap Singh Rajput on 23/03/19.
//  Copyright © 2019 Shailendra Pratap Singh Rajput. All rights reserved.
//
//https://www.geeksforgeeks.org/count-distinct-occurrences-as-a-subsequence/

#include <iostream>
#include <vector>
using namespace std;

int rec_count =0;
int CountSS_DP(string & str1,string& str2)
{
	if(str2.empty())
		return 1;
	if(str1.empty()  || (str1.size()<str2.size()) )
		return 0;
	
	size_t r = str2.size()+1;
	size_t c = str1.size()+1;
	vector<vector<int>> dp(r);
	for(int i=0;i<r;++i)
		dp[i] = vector<int> (c);
	
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j)
		{
			rec_count++;
			if(i == 0)
				dp[i][j] = 1;
			else if( j ==0 )
				dp[i][j] = 0;
			else
			{
				dp[i][j] = dp[i][j-1];
				if(str2[i-1] == str1[j-1])
					dp[i][j] += dp[i-1][j-1] ;
			}
		}
	cout<<"\n print DP matrix"<<endl;

	for(int i=0;i<r;++i)
	{
		cout<<endl;
		for(int j=0;j<c;++j)
			cout<<"\t"<<dp[i][j] ;
	}
	cout<<endl<<dp[r-1][c-1]<<endl;
	return dp[r-1][c-1];
}
int CountSS(string & str1, size_t l1, int p1 , string& str2 , size_t l2, int p2, string result)
{
	++rec_count;
	int count = 0;
	if( p2 == l2)
	{
		cout<<"["<<result<<"]"<<endl;
		return 1;
	}
	if( p1 == l1)
	{
		return 0;
	}
	
	if( (l2-p2) > (l1-p1) )
		return 0;
	
	
	
	if(str1[p1] == str2[p2])
	{
		count += CountSS(str1,l1,p1+1,str2,l2,p2+1,result + str1[p1]);
	}
	count += CountSS(str1,l1,p1+1,str2,l2,p2,result + "_");
	return count;
}

int CountSubSeq(string & str1, string& str2)
{
	int count=0;
	size_t l1 = str1.size();
	size_t l2 = str2.size();
	if(l2 ==0)
		return 1;
	if (l1 ==0)
		return 0;
	string result;
	count = CountSS(str1,l1,0,str2,l2,0, result);
	
	return count;
}

int main()
{
	cout<<"\n Program Started"<<endl;
	string str1 = "banana";
	string str2 = "ban";
	
	//string str1 = "geeksforgeeks";
	//string str2 = "ge";

	cout<<"\n str1 = "<<str1<<",  str2 = "<<str2 <<endl;
	int count = CountSubSeq(str1,str2);
	cout<< "\n\n\n count of sequence = "<< count<<"\n recoursive count = "<<rec_count<<endl;
	
	rec_count=0;
	count =CountSS_DP(str1,str2);
	cout<< "\n\n\n count of sequence DP = "<< count <<"\n recoursive count = "<<rec_count<<endl;
	
	cout<<"\n Program Ended"<<endl;
	return 0;
}
