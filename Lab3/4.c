#include <stdio.h>

int n;

void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
} 

void max_heapify(int arr[],int i,int n)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int largest = i;
	if(l<n && arr[largest]<arr[l])
		largest = l;
	if(r<n && arr[largest]<arr[r])
		largest = r;
	if(largest != i)
	{
		swap(&arr[largest],&arr[i]);
		max_heapify(arr,largest,n);
	}
}

void heap_sort(int arr[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	{
		max_heapify(arr,i,n);
	}
	for(i = n-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		max_heapify(arr,0,i);
	}
}

void print(int arr[])
{
	int i;
	for(i=0;i<n;i++)
		printf("%d,",arr[i]);
	printf("\n");
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
	print(arr);
	heap_sort(arr,n);
	printf("Sorted Array\n");
	print(arr);
	return 0;
}
