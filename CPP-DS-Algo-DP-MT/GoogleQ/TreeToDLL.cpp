//
//  TreeToDLL.cpp
//  GoogleQ
//
//  Created by Shailendra Pratap Singh Rajput on 27/03/19.
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

void printInorder(Node* root)
{
	if(!root)	return;
	stack<Node*> st;
	
	while(1)
	{
		while(root)
		{
			st.push(root);
			root = root->left;
		}
		if(st.empty())	break;
		
		root = st.top() ;	st.pop();
		cout<<"\t"<<root->data;
		
		root = root->right;
	}
}
void PrintDLL(Node* head)
{
	if(! head)	return;
	cout<<"\t"<<head->data;
	Node* temp = head->right;
	while(temp != head)
	{
		cout<<"\t"<<temp->data;
		temp = temp->right;
	}
}
//======================================================================
Node* AddTwoList(Node* alist, Node* blist)
{
	if(!alist)	return blist;
	if(!blist)	return alist;
	
	Node* aend = alist->left;
	Node* bend = blist->left;
	
	alist->left = bend;
	bend->right = alist;
	
	blist->left = aend;
	aend->right = blist;
	return alist;
}

Node* ConvertTreeToDLL(Node* root)
{
	if(!root)	return nullptr;
	
	Node* alist = ConvertTreeToDLL(root->left);
	Node* blist = ConvertTreeToDLL(root->right);
	
	root->left = root;
	root->right = root;
	
	alist = AddTwoList(alist , root);
	alist = AddTwoList(alist , blist);
	
	return alist;
}
//======================================================================
int main()
{
	cout<<"\n Program started : TREE to DLL "<<endl;
	Node* root = new Node('A');
	root->left = new Node('B');
	root->right= new Node('C');
	
	root->left->left = new Node('D');
	root->left->right = new Node('E');
	root->right->left = new Node('F');
	root->right->right = new Node('G');
	
	cout<<"\n print Tree  Inorder= "<<endl;
	printInorder(root);
	
	root = ConvertTreeToDLL(root);
	cout<<"\n print Tree as DLL= "<<endl;
	PrintDLL(root);
	
	cout<<"\n Program ended : "<<endl;
}
