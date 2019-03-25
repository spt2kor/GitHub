//
//  TreeDiameter.cpp
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

int GetHeightRec(Node* root)
{
	int h = 0;
	
	if( root )
		h= 1+ Max( GetHeightRec(root->left) , GetHeightRec(root->right) );
	
	return h;
}
//======================================================================
int GetDiameter(Node* root , int & maxd)
{
	int d = 0;
	if(!root)
		return d;
	int lh = GetHeightRec(root->left);
	int rh = GetHeightRec(root->right);
	
	int ld = GetDiameter(root->left,maxd);
	int rd = GetDiameter(root->right,maxd);
	
	d = lh+rh+1;
	
	maxd = max(max(ld,rd) , max(maxd,d) );
	return d;
}
//======================================================================
void PrintAllPathRec(Node* root,vector<char>& v,int p)
{

	v.push_back( root->data);
	if(root->left)
		PrintAllPathRec(root->left , v , p+1);
	
	if(root->right)
		PrintAllPathRec(root->right , v , p+1);
	
	if(!root->left && !root->right)	{
		for(auto a : v) cout<<"\t "<< a;
		cout<<endl;
	}
	v.erase(v.end()-1);
}

void PrintAllPath(Node* root)
{
	if(root==NULL)
		return;
	vector<char> v;
	PrintAllPathRec(root,v,0);
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
	
	
	int height = GetHeightRec(root);
	cout<<"\n Height of tree rec = "<<height<<endl;
	int dia = INT_MIN;
	GetDiameter(root,dia);
	cout<<"\n Diameter of tree = "<<dia<<endl;
	
	cout<<"\n PrintAll Path = "<<endl;
	PrintAllPath(root);
	cout<<"\n Program ended : "<<endl;
}
