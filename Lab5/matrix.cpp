#include <bits/stdc++.h>

using namespace std;

int r;
void create_graph(int **mat,int r1, int c1,int w)
{
	mat[r1][c1] = w;
}
int main()
{
	
	cout <<"Enter the size of rows and columns\n";
	cin >>r;
	int** m = (int**)malloc(r*sizeof(int*));
	for(int i=0;i<r;i++)
	{
		m[i] = (int*)malloc(r*sizeof(int));
	}
	for(int i = 0;i<r;i++)
	{
		for(int j=0;j<r;j++)
			m[i][j] = 0;
	}
	int n;
	cout <<"Enter the number of links\n";
	cin >>n;
	while(n>0)
	{
		cout <<"Enter the  source and the destination\n";
		int src,dst,w;
		cin >>src>>dst>>w;
		create_graph(m,src,dst,w);
		n--;
	}
	for(int i = 0;i<r;i++)
	{
		for(int j=0;j<r;j++)
			cout << m[i][j]<<" ";
		cout <<endl;
	}
	return 0;
}


