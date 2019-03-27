//
//  DLLToTree.cpp
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
	Node* prev;
	Node* next;
	Node(char d):data(d),prev(this), next(this){}
};

//======================================================================
void printPostorder(Node* root)
{
	if(!root)	return;
	stack<Node*> st;
	Node* prev = nullptr;
	while(1)
	{
		while(root)
		{
			st.push(root);
			root = root->prev;
		}
		if(st.empty())	break;
		
		root = st.top();
		if(root->next == nullptr || root->next == prev)
		{
			cout<<"\t"<<root->data;
			prev = root;
			st.pop(); root = nullptr;
			
		}
		else
		{
			prev = root;
			root = root->next;
		}
	}
}
void printPreorder(Node* root)
{
	if(!root)	return;
	stack<Node*> st;
	
	while(1)
	{
		while(root)
		{
			cout<<"\t "<<root->data;
			st.push(root);
			root = root->prev;
		}
		if(st.empty())	break;
		
		root = st.top() ; st.pop();
		root = root->next;
	}
}

void printInorder(Node* root)
{
	if(!root)	return;
	stack<Node*> st;
	
	while(1)
	{
		while(root)
		{
			st.push(root);
			root = root->prev;
		}
		if(st.empty())	break;
		
		root = st.top() ;	st.pop();
		cout<<"\t"<<root->data;
		
		root = root->next;
	}
}
void PrintDLL(Node* head)
{
	if(! head)	return;
	cout<<"\t"<<head->data;
	Node* temp = head->next;
	while(temp != head)
	{
		cout<<"\t"<<temp->data;
		temp = temp->next;
	}
}
//======================================================================
Node* AddTwoList(Node* alist, Node* blist)
{
	if(!alist)	return blist;
	if(!blist)	return alist;
	
	Node* aend = alist->prev;
	Node* bend = blist->prev;
	
	alist->prev = bend;
	bend->next = alist;
	
	blist->prev = aend;
	aend->next = blist;
	return alist;
}
//======================================================================
Node* FindMid(Node* head, Node** last)
{
	if(!head)	return nullptr;
	//single node
	if(head == head->next)	{ *last = nullptr ; return head;}
	
	//only 2 nodes
	if(head == head->next->next) {	*last = head->next ; return head;}
	
	Node* sp = head;
	Node* fp = head->next;
	
	while( fp->next != head)
	{
		fp = fp->next;
		sp = sp->next;
		if(fp->next == head)	break;
		
		fp = fp->next;
	}
	*last = fp;
	return sp;
}
Node* ConvertDLLToTree(Node* head)
{
	if(!head)	return nullptr;
	if(head == head->next)	{
		head->prev = nullptr ; head->next = nullptr ; return head;
	}
	if(head == head->next->next)	{
		head->prev = nullptr ; head->next->next = nullptr ;
		head->next->prev = nullptr ;return head;
	}
	Node* last = nullptr;
	Node* mid = FindMid (head , &last);
	
	Node* alists = head;
	Node* aliste = mid->prev;
	
	Node* blists = mid->next;
	Node* bliste = last;
	
	alists->prev = aliste;
	aliste->next = alists;
	
	blists->prev = bliste;
	bliste->next = blists;
	
	mid->prev = ConvertDLLToTree(alists);
	mid->next = ConvertDLLToTree(blists);
	return mid;
}
//======================================================================

//======================================================================
int main()
{
	cout<<"\n Program started : TREE to DLL "<<endl;
	Node* a = new Node('A');
	Node* b = new Node('B');
	Node* c = new Node('C');
	Node* d = new Node('D');
	Node* e = new Node('E');
	Node* f = new Node('F');
	Node* g = new Node('G');
	
	Node* head = AddTwoList(AddTwoList(AddTwoList(AddTwoList(AddTwoList(AddTwoList(d , b), e), a), f), c), g);
	cout<<"\n print Tree as DLL= "<<endl;
	PrintDLL(head);

	Node* root = ConvertDLLToTree(head);

	cout<<"\n print Tree  Inorder= "<<endl;
	printInorder(root);
	
	cout<<"\n print Tree  printPreorder= "<<endl;
	printPreorder(root);
	
	cout<<"\n print Tree  printPostorder= "<<endl;
	printPostorder(root);
	
	
	cout<<"\n Program ended : "<<endl;
}
