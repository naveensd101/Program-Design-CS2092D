#include <stdio.h>
int main()
{
	char a[100], b[100];
	scanf("%[^\n]%*c", a);
	scanf("%[^\n]%*c", b);
	int alen = 0;
	for (int i = 0; a[i] != '\0'; ++i)
	{
		alen++;
	}
	int blen = 0;
	for (int i = 0; b[i] != '\0'; ++i)
	{
		blen++;
	}
	if (blen > alen)
	{
		printf("%d\n", -1);
		return 0;
	}
	else
	{
		int isequal = 1;
		for (int i = 0; i <= alen - blen; ++i)
		{
			isequal = 1;
			for (int j = 0; j < blen; ++j)
			{
				if (a[i + j] == b[j])
				{
					if (j == blen - 1)
					{
						printf("%d\n", i);
						i = alen - blen;
						break;
					}
					else
					{
						continue;
					}
				}
				else
				{
					isequal = 0;
					break;
				}
			}
		}
		if (isequal == 0)
			printf("%d\n", -1);
	}
}
