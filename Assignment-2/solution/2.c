#include<stdio.h>

long long int factorial(long long int n)
{
	if(n == 0)
		return 1;
	return (n * factorial(n-1));
}

long long int main()
{
	long long int n = 0;
	scanf("%lld", &n);
	long long int fac = factorial(n);
	printf("%lld", fac);
	return 0;
}