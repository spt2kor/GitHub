//
//  TreeTraveralNonRecursive.cpp
//  GoogleQ
//
//  Created by Shailendra Pratap Singh Rajput on 24/03/19.
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
//=====================================================

void printInorderRec(Node *root)
{
	if(! root)
		return;
	if(root->left)
		printInorderRec(root->left);
	
	cout<<"\t"<<root->data;
	
	if(root->right)
		printInorderRec(root->right);
}

void printInorderNonRec(Node *root)
{
	if(! root)	return;
	stack<Node*> st;
	while(1)
	{
		while(root)		{
			st.push(root);
			root = root->left;
		}
		if(st.empty())	break;
		root = st.top() ; st.pop();
		cout<<"\t"<<root->data;
		root = root->right;
	}
}

void printInorder(Node *root, int rec = true)
{
	if(! root) 		return;
	else	{
		if(rec == true)		{
			cout<<"\n printInorder recursive=";
			printInorderRec(root);
		}
		else		{
			cout<<"\n printInorderNonRec =";
			printInorderNonRec(root);
		}
	}
	cout<<endl;
}

//=====================================================
void printPreorderNonRec(Node *root)
{
	if(! root)	return;
	stack<Node*> st;
	while(1)	{
		while (root)	{
			cout<<"\t"<<root->data;
			st.push(root);
			root = root->left;
		}
		if(st.empty())	break;
		root = st.top();	st.pop();
		root = root->right;
	}
}
void printPreorderRec(Node *root)
{
	if(! root)
		return;
	
	cout<<"\t"<<root->data;
	if(root->left)
		printPreorderRec(root->left);
	if(root->right)
		printPreorderRec(root->right);
}

void printPreorder(Node *root, int rec = true)
{
	if(! root) 		return;
	else	{
		if(rec == true)		{
			cout<<"\n printPreorder recursive=";
			printPreorderRec(root);
		}
		else		{
			cout<<"\n printPreorderNonRec =";
			printPreorderNonRec(root);
		}
	}
	cout<<endl;
}
//=====================================================
void printPostorderNonRec(Node *root)
{
	if(! root)	return;
	stack<Node*> st;
	Node* prev = nullptr;
	do{
		while (root)	{
			st.push(root);
			root = root->left;
		}
		if(root == NULL && !st.empty())
		{
			root = st.top();
			if(root->right == NULL || root->right == prev )
			{
				cout<<"\t" << root->data;
				st.pop();
				prev = root;
				root = NULL;
			}
			else
				root = root->right;
		}
	}while(!st.empty());
}

void printPostorderRec(Node *root)
{
	if(! root)
		return;
	if(root->left)
		printPostorderRec(root->left);
	if(root->right)
		printPostorderRec(root->right);
	cout<<"\t"<<root->data;
}

void printPostorder(Node *root, int rec = true)
{
	if(! root) 		return;
	else	{
		if(rec == true)		{
			cout<<"\n printPostorder recursive=";
			printPostorderRec(root);
		}
		else		{
			cout<<"\n printPostorderNonRec =";
			printPostorderNonRec(root);
		}
	}
	cout<<endl;
}
//=====================================================
void printLevelOrder(Node* root)
{
	if (! root)
		return;
	queue<Node*> q;
	q.push(root);
	cout<<"\n printLevelOrder = ";
	while(!q.empty())
	{
		root = q.front(); q.pop();
		cout<<"\t"<<root->data;
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	}
}
//=====================================================
//=====================================================
//=====================================================
int main()
{
	cout<<"\n Program Started : Tree Traversal"<<endl;
	Node* root = new Node('A');
	root->left = new Node('B');
	root->right= new Node('C');
	
	root->left->left = new Node('D');
	root->left->right = new Node('E');
	root->right->left = new Node('F');
	root->right->right = new Node('G');
	
	printInorder(root);
	printInorder(root,false);

	printPreorder(root);
	printPreorder(root,false);

	printPostorder(root);
	printPostorder(root,false);
	
	printLevelOrder(root);
	cout<<"\n Program Ended : Tree Traversal"<<endl;
}
/*
void printInorderNonRec(Node *root)
{
	if(! root)
		return;
	stack<Node*> st;
	Node* node = root;
	while(node) {
		if(node->left)		{
			st.push(node);
			node = node->left;
		}
		else
		{
			while(node)
			{
				cout<<"\t"<<node->data;
				if(node->right)
				{
					node = node->right;
					break;
				}
				else
				{
					if(st.empty())
					{
						node = nullptr;
						break;
					}
					node = st.top(); st.pop();
				}
			}
		}
	}
}
*/
