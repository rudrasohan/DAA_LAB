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

Node* minNode(Node* root)
{
	if(root->left == NULL)
		return root;
	else
		return minNode(root->left) ;
		
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

Node* Delete(Node* root,int data)
{
	if(root == NULL)
		return root;
	else if(root->data > data)
		root->left = Delete(root->left,data);
	else if(root->data < data)
		root->right = Delete(root->right,data);
	//Now Delete
	else 
	{
		if(root->left == NULL && root->right == NULL)
			{
				delete root;
				root = NULL;
			}
	
		else if(root->left == NULL && root->right != NULL)
			{
				Node *temp = root;
				root = root->right;
				delete temp;
			}
		else if(root->left != NULL && root->right == NULL)
			{
				Node *temp = root;
				root = root->left;
				delete temp;
			}
		else
			{
				Node *temp = minNode(root->right);
				root->data = temp->data;
				root->right = Delete(root->right,temp->data);
			}
	
	}
	return root;
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
	//Node* min = minNode(root);
	//cout <<endl<<min->data<<endl;
	printf("\nEnter the element to delete\n");
	int del;
	cin >>del;
	Delete(root,del);
	printt(root);
	printf("\nEnter the element to insert\n");
	cin >>val;
	root = insert(root,val);
	cout <<endl;
	printt(root);
	cout <<endl;
	return 0;
}
