//
//  TreeLevelOrderBFS.cpp
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
int Max(int a, int b)
{
	return  a>b? a: b;
	
}

//================================================
void printLevelOrderRev(Node* root)
{
	if(!root)
		return;
	queue<Node*> q;
	stack<Node*> st;
	q.push(root);
	cout<<"\n printLevelOrderRev =  ";
	while(!q.empty())
	{
		root = q.front();   q.pop();
		st.push(root);
		if(root->right)
			q.push(root->right);
		if(root->left)
			q.push(root->left);
	}
	while(!st.empty())
	{
		root = st.top() ; st.pop();
		cout<<"\t "<<root->data;
	}
	cout<<endl;
}

//======================================================================
void printLevelOrder(Node* root)
{
	if(!root)
		return;
	queue<Node*> q;
	q.push(root);
	cout<<"\n printLevelOrder =  ";
	while(!q.empty())
	{
		root = q.front();   q.pop();
		cout<<"\t "<<root->data;
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	}
	cout<<endl;
}
//======================================================================
int GetHeightRec(Node* root)
{
	int h = 0;
	
	if( root )
		h= 1+ Max( GetHeightRec(root->left) , GetHeightRec(root->right) );
	
	return h;
}

int GetHeightNonRec(Node* root)
{
	int h = 0;
	if(! root)
		return h;
	queue<Node*> q;
	q.push(root) ; 	q.push(NULL);
	while(!q.empty())
	{
		root = q.front();	q.pop();
		if(root)
		{
			if(root->left)
				q.push(root->left);
			if(root->right)
				q.push(root->right);
		}
		else
		{
			++h;
			if(! q.empty())	{
				q.push(NULL);
			}
		}
	}
	return h;
}
//======================================================================
int main()
{
	cout<<"\n Program started : TREE BFS traversal"<<endl;
	Node* root = new Node('A');
	root->left = new Node('B');
	root->right= new Node('C');
	
	root->left->left = new Node('D');
	root->left->right = new Node('E');
	root->right->left = new Node('F');
	root->right->right = new Node('G');

	
	printLevelOrder(root);
	printLevelOrderRev(root);
	int height = GetHeightRec(root);
	cout<<"\n Height of tree rec = "<<height<<endl;
	height = GetHeightNonRec(root);
	cout<<"\n Height of tree Non rec = "<<height<<endl;
	
	cout<<"\n Program ended : "<<endl;
}

