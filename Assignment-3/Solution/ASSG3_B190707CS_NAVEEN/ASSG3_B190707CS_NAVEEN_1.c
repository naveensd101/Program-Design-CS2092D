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

int INSERTION_SORT(int arr[])
{
	int n = arr[0];
	int comparison = 0;
	int key, i;
	for(int j = 2; j <=n; ++j)
	{
		key = arr[j];
		i = j - 1;
		while(i > 0 && (++comparison ? 1 : 1) && arr[i] > key)
		{
			arr[i+1] = arr[i];
			i--;
		}
		
		arr[i+1] = key;	
	}
	return comparison;
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
