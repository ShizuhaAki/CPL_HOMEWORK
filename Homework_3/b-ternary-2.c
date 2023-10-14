#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int fun(int len, char str[])
{
    for (int i = 0; i < len; i++)
    {
        char ch = str[i];
        if (ch != '-' && isdigit(ch) == 0)
            return -1;
    }
    return 1;
}

void Inverse(char arr[], int len)
{
    char r[25] = {0};
    for (int i = 0; i < len; i++)
    {
        r[i] = arr[i];
    }
    for (int i = 0; i < len; i++)
    {
        arr[i] = r[len - 1 - i];
    }
}

void Change(char str[], char answer[])
{
    int origin = atoi(str);
    if (origin != 0)
    {
        int o[25] = {0};
        int count = 0;
        while (origin != 0)
        {
            o[count] = origin % 3;
            origin /= 3;
            count++;
        }
        for (int j = 0; j < count; j++)
        {
            if (o[j] == 1)
            {
                answer[j] = '1';
            }
            else if (o[j] == 0)
            {
                answer[j] = '0';
            }
            else if (o[j] == 2)
            {
                answer[j] = 'Z';
                o[j + 1] += 1;
            }
            else if (o[j] == 3)
            {
                answer[j] = '0';
                o[j + 1] += 1;
            }
        }
        if (o[count] != 0)
        {
            answer[count] = '1';
            count += 1;
        }
        Inverse(answer, count);
        for (int k = 0; k < count; k++)
        {
            printf("%c", answer[k]);
        }
    }
    else
    {
        printf("0");
    }
    printf("\n");
}

void Change2(char str[], char answer[])
{
    int origin = atoi(str);
    origin = origin * (-1);
    int o[25] = {0};
    int count = 0;
    while (origin != 0)
    {
        o[count] = origin % 3;
        origin /= 3;
        count++;
    }
    for (int j = 0; j < count; j++)
    {
        if (o[j] == 1)
        {
            answer[j] = '1';
        }
        else if (o[j] == 0)
        {
            answer[j] = '0';
        }
        else if (o[j] == 2)
        {
            answer[j] = 'Z';
            o[j + 1] += 1;
        }
        else if (o[j] == 3)
        {
            answer[j] = '0';
            o[j + 1] += 1;
        }
    }

    if (o[count] != 0)
    {
        answer[count] = '1';
        count += 1;
    }

    Inverse(answer, count);
    for (int k = 0; k < count; k++)
    {
        if (answer[k] == '1')
            answer[k] = 't';
        else if (answer[k] == 'Z')
            answer[k] = '1';
    }
    for (int k = 0; k < count; k++)
    {
        if (answer[k] == 't')
            answer[k] = 'Z';
    }

    for (int k = 0; k < count; k++)
    {
        printf("%c", answer[k]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char str[20];
        getchar();
        scanf("%s", str);

        int len = strlen(str);
        int judge = fun(len, str);
        if (judge == -1)
            printf("Radix Error\n");
        else if (judge == 1)
        {
            char answer[25];
            if (str[0] != '-')
            {
                Change(str, answer);
            }
            else
            {
                Change2(str, answer);
            }
        }
    }

    return 0;
}