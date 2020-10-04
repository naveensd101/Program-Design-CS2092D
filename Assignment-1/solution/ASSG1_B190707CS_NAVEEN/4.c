#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 0 , k = 0;
	scanf("%d %d",&n, &k);
	if(k>n)
	k = k%n;
	int *arr = (int*)malloc(n*sizeof(int));
	for(int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	for(int i = n-k; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	for(int i = 0; i < n-k; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
