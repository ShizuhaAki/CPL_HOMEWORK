#include <stdio.h>
#include <math.h>

int n, p, A[100000];
double absf(double X);
double f(double X);
double S(double a, double b);
double simpson_sum(double a, double b, double e);

int main()
{
    // 输入
    scanf("%d %d", &n, &p);
    for (int i = 0; i <= n; ++i)
    {
        scanf("%d", &A[i]);
    }
    double a, b;
    scanf("%lf %lf", &a, &b);

    // 处理
    double ans = simpson_sum(a, b, 1e-4);
    // printf("%lf\n",pow(-0.5,2));
    // 输出
    printf("%lf\n", ans);
    return 0;
}

double absf(double X)
{
    if (X < 0)
        return -X;
    else
        return X;
}

double f(double X)
{
    double fx = 0;
    for (int i = n; i >= 0; i--)
    {
        fx += A[i] * pow(X, i);
    }
    fx = pow(fx, p);
    return fx;
}

double S(double a, double b)
{
    double M = 4 * f((a + b) / 2) + f(a) + f(b);
    double s = M / 6 * (b - a);
    return s;
}

double simpson_sum(double a, double b, double e)
{
    double ans;
    double l = a, r = b;
    double mid = (l + r) / 2;
    double chk = S(l, r);
    double SL = S(l, mid), SR = S(mid, r);

    if (absf(SL + SR - S(l, r)) <= 15 * e)
    {
        ans = SL + SR + (SL + SR - S(l, r)) / 15;
        return ans;
    }
    else
    {
        return simpson_sum(l, mid, e / 2) + simpson_sum(mid, r, e / 2);
    }
}