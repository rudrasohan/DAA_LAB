#include <iostream>
#include <stdio.h>
using namespace std;

struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* NewNode(int data) 
{
	Node* temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

Node* insert(Node* root,int data)
{
	if(root == NULL)
	{
		root = NewNode(data);
	}
	else if(root->data >= data)
	{
		root->left = insert(root->left,data);	
	}
	else
	{
		root->right = insert(root->right,data);	
	}
	return root;
}

void printt(Node* root)
{
	if(root == NULL)
		return;
	printt(root->left);
	printf("%d ",root->data);
	printt(root->right);
	
}

int main()
{
	int n;
	cin >>n;
	int i,val;
	cout <<"Enter The Elements\n";
	Node* root = NULL;
	for(i = 0;i<n;i++)
	{
		cin >>val;
		root = insert(root,val);
	}	
	printt(root);
	return 0;
}
