#include<stdio.h>
#include<math.h>
#include<stdlib.h>

long long int Binary(int arr[], int l, int r, int k)
{
	int mid = floor((l+r)/2);
	if(arr[mid] == k)
	{
		while(mid >= 0 && arr[mid-1] == k)
			mid--; 
		return mid;
	}
	if(l > r)
	{
		return -1;
	}
	if(k > arr[mid])	
	{
		return Binary(arr, mid+1, r, k);
	}
	else if (k < arr[mid])
	{
		return Binary(arr, l, mid-1, k);
	}
}

int main()
{
	long long int n = 0;
	scanf("%lld", &n);
	long long int m = 0;
	scanf("%lld", &m);
	int *arr = (int*)malloc(n*sizeof(int));
	for(long long int i = 0; i < n; ++i)
		scanf("%d",&arr[i]);
	int quer = 0;
	while(m--)
	{
		scanf("%d",&quer);
		printf("%lld\n", Binary(arr,0,n-1,quer));
	}
	
	return 0;
}

