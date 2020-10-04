#include <stdio.h>
#include <stdlib.h>

void PRINT(int A[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", A[i]);
	printf("\n");
}

int PARTITION(int A[], int p, int r, int *q)
{
	int count = 0;
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; ++j)
	{
		if ((++count ? 1 : 1) && A[j] <= x)
		{
			i++;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	int t = A[i + 1];
	A[i + 1] = A[r];
	A[r] = t;
	(*q) = i + 1;
	return count;
}

int QUICK_SORT(int A[], int p, int r)
{
	int count = 0;
	if (p < r)
	{
		int q = 0;
		count += PARTITION(A, p, r, &q);

		count += QUICK_SORT(A, p, q - 1);
		count += QUICK_SORT(A, q + 1, r);
	}
	return count;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int *arr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	int count = QUICK_SORT(arr, 0, n - 1);
	PRINT(arr, n);
	printf("%d\n", count);
	return 0;
}
