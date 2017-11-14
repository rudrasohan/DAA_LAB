#include<bits/stdc++.h>
using namespace std;
#define s 6

int Find_Min(int d[],bool v[])
{
	int min_d = INT_MAX,min_p=0;
	for(int i=0;i<s;i++)
	{
		if(!v[i] && d[i]<min_d)
			min_d = d[i],min_p=i;
	}
	cout <<min_p<<endl;

	return min_p;
}

void printPath(int parent[], int j)
{

    if (parent[j]==-1)
        return;
 
    printPath(parent, parent[j]);
 
    printf("%d ", j);
}
 

int printSolution(int dist[], int parent[],int src)
{
    
    printf("Vertex\t  Distance\tPath");
    for (int i = 0; i < s; i++)
    {
    	if(dist[i]<50 && dist[i]>=0)
    	{ 
    	printPath(parent, i);
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        }
    }
}



void Dijkstras(int mat[s][s], int src)
{
	int dist[s];
	bool visit[s];
	 int parent[s];
	 parent[src] = -1;
	fill_n(dist,s,INT_MAX);
	fill_n(visit,s,false);
	fill_n(parent,s,-1);
	dist[src] = 0;
	for(int i=0;i<s-1;i++)
	{
		int cur = Find_Min(dist,visit);
		visit[cur] = true;
		
		for(int j = 0;j<s;j++)
		{
			if(mat[cur][j]&&!visit[j]&&(dist[j]>(mat[cur][j]+dist[cur])))
			{
				dist[j]=(mat[cur][j]+dist[cur]);
				parent[j]  = cur;
				}
		}
	}
	printSolution(dist,parent,src);
}

int main()
{
	int mat[s][s] = {{0,4,8,6,0,0},
					{0,0,3,0,5,0},
					{0,0,0,0,0,3},
					{0,0,10,0,2,0},
					{0,0,0,0,0,0},
					{0,6,0,0,9,0}};
	
	int node;
	cout <<"Input Starting Node\n";
	cin >>node;				
	Dijkstras(mat,node);
	cout<<endl;
	return 0;
}
