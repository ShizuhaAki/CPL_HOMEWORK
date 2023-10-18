#include <stdio.h>
#include <math.h>

int CHECK(char str[], int len, int N)
{
    for (int i = 0; i < len; i++)
    {
        int k = (int)str[i];
        if (N <= 10)
        {
            if (k < 48 || k > N - 1 + 48)
                return -1;
        }
        else if (N > 10)
        {
            if (k < 48 || (k > 57 && k < 'A') || k > N - 11 + 'A')
                return -1;
        }
    }
    return 0;
}

int FUN(char str[], int len, int N)
{
    int n = 0;
    for (int i = 0; i < len; i++)
    {
        int k = (int)str[i];
        if(k >= 'A')
            k -= ('A' - 10);
        else
            k -= 48;
        n += k * pow(N, len - i - 1);
    }
    return n;
}

int main()
{
    int len, N;
    char s[35] = {0};
    scanf("%d%d", &len, &N);
    getchar();
    scanf("%s", s);

    int check = CHECK(s, len, N);
    if (check == -1)
        printf("Error");
    else
    {
        printf("%d\n", FUN(s, len, N));
    }

    return 0;
}