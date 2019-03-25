//
//  TreeVerticalSum.cpp
//  GoogleQ
//
//  Created by Shailendra Pratap Singh Rajput on 25/03/19.
//  Copyright © 2019 Shailendra Pratap Singh Rajput. All rights reserved.
//


#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(char d):data(d),left(nullptr), right(nullptr){}
};

//======================================================================
void GetVerticalSum(Node* root , map<int,int>& m, int pos = 0)
{
	if(root)	{
		auto itr = m.find(pos);
		if(itr == m.end())
			m[pos] = root->data;
		else
			m[pos] += root->data;
		if(root->left)
			GetVerticalSum(root->left , m , pos-1);
		if(root->right)
			GetVerticalSum(root->right , m , pos+1);
	}
}
//======================================================================
int main()
{
	cout<<"\n Program started : TREE Zigzag "<<endl;
	Node* root = new Node(20);
	root->left = new Node(30);
	root->right= new Node(15);
	
	root->left->left = new Node(13);
	root->left->right = new Node(23);
	root->right->left = new Node(34);
	root->right->right = new Node(45);
	
	map<int,int> m;
	GetVerticalSum(root , m);
	cout<<"\n print vertical sum = "<<endl;
	for(auto a: m) cout<<"\t ["<<a.first<<":"<<a.second<<"]";
	
	cout<<"\n Program ended : "<<endl;
}
