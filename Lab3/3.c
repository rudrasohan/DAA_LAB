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

void build_max_heap(int arr[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	{
		max_heapify(arr,i,n);
	}
	/*for(i = n-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		max_heapify(arr,0,i);
	}*/
}

void print(int arr[])
{
	int i;
	for(i=0;i<n;i++)
		printf("%d,",arr[i]);
	printf("\n");
}

void insert(int arr[])
{
	if(n>=100)
		printf("Overflow!!\n");
	else
	{
		printf("Enter\n");
		scanf("%d",&arr[n]);
		n++;
		build_max_heap(arr,n);
		
	}
}

void delete_at_top(int arr[])
{
	if(n==0)
		printf("Underflow!!");
	int temp = arr[0];
	swap(&arr[0],&arr[n-1]);
	n--;
	build_max_heap(arr,n);
}

void delete_any(int arr[])
{
	printf("Enter the Index\n");
	int ind;
	scanf("%d",&ind);
	arr[ind] = 99999;
	build_max_heap(arr,n);
	delete_at_top(arr);
}

int extract_max(int arr[])
{
	printf("Max=%d\n",arr[0]);
	return arr[0];
}

int main()
{
	int i=0,max;
	printf("Enter size \n");
	scanf("%d",&n);
	int arr[100];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	//printf("Unsorted Array\n");
	print(arr);
	build_max_heap(arr,n);
	//printf("Sorted Array\n");
	print(arr);
	printf("1:Insert\n");
	printf("2:Delete\n");
	printf("3:Extract\n");
	printf("0:Exit\n");
	int choice = 4;
	while(choice != 0)
	{	
		printf("Enter Choice\n");
		scanf("%d",&choice);
		if(choice == 1)
			insert(arr);
		if(choice == 2)
			delete_any(arr);
		if(choice == 3)
			max = extract_max(arr);
		print(arr);
	}
	return 0;
}
