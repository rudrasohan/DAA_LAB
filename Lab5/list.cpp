#include <bits/stdc++.h>

using namespace std;

int r;

int V;   
//list<int> *adj;
vector<pair<int, int> > *adj;
void Graph(int x)
{
	V = x;
	adj = new vector<pair<int, int> >[V];
} 

void Edge(int v, int w, int W)
{
    adj[v].push_back(make_pair(w, W));
}


void create_graph(int **mat,int r1, int c1,int w)
{
	mat[r1][c1] = w;
}
int main()
{
	
	cout <<"Enter the size\n";
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
	int n1 = n;
	while(n>0)
	{
		cout <<"Enter the  source and the destination and Weight\n";
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
	Graph(r);
	for(int i = 0;i<r;i++)
	{
		for(int j=0;j<r;j++)
		{
			if(m[i][j] != 0)
				Edge(i,j,m[i][j]);
		}
	}
	int v1, v2;
	 for (int u=0; u<r; u++) {
        cout << "Node u=" << u << " has the following neighbors:\n";
 		vector<pair<int,int> >::iterator it;
        for (it=adj[u].begin(); it!=adj[u].end(); it++) {
            v1 = it->first;
            v2 = it->second;
            cout << "\tNode v=" << v1 << " with edge weight w=" << v2 << "\n";
        }
 
        cout << "\n";
    }
	return 0;
}
