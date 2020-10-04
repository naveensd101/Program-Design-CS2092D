#include<stdio.h>
#include<math.h>
int naveen(int n)
{
	if(n >= 0 && n <= 9)
		return n;
	int dig = n % 10;
	return (dig * (int)pow(10, floor(log10((double)n))) + naveen(n/10));
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", naveen(n));
}
