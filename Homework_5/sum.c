#include <stdio.h>
#include <math.h>
int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    int sum = 0;
    int k = 1;
    while(n > 0)
    {
        sum += k * t * pow(10, n - 1);
        k++;
        n--;
    }
    printf("%d", sum);
    return 0;
}