#include <stdio.h>
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int arr[501] = {0};
    int count = 0;
    int survive = n;
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    int x = 0;
    while (survive > 1)
    {
        if (arr[x] == 1)
        {
            if (x == n - 1)
                x = 0;
            else
                x++;
            continue;
        }
        else
        {
            count++;
            if (count == k)
            {
                arr[x] = 1;
                survive--;
                count = 0;
            }
            if (x == n - 1)
                x = 0;
            else
                x++;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (arr[j] == 0)
            printf("%d\n", j + 1);
    }
    return 0;
}