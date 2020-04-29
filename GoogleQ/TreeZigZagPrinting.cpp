//
//  TreeZigZagPrinting.cpp
//  GoogleQ
//
//  Created by Shailendra Pratap Singh Rajput on 25/03/19.
//  Copyright © 2019 Shailendra Pratap Singh Rajput. All rights reserved.
//



#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node{
	char data;
	Node* left;
	Node* right;
	Node(char d):data(d),left(nullptr), right(nullptr){}
};

//======================================================================
void PrintZigZag2Stack(Node* root)
{
	if(root == NULL) 	return ;
	stack<Node*> *curr = new stack<Node*> ();
	stack<Node*> *next = new stack<Node*> ();
	bool leftToright = false;
	
	curr->push(root);
	while(!curr->empty())	{
		root = curr->top();	curr->pop();
		cout<<"\t"<<root->data;
		if(leftToright == true)		{
			if(root->right)	next->push(root->right);
			if(root->left)	next->push(root->left);
		}
		else	{
			if(root->left)	next->push(root->left);
			if(root->right)	next->push(root->right);
		}
		
		if(curr->empty())	{
			leftToright = 1- leftToright;
			swap (curr , next);
		}
	}
}
//======================================================================
void PrintZigZagStackQueue(Node* root)
{
	if (!root)	return;
	
	stack<Node*> st;
	queue<Node*> q;
	bool ltr = false;
	q.push(root);	q.push(NULL);
	
	while(! q.empty())		{
		root = q.front();		q.pop();
		
		if(root)		{
			cout<<"\t"<<root->data;
			if(ltr)		{
				if(root->left)	st.push(root->left);
				if(root->right)	st.push(root->right);
			}
			else		{
				if(root->right)	st.push(root->right);
				if(root->left)	st.push(root->left);
			}
		}
		else	{
			while(! st.empty())	{
				q.push( st.top()); 	st.pop();
				ltr = 1 - ltr;
			}
			if(!q.empty())
				q.push(NULL);
		}
	}
		
}

//======================================================================
int main()
{
	cout<<"\n Program started : TREE Zigzag "<<endl;
	Node* root = new Node('A');
	root->left = new Node('B');
	root->right= new Node('C');
	
	root->left->left = new Node('D');
	root->left->right = new Node('E');
	root->right->left = new Node('F');
	root->right->right = new Node('G');
	
	cout<<"\n print ZigZag 2Stacks= "<<endl;
	PrintZigZag2Stack(root);
	cout<<"\n print ZigZag Stack Queue= "<<endl;
	PrintZigZagStackQueue(root);
	
	cout<<"\n Program ended : "<<endl;
}

