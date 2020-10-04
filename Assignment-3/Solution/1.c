#include<stdio.h>
#include<stdlib.h>

void PRINT(int arr[])
{
	int n = arr[0];
	for(int i = 1; i <=n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void INSERTION_SORT(int arr[], int size)
{
	int n = size;
	int key, i;
	for(int j = 1; j < n; ++j)
	{
		key = arr[j];
		i = j - 1;
		while(i >= 0&& arr[i] > key)
		{
			arr[i+1] = arr[i];
			i--;
		}
		
		arr[i+1] = key;	
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int *arr = (int*)malloc(sizeof(int)*(n+1));
	arr[0] = n;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	int comparison = 0;
	comparison = INSERTION_SORT(arr);
	PRINT(arr);
	printf("%d\n",comparison);
	return 0;
}
