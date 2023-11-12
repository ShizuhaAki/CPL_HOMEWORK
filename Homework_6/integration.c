#include <stdio.h>
#include <math.h>

int problem[25];
int n, p;

double abs_double(double x)
{
    if (x < 0)
        x = x * (-1);
    return x;
}

// double pow_double(double x, int k)
// {
//     double s = 1;
//     while (k > 0)
//     {
//         s *= x;
//         k--;
//     }
//     return s;
// }

double fun(double x)
{
    double answer = 0;
    for (int i = 0; i <= n; i++)
    {
        answer += problem[i] * pow(x, i);
    }
    answer = pow(answer, p);
    return answer;
}

double simpson(double a, double b)
{
    return ((4 * fun((a + b) / 2.0) + fun(a) + fun(b)) / 6.0) * (b - a);
}

double check(double l, double r, double epison)
{
    double mid = (l + r) / 2;
    double S = simpson(l, r);
    double SL = simpson(l, mid);
    double SR = simpson(mid, r);
    if (abs_double(SL + SR - S) <= 15 * epison)
        return (SL + SR + (SL + SR - S) / 15.0);
    else
        return check(l, mid, epison / 2.0) + check(mid, r, epison / 2.0);
}

int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &problem[i]);
    }
    double a, b;
    scanf("%lf%lf", &a, &b);
    double out = check(a, b, 0.0001);
    printf("%lf\n", out);
    return 0;
}