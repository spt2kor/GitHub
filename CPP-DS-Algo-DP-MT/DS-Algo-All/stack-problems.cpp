/*
//https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

*/

#include <iostream>
using namespace std;
struct Stack
{
	int arr[10];
	int _top;
	Stack() : _top(-1){}
	void push(int data)
	{
		arr[++_top] = data;
	}
	int pop()
	{
		return arr[_top--];
	}
	int top()
	{
		return arr[_top];
	}

	bool isEmpty()
	{
		return _top == -1;
	}
	void print()
	{
		cout<<"\n Stack Elements are count : "<<(_top+1)<<endl;
		for(int i=0; i< (_top+1); ++i)
			cout<<arr[_top-i]<<endl;
	}
};

//===========================================================

void PushDown(Stack &st , int data)
{
	if(st.isEmpty())
		st.push(data);
	else
	{
		int currTop = st.pop();

		PushDown(st,data);

		st.push(currTop);
	}
}

//===========================================================

void reverse(Stack &st)
{
	if( st.isEmpty())
		return;
	else
	{
		int data = st.pop();
		reverse(st);
	
		PushDown(st, data);
	}
}


//===========================================================
void ReverseStackHelper()
{
	cout<<"\n Reverse the Stack :"<<__FUNCTION__<<endl;
	Stack st;
	//cout<<"\n stack empty : "<<( st.isEmpty()? "TRUE" : "FALSE" )<<endl;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	cout<<"\n current Stack "<<endl;
	st.print();

	reverse(st);
	cout<<"\n Stack after reversal "<<endl;
	st.print();
	//cout<<"\n stack empty : "<<( st.isEmpty()? "TRUE" : "FALSE" )<<endl;
	//cout<<"\n stack pop : "<< st.pop()<<endl;
	cout<<"\n Program Ended"<<endl;
}
//===========================================================
//===========================================================
//keep greatest element at the top
void InsertInSortedOrder(Stack &st, int data)
{
	if(st.isEmpty()  || (st.top() < data))  
		st.push(data);
	else // (st.top() > data)
	{
		int currTop = st.pop();
		InsertInSortedOrder(st, data);
		st.push(currTop);
	}
}
void SortStack(Stack &st)
{
	if(st.isEmpty())
		return;
	int data = st.pop(); 
	SortStack(st);
	InsertInSortedOrder(st, data);
}
void SortStackHelper()
{
	cout<<"\n Sort the Stack Increasing order:"<<__FUNCTION__<<endl;
	Stack st;
	st.push(10);
	st.push(2);
	st.push(30);
	st.push(4);
	st.push(50);
	st.push(6);
	st.push(60);
	st.push(1);
	cout<<"\n current Stack "<<endl;
	st.print();

	SortStack(st);
	cout<<"\n Stack after sorting "<<endl;
	st.print();
	cout<<"\n Program Ended"<<endl;
}
//===========================================================
//===========================================================
void SortStackUsingTempStack(Stack &st, Stack& temp)
{
	while (!st.isEmpty())
	{
		int data = st.pop();
		if(temp.isEmpty() || ( temp.top() > data))		//build temp stack in decreasing order
			temp.push(data);
		else
		{
			while( (! temp.isEmpty() && (temp.top() < data) ))
			{
				st.push(temp.pop());
			}
			temp.push(data);
		}
	}
	while(! temp.isEmpty())
	{
		st.push(temp.pop());
	}
}

void SortStackUsingAnotherTempStackHelper()
{
cout<<"\n Sort the Stack Increasing order:"<<__FUNCTION__<<endl;
	Stack st; Stack temp;
	st.push(10);
	st.push(2);
	st.push(30);
	st.push(4);
	st.push(50);
	st.push(6);
	st.push(60);
	st.push(1);
	cout<<"\n current Stack "<<endl;
	st.print();

	SortStackUsingTempStack(st, temp);
	cout<<"\n Stack after sorting "<<endl;
	st.print();
	cout<<"\n Program Ended"<<endl;
}
//===========================================================
//===========================================================
void main()
{
	cout<<"\n Program started :Reverse the Stack :"<<__FILE__<<endl;
	//ReverseStackHelper();
	//SortStackHelper();
	SortStackUsingAnotherTempStackHelper();
	cout<<"\n Program Ended"<<endl;
}