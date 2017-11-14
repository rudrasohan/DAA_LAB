#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define N 6


void mst(int mat[N][N])
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
	for(i = 0;i<N-1;i++)
	{
		int j=0;
		int t = INT_MAX,l;
		for(j = 0;j<N;j++)
		{
			if(m[j] == false && t>d[j])
			{
				t = d[j];
				l = j;
				}
		}
		m[l] = true;
		cout <<l<<endl;
		
		for(j = 0;j < N;j++)
		{
			if(m[j] == false && mat[l][j]<d[j] && mat[l][j])
			{
				d[j] = mat[l][j];
				pv[j] = l;
				//cout <<j<<","<<l<<endl; 
			}
		}
	}
	cout <<"Minimum Spanning Tree =>>"<<endl;
	for(i = 1;i<N;i++)
	{
		cout <<pv[i]<<","<<i<<"=="<<mat[i][pv[i]]<<endl;
	}

}

int main()
{
	
	int mat[N][N] = {{0,8,0,6,4,0},
			   		 {8,0,4,0,7,0},
			   		 {0,4,0,3,0,11},
			         {6,0,3,0,0,8},
			   		 {4,7,0,0,0,0},
			   		 {0,0,11,8,0,0}};
	mst(mat);
	return 0;
}

