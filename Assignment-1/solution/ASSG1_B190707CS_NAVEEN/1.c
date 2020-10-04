#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int *arr = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n ; i++)
	{
		scanf("%d",&arr[i]);
	}
	int find = 0;
	int flag = 0;
	scanf("%d", &find);
	for(int j = 0; j < n; j++)
	{
		if(find == arr[j])
		{
			flag = 1;
			printf("%d ", j);
		}
	}
	if(flag == 0)
	{
		printf("-1");
	}
	printf("\n");
	return 0;
}
