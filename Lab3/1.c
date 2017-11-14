#include <stdio.h>

int n;
int count = 0;
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
		count++;
		max_heapify(arr,largest,n);
	}
}

void build_max_heap(int arr[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	{
		max_heapify(arr,i,n);
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
	build_max_heap(arr,n);
	printf("Sorted Array\n");
	print(arr);
	printf("Count=%d\n",count);
	return 0;
}
