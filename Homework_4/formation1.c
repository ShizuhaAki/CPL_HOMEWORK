#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    char s[2001] = {0};
    scanf("%s", s);
    int str[2001] = {0};
    for (int i = 0; i < n; i++)
    {
        str[i] = (int)s[i] + 1 - '1';
    }

    for (int i = 1; i < m; i++)
    {
        int str1[2001] = {0};
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                if ((str[j] + str[j + 1]) > 0)
                    str1[j] = 1;
                else
                    str1[j] = 0;
            }
            else if (j == n - 1)
            {
                if (str[j] == 1)
                    str1[j] = 1;
                else
                    str1[j] = 0;
            }
            else
            {
                if (((str[j] + str[j - 1] + str[j + 1]) == 0) || ((str[j] + str[j - 1] + str[j + 1]) == 3) || ((str[j - 1] == 1 && str[j] == 0 && str[j + 1] == 0)))
                    str1[j] = 0;
                else
                    str1[j] = 1;
            }
        }
        for (int k = 0; k < n; k++)
        {
            printf("%d", str1[k]);
            str[k] = str1[k];
        }
        printf("\n");
    }

    return 0;
}