#include <stdio.h>

int main()
{
    int n;
    char str[100001] = {'0'};
    scanf("%d ", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &str[i]);
    }

    int k = 0;
    int check[100001] = {0};

    for (int i = 0; i < n; i++)
    {
        int j = n - 1 - i;
        if (str[i] == str[j] && str[i] != '?')
            printf("%c", str[i]);
        else if (str[i] == '?' && str[j] != '?')
            printf("%c", str[j]);
        else if (str[j] == '?' && str[i] != '?')
            printf("%c", str[i]);
        else
        {
            if (i < (n / 2))
            {
                printf("%02d", k);
                check[i] = k;
                k++;
            }
            else
            {
                int m = check[j];
                int s;
                s = 10 * (m % 10) + m / 10;
                printf("%02d", s);
            }
        }
    }
    return 0;
}