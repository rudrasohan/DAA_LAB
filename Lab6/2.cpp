#include <bits/stdc++.h>

using namespace std;

list<int> *grp;
int size;
int c = 0;
int a[50][50];
 
void addEdge(int a,int b)
{
	grp[a].push_back(b);
}

void DFS_help(int i,int k,bool visit[])
{
	cout <<i<<" ";
	visit[i] = true;
	a[k][i] = 1;
	list<int> ::iterator j;
	for(j = grp[i].begin();j != grp[i].end();j++)
	{
		if(!visit[*j])
		{
			DFS_help(*j,k,visit);
		}
	}
}

void DFS(int i,int k)
{
	bool visit[size];
	fill_n(visit,size,false);
	DFS_help(i,k,visit);
}

int main()
{
	cout <<"Enter the size";
	cin>>size;
	grp = new list<int>[size];
	cout <<"Enter Elements(press 99 99 to exit) "<<endl;
	for(int i=1 ;i>0;i++)
	{
		int a,b; 
		cout <<"Edge(a,b): ";
		cin >>a>>b;
		if (a == 99)
			break;
		cout <<endl;
		addEdge(a,b);
	}
	cout <<"Enter Starting Node:";
	int st;
	cin>>st;
	DFS(st,st);
	cout <<endl;
	for(int i=0 ;i<size;i++)
	{
		
		DFS(i,i);
		cout<<endl;
		c = 0;
	}
	cout <<"Matrix:\n";
	for(int i=0;i<size;i++)
	{
	for(int j = 0;j<size;j++)
		cout <<a[i][j]<<" ";
	cout<<endl;
	}
	
return 0;
}
