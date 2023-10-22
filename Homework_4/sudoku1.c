#include <stdio.h>

int main()
{
    int arr[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int check = 1;
    for (int i = 0; i < 9; i++)
    {
        int a1[10] = {0};
        int a2[10] = {0};
        for (int j = 0; j < 9; j++)
        {
            int x1, x2;
            x1 = arr[i][j];
            x2 = arr[j][i];
            if (x1 <= 9)
                a1[x1]++;
            if (x2 <= 9)
                a2[x2]++;
        }
        for (int k = 1; k < 10; k++)
        {
            if (a1[k] != 1 || a2[k] != 1)
            {
                check = 0;
                break;
            }
        }
    }

    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            int a3[10] = {0};
            for (int m = i; m < i + 3; m++)
            {
                for (int n = j; n < j + 3; n++)
                {
                    int x3;
                    x3 = arr[m][n];
                    if (x3 <= 9)
                        a3[x3]++;
                }
            }
            for (int k = 1; k < 10; k++)
            {
                if (a3[k] != 1)
                {
                    check = 0;
                    break;
                }
            }
        }
    }

    if (check == 0)
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
}