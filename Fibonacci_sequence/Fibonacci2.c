#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int f1 = 1, f2 = 1;
    for (int i = 3; i <= n; i++)
    {
        f2 = f1 + f2;
        f1 = f2 - f1;
    }
    printf("%d\n", f2);
    return 0;
}