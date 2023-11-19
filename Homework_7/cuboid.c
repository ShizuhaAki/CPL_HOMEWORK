#include <stdio.h>

int main()
{
    char board[100][100] = {0};
    int T;
    scanf("%d", &T);
    while (T > 0)
    {
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                board[i][j] = ' ';
            }
        }
        T--;
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        for (int i = 0; i < 2 * b; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < 2 * b - i; j++)
                    board[i][j] = ' ';
                for (int j = 2 * b - i; j <= 2 * (a + b) - i; j++)
                {
                    if (j % 2 == 0)
                        board[i][j] = '+';
                    else
                        board[i][j] = '-';
                }
            }
            else
            {
                for (int j = 0; j < 2 * b - i; j++)
                    board[i][j] = ' ';
                for (int j = 2 * b - i; j <= 2 * (a + b) - i; j++)
                {
                    if (j % 2 == 0)
                        board[i][j] = ' ';
                    else
                        board[i][j] = '/';
                }
            }
        }

        for (int i = 2 * b; i <= 2 * b + 2 * c + 1; i += 2)
        {
            for (int j = 0; j <= 2 * a; j++)
            {
                if (j % 2 == 0)
                    board[i][j] = '+';
                else
                    board[i][j] = '-';
            }
        }
        for (int i = 2 * b + 1; i <= 2 * b + 2 * c + 1; i += 2)
        {
            for (int j = 0; j <= 2 * a; j++)
            {
                if (j % 2 == 0)
                {
                    board[i][j] = '|';
                }
                else
                {
                    board[i][j] = ' ';
                }
            }
        }

        for (int j = 2 * a + 1; j <= 2 * (a + b); j++)
        {
            if (j % 2 == 0)
            {
                for (int i = 2 * b - j + 2 * a; i < 2 * (a + b + c) + 1 - j; i++)
                {
                    if (i % 2 == 0)
                        board[i][j] = '+';
                    else
                        board[i][j] = '|';
                }
            }
            else
            {
                for (int i = 2 * b - j + 2 * a; i < 2 * (a + b + c) + 1 - j; i++)
                {
                    if (i % 2 == 0)
                        board[i][j] = ' ';
                    else
                        board[i][j] = '/';
                }
            }
        }

        for (int i = 0; i <= 2 * (b + c); i++)
        {
            for (int j = 0; j <= 2 * (a + b); j++)
            {
                printf("%c", board[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}