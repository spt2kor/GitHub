//
//  SortedListToTreeBottomUp.cpp
//  GoogleQ
//
//  Created by Shailendra Pratap Singh Rajput on 27/03/19.
//  Copyright © 2019 Shailendra Pratap Singh Rajput. All rights reserved.
//


#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TNode{
	char data;
	TNode* left;
	TNode* right;
	TNode(char d):data(d),left(nullptr), right(nullptr){}
};

struct LNode{
	char data;
	LNode* next;
	LNode(char d):data(d),next(nullptr){}
};
//======================================================================

void printInorder(TNode* root)
{
	if(!root)	return;
	stack<TNode*> st;
	
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
void PrintLinkList(LNode* head)
{
	if(! head)	return;
	while( head)
	{
		cout<<"\t"<<head->data;
		head = head->next;
	}
}

//======================================================================

TNode* ConvertLToT(LNode* &head, int s, int e)
{
	//if(!head)	return nullptr;
	
	if(s>e)
		return nullptr;
	
	int mid = s + (e-s)/2;
	
	TNode* parent = new TNode('X');
	
	parent->left = ConvertLToT(head, s , mid-1);
	
	parent->data = head->data;
	
	head = head->next;
	
	parent->right = ConvertLToT(head, mid+1 , e);
	
	return parent;
}
TNode* ConvertSortedListToTree(LNode* head)
{
	if(!head)	return nullptr;
	LNode* temp = head;
	int count = 0;
	while(temp)	{	++count; temp = temp->next;
	}
	cout<<"\n total elements in list :"<<count<<endl;
	return ConvertLToT(head, 0 , count-1);
}
//======================================================================

//======================================================================
int main()
{
	cout<<"\n Program started : TREE to DLL "<<endl;
	LNode* a = new LNode('A');
	LNode* b = new LNode('B');
	LNode* c = new LNode('C');
	LNode* d = new LNode('D');
	LNode* e = new LNode('E');
	LNode* f = new LNode('F');
	LNode* g = new LNode('G');
	
	LNode* head = d;
	d->next = b; b->next = e; e->next = a; a->next = f;
	f->next = c;
	c->next = g;
	
	cout<<"\n print sorted ListL= "<<endl;
	PrintLinkList(head);
	
	TNode* root = ConvertSortedListToTree(head);
	
	cout<<"\n print Tree  Inorder= "<<endl;
	printInorder(root);
	
	cout<<"\n Program ended : "<<endl;
}

