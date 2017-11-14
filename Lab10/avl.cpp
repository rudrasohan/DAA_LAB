#include<bits/stdc++.h>
using namespace std;

struct node
{
	int key;
	struct node *left;
	struct node *right;
	int ht;
};

typedef struct node Node;

int height(Node* a)
{
	if(a == NULL)
		return 0;
	return (a->ht);
}

Node* newNode(int k)
{
	Node* temp = new Node();
	temp->left=temp->right=NULL;
	temp->key = k;
	temp->ht = 1;
	return temp;
}

Node* rightRotate(Node* x)
{
	Node* y = x->left;
	Node* z = y->right;
	y->right = x;
	x->left = z;
	x->ht = max(height(x->left),height(x->right))+1;
	y->ht = max(height(y->left),height(y->right))+1;
	return y;
}

Node* leftRotate(Node* x)
{
	Node* y = x->right;
	Node* z = y->left;
	y->left = x;
	x->right = z;
	x->ht = max(height(x->left),height(x->right))+1;
	y->ht = max(height(y->left),height(y->right))+1;
	return y;
}

int checkBalance(Node* x)
{
	//cout<<"COOL\n";
	if(x == NULL)
		return 0;
	return (height(x->left)-height(x->right));
}

Node* insert(Node* root, int k)
{
	if(root == NULL)
		return newNode(k);
	else if(k>root->key)
		root->right = insert(root->right,k);
	else if(k<root->key)
		root->left = insert(root->left,k);
	else
		return root;
	
	root->ht = max(height(root->left),height(root->right))+1;
	//cout<<"OK\n";
	int bal = checkBalance(root);
	
	if(bal>1 && (root->left)->key > k) //left left
		return (rightRotate(root));
	if(bal<-1 && (root->right)->key < k) //right right
		return (leftRotate(root));
	if(bal>1 && (root->left)->key < k) //left right
	{
			root->left = leftRotate(root->left);
		return (rightRotate(root->left));
	}
	if(bal<-1 && (root->right)->key > k) // right left
	{
			root->right = rightRotate(root->right);
		return (leftRotate(root->left));
	}
	return root;
}
void inorder(Node*root)
{
	if(root != NULL)
	{
		
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}
int main()
{
	int num;
	cout<<"Enter The num of Nodes\n";
	cin>>num;
	Node* root = NULL;
	for(int i=0;i<num;i++)
	{
		int a;
		cin>>a;
		root = insert(root,a);
	}
	cout<<"INORDER==> ";
	inorder(root);
	cout<<endl;
}

