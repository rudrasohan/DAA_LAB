#include<bits/stdc++.h>

using namespace std;
int knapsack(int w, int W[],int V[],int n)
{
	int sack[n+1][w+1];
	int i,j;
	for(i = 0;i <=n;i++)
	{
		for(j = 0;j<=w;j++)
		{
			if(i ==0 || j ==0)
				sack[i][j] = 0;
			else if(j>=W[i-1])
				sack[i][j] = max((V[i-1] + sack[i-1][j-W[i-1]]), sack[i-1][j]);
			else
				sack[i][j] = sack[i-1][j];
				
		}
	}
	return sack[n][w];
}
int main()
{
	int m;
	cout <<"Enter the length of list=>\t";
	cin >>m;
	int W[m],V[m];
	cout <<"Enter the arrays W/V=>\n";
	for(int i=0;i<m;i++)
		cin>>W[i],cin>>V[i];
	int w;	
	cout <<"Enter the weight of the Knapsack=>\t";
	cin >>w;
	int val = knapsack(w,W,V,m);
	cout <<"Value of the Knapsack=>\t"<<val<<endl;
	return 0;
}
