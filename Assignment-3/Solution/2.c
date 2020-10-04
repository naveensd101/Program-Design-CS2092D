#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Print(int a[])
{
	int n = a[0];
	for (int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	printf("\n");
	return;
}

int Merge(int a[], int p, int mid, int r)
{
	int n1 = mid - p + 1;
	int n2 = r - mid;

	int *L = (int *)malloc(sizeof(int) * (n1 + 1));
	for (int i = 0, j = p; i < n1; ++i, ++j)
		L[i] = a[j];
	L[n1] = 1009; //sentinal

	int *R = (int *)malloc(sizeof(int) * (n2 + 1));
	for (int i = 0, j = mid + 1; i < n2; ++j, ++i)
		R[i] = a[j];
	R[n2] = 1009; //sentinal

	int compare = 0;
	for (int i = p, Lit = 0, Rit = 0; i <= r;)
	{
		compare++;
		if (L[Lit] <= R[Rit])
			a[i++] = L[Lit++];
		else
			a[i++] = R[Rit++];
	}
	return compare;
}

int MergeSort(int a[], int p, int r)
{
	int compare = 0;
	int compareL = 0;
	int compareR = 0;
	if (p < r)
	{
		int mid = floor((p + r) / 2);
		compareL = MergeSort(a, p, mid);
		compareR = MergeSort(a, mid + 1, r);

		compare = Merge(a, p, mid, r);
	}
	return (compare + compareL + compareR);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int *a = (int *)malloc(sizeof(int) * (n + 1));
	a[0] = n;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	int compare = MergeSort(a, 1, n); //MergeSort(arra, start index, endindex)
	Print(a);
	printf("%d\n", compare);
	return 0;
}
