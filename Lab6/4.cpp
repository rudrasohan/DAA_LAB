#include <bits/stdc++.h>

using namespace std;

list<int> *grp;
int size;
int c = 0;


void addEdge(int a,int b)
{
	grp[a].push_back(b);
}

void BFS(int st)
{
	bool visit[size];
	fill_n(visit,size,false);
	list<int> queue;
	visit[st] = true;
	queue.push_back(st);
	while(queue.size())
	{
		int p = queue.front();
		//cout <<p<<" ";
		queue.pop_front();
		list<int> ::iterator i;
		for(i = grp[p].begin();i != grp[p].end(); i++)
		{
			c++;
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
	bool f = false;
	for(int i = 0;i<size; i++)
	{
		BFS(i);
		cout <<c<<endl;
		if(c == size-1)
		{
			f = true;
			break;
		}
		c=0;
	}
	cout <<endl;
	if(f)
		cout <<"Binary tree";
	else
		cout <<"Not a Binary tree";
	cout <<endl;
	return 0;
	}
