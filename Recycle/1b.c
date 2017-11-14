#include <stdio.h>
int n;
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
	pv = arr[high];
	i = low -1;
	for(j = low;j<=high-1;j++)
	{
		if(arr[j]<pv)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[high],&arr[i+1]);
	return i+1;
}

void print(int arr[])
{
	int i;
	for(i=0;i<n;i++)
		printf("%d,",arr[i]);
	printf("\n");
}

void quickSort(int arr[],int low,int high)
{
	if(high>low)
	{
		print(arr);
		int p = partition(arr,low,high);
		quickSort(arr,low,p-1);
		quickSort(arr,p+1,high);
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
	printf("Unsorted Array\n");
	quickSort(arr,0,n-1);
	printf("Sorted Array\n");
	print(arr);
	return 0;
}
