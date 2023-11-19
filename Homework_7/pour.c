#include <stdio.h>

int k, VA, VB, VC, a, b, c, a0, b0, c0;

int pour(int times, int va, int vb, int vc);
int judge(int va, int vb, int vc);
int min(int a, int b);

int main()
{
    scanf("%d%d%d%d%d%d%d%d%d%d", &k, &VA, &VB, &VC, &a, &b, &c, &a0, &b0, &c0);
    int va = a, vb = b, vc = c;
    int t = pour(0, va, vb, vc);
    if (t)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

int pour(int times, int va, int vb, int vc)
{
    if (judge(va, vb, vc))
        return 1;
    if (times == k)
        return 0;

    return (pour(times + 1, min((va + vb), VA), 0, vc) || pour(times + 1, min((va + vc), VA), vb, 0) || pour(times + 1, 0, min((va + vb), VB), vc) || pour(times + 1, va, min((vc + vb), VB), 0) || pour(times + 1, 0, vb, min((va + vc), VC)) || pour(times + 1, va, 0, min((vb + vc), VC)));
}

int judge(int va, int vb, int vc)
{
    if (va == a0 && vb == b0 && vc == c0)
        return 1;
    else
        return 0;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}