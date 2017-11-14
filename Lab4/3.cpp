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
int lca(Node* root, int n1, int n2)
{
	if (root == NULL) 
		return -9999;
        if (root->data > n1 && root->data > n2)
                return lca(root->left, n1, n2);
        if (root->data < n1 && root->data < n2)
                return lca(root->right, n1, n2);
 
        return root->data;
}
int main()
{
	int n,n1,n2;
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
	cout <<"\nEnter two numbers\n";
	cin >>n1>>n2;
	int k = lca(root,n1,n2);
	cout <<"LCA = ";
	cout <<k<<endl;
	return 0;
}
