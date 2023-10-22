#include <stdio.h>
#include <math.h>

int main()
{
    int xa, ya, xb, yb, xc, yc;
    scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
    int x = (xa - xb);
    int y = (ya - yb);

    if (x == 0 && xc == xa && (abs(yc - ya) < abs(y)) && (abs(yc - yb) < abs(y)))
    {
        printf("%d\n", abs(x) + abs(y) + 2);
        printf("R");
        for (int i = 0; i < abs(y); i++)
        {
            if (y > 0)
            {
                printf("D");
            }
            else
            {
                printf("U");
            }
        }
        printf("L");
        printf("\n");
    }
    else if (y == 0 && yc == ya && (abs(xc - xa) < abs(x)) && (abs(xc - xb) < abs(x)))
    {
        printf("%d\n", abs(x) + abs(y) + 2);
        printf("U");
        for (int i = 0; i < abs(x); i++)
        {
            if (x > 0)
            {
                printf("L");
            }
            else
            {
                printf("R");
            }
        }
        printf("D");
        printf("\n");
    }
    else
    {
        printf("%d\n", abs(x) + abs(y));
        if (xc == xa || yc == yb)
        {
            for (int i = 0; i < abs(x); i++)
            {
                if (x > 0)
                {
                    printf("L");
                }
                else
                {
                    printf("R");
                }
            }
            for (int i = 0; i < abs(y); i++)
            {
                if (y > 0)
                {
                    printf("D");
                }
                else
                {
                    printf("U");
                }
            }
            printf("\n");
        }
        else
        {
            for (int i = 0; i < abs(y); i++)
            {
                if (y > 0)
                {
                    printf("D");
                }
                else
                {
                    printf("U");
                }
            }
            for (int i = 0; i < abs(x); i++)
            {
                if (x > 0)
                {
                    printf("L");
                }
                else
                {
                    printf("R");
                }
            }
            printf("\n");
        }
    }
    return 0;
}