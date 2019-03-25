//
//  TreeLCA.cpp
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
char GetLCA(Node* root,char a, char b)
{
	if(root == NULL) 	return 0;
	char c = root->data;
	
	if(c == a || c == b)
		return c;
	char rl=0, rr=0;
	if(root->left)
		rl = GetLCA(root->left , a, b);
	if(root->right)
		rr = GetLCA(root->right , a, b);
	if(rl && rr)
		return c;
	if(rl)
		return rl;
	if(rr)
		return rr;
	return 0;
}
//======================================================================
int main()
{
	cout<<"\n Program started : TREE Diameter "<<endl;
	Node* root = new Node('A');
	root->left = new Node('B');
	root->right= new Node('C');
	
	root->left->left = new Node('D');
	root->left->right = new Node('E');
	root->right->left = new Node('F');
	root->right->right = new Node('G');
	
	
	char LCA = GetLCA(root, 'B','E');
	cout<<"\n LCA of B, E is = "<<LCA<<endl;
	
	LCA = GetLCA(root, 'C','E');
	cout<<"\n LCA of C, E is = "<<LCA<<endl;
	
	LCA = GetLCA(root, 'D','F');
	cout<<"\n LCA of D, F is = "<<LCA<<endl;
	
	cout<<"\n Program ended : "<<endl;
}
