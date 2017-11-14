#include <iostream>
#include <stdio.h>
#include <stdlib.h> 

int count = 0;
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

void K_small(Node* root,int n)
{
	if(root == NULL)
		return;
	K_small(root->left,n);
	if(count == n-1)
	{
		printf("Kth Smallest = %d ",root->data);
		exit;
	}
	count++;
	K_small(root->right,n);
}

int main()
{
	int n,k;
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
	cout <<"Enter the value of k\n";
	cin >>k;
	K_small(root,k);
	cout <<endl;
	return 0;
}
