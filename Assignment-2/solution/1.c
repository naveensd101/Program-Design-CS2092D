#include<stdio.h>

void gcd(int a, int b)//a >= b
{
	a = fabs(a);
	b = fabs(b);
	int temp = max(a,b);
	b = min(a, b);
	a = temp;
	if(b == 0)
	{
		printf("%d", a);
		return;
	}
	int temp = b;
	b = a % b;
	a = temp;
	a >= b ? gcd(a, b) : gcd(b,a);
	return;
}

int main()
{
	int a = 0, b= 0;
	scanf("%d %d",&a,&b);
	if(a < 0)
		a = a*-1;
	if(b < 0)
		b = b*-1;
	if(a == 0 && b==0)
	{
		printf("-1");
		return 1;
	}
	a>=b ? gcd(a,b) : gcd(b,a);
return 0;
}