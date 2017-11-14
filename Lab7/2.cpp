#include <bits/stdc++.h>
using namespace std;
#define N 3


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

void mst()
{
	int pv[N],d[N];
	bool m[N];
	int i;
	for(i = 0;i < N; i++)
	{
		d[i] = INT_MAX;
		m[i] = false;
	}
	pv[0] = -1;
	d[0] = 0;
	cout <<"END"<<endl;
	for(i = 0;i<N-1;i++)
	{
		int j;
		int t = INT_MAX,l;
		for(j = 0;j<N;j++)
		{
			if(m[j] == false && t>d[j])
			{
				t = d[j];
				l = j;
				cout <<l<<endl;
			}
		}
		
		m[l] = true;
		cout <<l<<endl;
		for(int k = 0;k < N; k++)
		{
			cout <<m[k];
		}
		int v1, v2;
		vector<pair<int,int> >::iterator it;
		for (it=adj[l].begin(); it!=adj[l].end(); it++) 
		{
			v1 = it->first;
            v2 = it->second;
            //cout <<v1<<","<<v2<<endl;
            if(m[j] == false && v2<d[j] && v2 != 0)
			{
				d[j] = v2;
				pv[j] = l;
				//cout <<j<<","<<l<<endl; 
			}
			//cout <<"END"<<endl;
            	
		}/*
		for(j = 0;j < N;j++)
		{
			if(m[j] == false && mat[l][j]<d[j] && mat[l][j] != 0) adj[][]
			{
				d[j] = mat[l][j];
				pv[j] = l;
				//cout <<j<<","<<l<<endl; 
			}
		}*/
	}
	
	int v1, v2;
	vector<pair<int,int> >::iterator it;
	cout <<"Minimum Spanning Tree =>>"<<endl;
	for(i = 1;i<N;i++)
	{	
		int v1=0, v2=0;
		//int count = 0;
		//cout <<i<<endl;
		for (it=adj[i].begin(); it!=adj[i].end(); it++) 
		{
			v1 = it->first;
            v2 = it->second;  
            //cout <<i<<","<<v1<<","<<v2<<endl;
			if(v1 == pv[i])
			{
				break; 
				}        	
		}
		cout <<pv[i]<<","<<i<<"=="<<v2<<endl;
	}

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
		create_graph(m,dst,src,w);
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
				//Edge(j,i,m[i][j]);
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
    mst();
	return 0;
}
