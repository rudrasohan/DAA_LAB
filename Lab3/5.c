#include <stdio.h>

int n;

int main()
{
	int i=0,flag=4,cflag = 0;
	printf("Enter size \n");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i = 0;i<(n/2);i++)
	{
	int l = 2*i+1;
	int r = 2*i+2;
	int largest = i;
	//printf("FLAG = %d,CFLAG = %d\n",flag,cflag);
	//printf("l = %d,r = %d\n",arr[l],arr[r]);
	
	if((l<n)&&(r<n))
	{	
		if((arr[largest]<arr[l])&&(arr[largest]<arr[r]))
		flag = 1;
	if((arr[largest]>arr[l])&&(arr[largest]>arr[r]))
		flag = 2;
	if(((arr[largest]>arr[l])&&(arr[largest]<arr[r]))||((arr[largest]<arr[l])&&(arr[largest]>arr[r])))		
		flag = 4;
	}
	if((l<n)&&(r>n))
	{
		if(arr[largest]<arr[l])
		flag = 1;
		if(arr[largest]>arr[l])
		flag = 2;
	}	
	if((r<n)&&(l>n))
	{
		if(arr[largest]<arr[r])
		flag = 1;
		if(arr[largest]>arr[r])
		flag = 2;
	}		
	if(i==0)
		cflag = flag;
		
	if(cflag != flag)
	{
		flag = 4;
		break;
	}
	}
	if(flag == 1)
		printf("Min Heapified\n");
	else if(flag == 2)
		printf("Max Heapified\n");
	else
		printf("Not a Binary Heap\n");	
	return 0;
}
