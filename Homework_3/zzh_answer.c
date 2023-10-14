#include <stdio.h>
int main()
{
	int n, k, count = 0;
	scanf("%d %d", &n, &k);
	int survive = n;
	int a[500];
	for (int i = 0; i < n; i++)
	{
		a[i] = 1;
	}
	for (int i = 0;; i++)
	{
		if (i == n)
			i = 0;
		if (survive == 1)
			break;
		if (a[i] == 0)
			continue;
		else
		{
			count++;
			if (count == k)
			{
				a[i] = 0;
				count = 0;
				survive--;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 1)
			printf("%d", i + 1);
	}
	return 0;
}