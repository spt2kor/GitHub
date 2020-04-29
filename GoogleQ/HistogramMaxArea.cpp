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

int main()
{
	cout<<"\n Program Started"<<endl;
	int hist[] = {6,2,5,4,5,1,6};
	int size = 7;
	stack<int> st;
	int area = 0; int maxarea = INT_MIN;
	int top = -1;
	int i= 0;
	while(i<size)
	{
		if(st.empty()  || ( hist[st.top()] <= hist[i] )  )
			st.push(i++);
		else
		{
			top = st.top() ; st.pop();
			if(st.empty())
				area = hist[top] * (i-top);
			else
				area = hist[top] * (i-st.top()-1);
			
			if(area > maxarea)
				maxarea = area;
		}
	}
	while( !st.empty() )
	{
		top = st.top() ; st.pop();
		if(st.empty())
			area = hist[top] * (i-top);
		else
			area = hist[top] * (i-st.top()-1);
		
		if(area > maxarea)
			maxarea = area;
	}
	cout <<"\n max area = "<<maxarea<<endl;
	cout<<"\n Program ended"<<endl;
	return 0;
}
