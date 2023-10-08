#include <stdio.h>
#include <math.h>
int main()
{
    float x;
    int n;
    scanf("%f%d", &x, &n);
    double y = 0.0;
    for (int i = 0; i <= n; i++)
    {
        y += 4 * (pow(-1, i) * pow(x, 2 * i + 1)) * 1.0 / (2 * i + 1);
    }
    printf("%.10lf", y);
    return 0;
}