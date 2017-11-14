#include <stdio.h>
int n,count=0;
void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
} 
int merge(int arr[], int low, int mid, int high)
{
	int l1,l2,i,j,k;
	l1 = mid - low + 1;
	l2 = high - mid;
	int L[l1],R[l2];
	i = 0;
	while(i<l1)
	{
		L[i] = arr[i+low];
		i++;
	}
	i = 0;
	while(i<l2)
	{
		R[i] = arr[i+mid+1];
		i++;
	}
	k = low,i=0,j=0;
	while(i<l1)
	{
		while(j<l2)
		{
			if(L[i]>R[j])
				count++;
			j++;
		}
		i++;
		j=0;
	}
	k = low,i=0,j=0;
	while((i<l1)&&(j<l2))
	{
		if(L[i]<R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<l1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j<l2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

}

void print(int arr[])
{
	int i;
	for(i=0;i<n;i++)
		printf("%d,",arr[i]);
	printf("\n");
}

void mergeSort(int arr[],int low,int high)
{
	if(high>low)
	{
		//print(arr);
		int mid = low + (high-low)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
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
	//printf("Unsorted Array\n");
	//print(arr);
	mergeSort(arr,0,n-1);
	printf("COUNT: %d\n",count);
	//print(arr);
	return 0;
}
