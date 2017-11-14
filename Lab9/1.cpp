#include<bits/stdc++.h>

using namespace std;
int longest(char X[],char Y[], int m, int n)
{
	int L[m+1][n+1];
	int i,j;
	for(i = 0;i <=m;i++)
	{
		for(j = 0;j<=n;j++)
		{
			if(i ==0 || j ==0)
				L[i][j] = 0;
			else if(X[i-1] == Y[j-1])
				L[i][j] = 1 + L[i-1][j-1];
			else
				L[i][j] = max(L[i-1][j],L[i][j-1]);
				
		}
	}
	return L[m][n];
	
}
int main()
{
	int m,n;
	cout <<"Enter the length of arrays=>\t";
	cin >>m>>n;
	char X[m],Y[n];
	cout <<"Enter the arrays=>\n";
	for(int i=0;i<m;i++)
		cin>>X[i];
	for(int i=0;i<n;i++)
		cin>>Y[i];
	int lcs = longest(X,Y,m,n);
	cout <<"Length == "<<lcs<<endl;
	return 0;
}
