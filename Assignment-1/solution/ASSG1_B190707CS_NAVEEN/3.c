#include <stdio.h>

int powe(int num1, int num2)
{
	int prod = 1;
	for(int i = 0; i < num2; ++i)
	{
		prod *= num1;
	}
	return prod;
}
int main()
{
	int n = 0;
	scanf("%d",&n);
	int pever = 0;
	int decimal = 0;
	while(n)
	{
		decimal+= (n%10)*powe(2,pever);
		pever++;
		n/=10;
	}
	printf("%d\n",decimal);
	return 0;
}
