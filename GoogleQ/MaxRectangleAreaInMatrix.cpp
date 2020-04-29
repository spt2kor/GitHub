//
//  HistogramMaxArea.cpp
//  GoogleQ
//
//  Created by Shailendra Pratap Singh Rajput on 21/03/19.
//  Copyright © 2019 Shailendra Pratap Singh Rajput. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

const int R=4;
const int C=4;

void printMatrix(int matrix[][C] , int r1,int c1 , int r2, int c2)
{
	cout<<"\n matrix is : "<<endl;
	for(int i=r1 ; i<= r2; ++i)
	{
		cout<<endl;
		for(int j=c1; j<=c2;++j)
			cout<<"  "<<matrix[i][j];
		
	}
	
}
int getMaxRect(int arr[R] , bool first )
{
	int maxarea = 0; int area=0;
	for ( int i = 0 ; i < R ; ++i )
	{
		if(arr[i] ==1 )
			area += 1;
		else
			area=0;
		
		if(area > maxarea)
			maxarea = area;
	}
	return maxarea;
}

int getMaxRect(int arr[R] )
{
	int maxarea = 0; int area=0;

	stack<int> st;
	int i=0, size=R;
	int top=-1;
	while(i<size)
	{
		if(st.empty() || (arr[st.top()]  <= arr[i]) )
			st.push(i++);
		else
		{
			top = st.top(); st.pop();
			if(st.empty())
				area = arr[top] * (i-top);
			else
				area = arr[top] * ( i - st.top() - 1);
			
			if(area > maxarea)
				maxarea = area;
		}
	}
	
	while (! st.empty() )
	{
		top = st.top(); st.pop();
		if(st.empty())
			area = arr[top] * (i-top);
		else
			area = arr[top] * ( i - st.top() - 1);
		
		if(area > maxarea)
			maxarea = area;
	}
	return maxarea;
}

int main()
{
	cout<<"\n Program Started"<<endl;
	

	int matrix[R][C] = {	{0,1,1,0},
							{1,1,1,1},
							{1,1,1,1},
							{1,1,0,0} };
	printMatrix(matrix,0,0,R-1,C-1);
	
	
	int maxArea = getMaxRect(matrix[0], true);
	cout<<"\n first row max area = "<< maxArea<<endl;
	
	int area=0;
	for(int r=1; r< R ; ++r)
	{
		for(int c=0;c<C;++c)
		{
			if(matrix[r][c] == 1)
				matrix[r][c] += matrix[r-1][c];
		}
		area = getMaxRect(matrix[r]);
		if(area > maxArea)
			maxArea = area;
	}
	cout<<"\n ********* final Max Rectangler area : "<< maxArea<<endl;
	printMatrix(matrix,0,0,R-1,C-1);
	cout<<"\n Program ended"<<endl;
	
	return 0;
}
