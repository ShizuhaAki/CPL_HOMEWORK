#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char str[1005] = {0};
    scanf("%s", str);
    int len = strlen(str);

    int max = 0;
    int count[126] = {0};
    for(int i = 0; i < len; i++)
    {
        int s = (int)str[i];
        count[s]++;
    }
    for(int i = 0; i < 126; i++)
    {
        if(count[i] > max)
            max = count[i];
    }
    char arr[1005][100] = {0};
    
    int x = -1;
    int sum = 0;
    for(int i = 'a', j = 'A'; i < 'z', j < 'Z'; i++, j++)
    {
        if(count[i] != 0)
        {
            x++;
            arr[0][x] = i;
            arr[1][x] = '-';
            for(int m = 2; m < max + 2; m++)
            {
                if(m < count[i] + 2)
                    arr[m][x] = '=';
                else
                    arr[m][x] = ' ';
            }
            sum++;
        }
        if(count[j] != 0)
        {
            x++;
            arr[0][x] = j;
            arr[1][x] = '-';
            for(int m = 2; m < max + 2; m++)
            {
                if(m < count[j] + 2)
                    arr[m][x] = '=';
                else
                    arr[m][x] = ' ';
            }
            sum++;
        }
        if(count[i] + count[j] > 0)
        {
            x++;
            arr[0][x] = ' ';
            arr[1][x] = '-';
            for(int m = 2; m < max + 2; m++)
            {
                arr[m][x] = ' ';
            }
            sum++;
        }
    }

    for(int i = max + 1; i >= 0; i--)
    {
        for(int j = 0; j < sum - 1; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}