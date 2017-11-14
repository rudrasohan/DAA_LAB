#include <stdio.h>
int n,k;
void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
} 
int partition(int arr[], int low, int high)
{
	int pv,i,j;
	pv = arr[low];
	i = low;
	for(j = low+1;j<=high;j++)
	{
		if(arr[j]>pv)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[low],&arr[i]);
	return i;
}

void print(int arr[])
{
	int i;
	for(i=0;i<k;i++)
		printf("%d,",arr[i]);
	printf("\n");
}

void quickSelect(int arr[],int low,int high,int k)
{
	if(high>low)
	{	
		int m = partition(arr, low, high);
		if(k<=m)
			quickSelect(arr,low, low+m-1, k);
		else if(k == (m+1))
			return;
		else
			quickSelect(arr,low+m+1, high, k-m-1);
	}
}

int main()
{
	int i=0;
	printf("Enter size \n");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter k\n");
	scanf("%d",&k);
	quickSelect(arr,0,n-1,k);
	printf("Sorted Array\n");
	print(arr);
	return 0;
}
