#include<bits/stdc++.h>
using namespace std;

int egghit(int e,int f)
{
	int hit[e+1][f+1];
	int res;
	int i,j,x;
	for (i = 1;i<= e;i++)
	{
		hit[i][1] = 1;
		hit[i][0] = 0;
	}
	for (j=1;j<=f;j++)
		hit[1][j] = j;
	for(i = 2;i <=e;i++)
	{
		for(j = 2;j<=f;j++)
		{
			hit[i][j] = INT_MAX;
			for (x = 1; x <= j; x++)
            {
                res = 1 + max(hit[i-1][x-1], hit[i][j-x]);
                if (res < hit[i][j])
                    hit[i][j] = res;
            }
				
		}
	}
	return hit[e][f];
}

int main()
{
	int egg,floor;
	cout <<"Enter the eggs and the floor=>\t";
	cin >>egg>>floor;
	int val = egghit(egg,floor);
	cout <<"Min number of trials=>\t"<<val<<endl;
	return 0;
}
