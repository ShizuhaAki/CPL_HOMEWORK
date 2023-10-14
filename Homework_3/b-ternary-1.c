#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int fun(int len, char str[])
{
    for (int i = 0; i < len; i++)
    {
        char ch = str[i];
        if (ch != 'Z' && ch != '1' && ch != '0')
            return -1;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char str[20];
        getchar();
        scanf("%s", str);

        int len = strlen(str);
        int judge = fun(len, str);
        if (judge == -1)
            printf("Radix Error\n");
        else if (judge == 1)
        {
            int answer = 0;
            for (int m = len - 1; m >= 0; m--)
            {
                if (str[m] == '1')
                    answer += pow(3, len - m - 1);
                else if (str[m] == '0')
                    continue;
                else if (str[m] == 'Z')
                    answer -= pow(3, len - m - 1);
            }
            printf("%d\n", answer);
        }
    }

    return 0;
}