#include <bits/stdc++.h>

using namespace std;

list<int> *grp;
int size;
int c = 0;
bool visit[50];

void addEdge(int a,int b)
{
	grp[a].push_back(b);
}

void BFS(int st)
{
	
	
	list<int> queue;
	visit[st] = true;
	queue.push_back(st);
	while(queue.size())
	{
		int p = queue.front();
		cout <<p<<" ";
		c++;
		queue.pop_front();
		list<int> ::iterator i;
		for(i = grp[p].begin();i != grp[p].end(); i++)
		{
			if(!visit[*i])
			{
				queue.push_back(*i);
				visit[*i] = true; 
			}
		}
	}
}


int main()
{
	cout <<"Enter the size";
	cin>>size;
	grp = new list<int>[size];
	fill_n(visit,size,false);
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
	int k=0;
	for(int i = 1;i>0; i++)
	{
		BFS(k);
		while(visit[k] && k<size)
			k++;
		if(k == size)
			break;
	}
	cout <<endl;
	return 0;
	}
