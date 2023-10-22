#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char str[1015] = {0};
    scanf("%s", str);
    int len = strlen(str);

    for (int times = 0; times < n; times++)
    {
        char str1[1015] = {0};
        memset(str1, '.', sizeof(str1));
        for (int i = len - 1; i >= 0; i--)
        {
            str[i + 3] = str[i];
        }
        for (int i = 0, j = len + 5; i < 3; i++, j--)
        {
            str[i] = '.';
            str[j] = '.';
        }
        for (int i = 3; i < len + 3; i++)
        {
            int countA = 0;
            int countB = 0;
            if (str[i] == '.')
            {
                for (int j = i - 3; j <= i + 3; j++)
                {
                    if (str[j] == 'A')
                        countA++;
                    else if (str[j] == 'B')
                        countB++;
                }
                if (countA >= 2 && countA <= 4 && countB == 0)
                    str1[i - 3] = 'A';
                else if (countB >= 2 && countB <= 4 && countA == 0)
                    str1[i - 3] = 'B';
            }
            else if (str[i] == 'A')
            {
                int flag = 0;
                for (int j = i - 3; j <= i + 3; j++)
                {
                    if (str[j] == 'B')
                    {
                        str1[i - 3] = '.';
                        flag = 1;
                        break;
                    }
                    else if (str[j] == 'A')
                    {
                        countA++;
                    }
                }
                if (countA - 1 > 1 && countA - 1 < 5 && flag == 0)
                    str1[i - 3] = 'A';
            }
            else
            {
                int flag = 0;
                for (int j = i - 3; j <= i + 3; j++)
                {
                    if (str[j] == 'A')
                    {
                        str1[i - 3] = '.';
                        flag = 1;
                        break;
                    }
                    else if (str[j] == 'B')
                    {
                        countB++;
                    }
                }
                if (countB - 1 > 1 && countB - 1 < 5 && flag == 0)
                    str1[i - 3] = 'B';
            }
        }
        str[len] = '\0';
        strncpy(str, str1, len);
    }
    printf("%s\n", str);
    return 0;
}