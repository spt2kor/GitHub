/*
https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)


length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20
And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20

*/
#include <iostream>
using namespace std;

int RodCutting_Recursion(int price[] ,int start , int n);

void main()
{
	cout<<"\n Program Started "<<__FILE__<<endl;
	int price[] = {1 ,  5,   8,   9,  10,  17,  17,  20};
	int n = 8, start = 1;
	RodCutting_Recursion(price , start , n);
	cout<<"\n Program Ended"<<endl;
}

//==================================================
int RodCutting_Recursion(int price[] ,int start , int n)
{
	if(n<1)
		return 0;
	else
	{
		int current_max = 0;
		int curr_price = price[n] + RodCutting_Recursion(price , n-start , n-1);
		curr_price = price[n] ;

	}
}
