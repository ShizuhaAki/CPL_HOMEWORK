#include <stdio.h>
int main()
{
    int n, num;
    scanf("%d", &n);
    int x1 = 1, x2 = 1;
    for (int i = 3; i <= n; i++)
    {
        num = x1 + x2;
        x1 = x2;
        x2 = num;
    }
    printf("%d\n", num);
    return 0;
}