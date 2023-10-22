#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char str[105][105] = {0};
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", str[i]);
    }
    char arr[105][105] = {0};

    int vectors[8][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
        {-1, -1},
        {1, -1},
        {-1, 1},
        {1, 1}
    };
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(str[i][j] == '*')
                arr[i][j] = '*';
            else
            {
                int count = 0;
                for(int k = 0; k < 8; k++)
                {
                    int newi = i + vectors[k][0];
                    int newj = j + vectors[k][1];
                    if (str[newi][newj] == '*')
                    {
                        count++;
                    }
                }
                arr[i][j] = count - 1 + '1';
            }    
        }
    }
    
    int vect[5][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {-1, 1},
        {1, 1}
    };
    for(int i = 1; i <= n; i++)
    {
        if(str[i][0] == '*')
            arr[i][0] = '*';
        else
        {
            int count = 0;
            for(int k = 0; k < 5; k++)
            {
                int newi = i + vect[k][0];
                int newj = 0 + vect[k][1];
                if (str[newi][newj] == '*')
                {
                    count++;
                }
            }
            arr[i][0] = count - 1 + '1';
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}