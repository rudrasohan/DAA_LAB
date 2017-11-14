#include <bits/stdc++.h>

using namespace std;

int V;   
list<int> *adj;

void Graph(int x)
{
	V = x;
	adj = new list<int>[V];
} 

void Edge(int v, int w)
{
    adj[v].push_back(w); 
}

void BFS(int ele)
{
    
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;

    
    visited[ele] = true;
    queue.push_back(ele);

   
    list<int>::iterator i;

    while(!queue.empty())
    {
        
        ele = queue.front();
        cout << ele << " ";
        queue.pop_front();

        
        for(i = adj[ele].begin(); i != adj[ele].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
	int n,flag=0;
	cout <<"Enter The Graph Size\n";
	cin >>n;
	Graph(n);
	while(!flag)
	{
		cout <<"Enter the  source and the destination\n";
		int src,dst;
		cin >>src>>dst;
		Edge(src,dst);
		cout <<"Continue flag = 0 else 1\n";
		cin >>flag;
	}
	BFS(0);
	return 0;
}

