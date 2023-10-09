#include <stdio.h>
#include <string.h>

int main()
{
    long int n;
    scanf("%ld", &n);
    getchar();
    char str[10000005] = {0};
    for (int i = 0; i < n; i++)
    {
        char ch = getchar();
        str[i] = ch;
    }
    long int k;
    scanf("%ld", &k);

    char r[10000005] = {0};
    for (int i = 0; i < k; i++)
    {
        r[i] = str[k - 1 - i];
    }
    for (int i = k; i < n; i++)
    {
        r[i] = str[n - 1 + k - i];
    }
    printf("%s\n", r);
    return 0;
}