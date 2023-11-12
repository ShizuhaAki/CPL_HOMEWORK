#include <stdio.h>
#include <math.h>

char board[2050][2050];

void paint(int n, int x, int y)
{
    if (n == 1)
    {
        board[x][y] = '/';
        board[x + 1][y - 1] = '/';
        board[x][y + 1] = '\\';
        board[x + 1][y + 2] = '\\';
        board[x + 1][y] = '_';
        board[x + 1][y + 1] = '_';
    }
    else
    {
        paint(n - 1, x, y);
        paint(n - 1, x + pow(2, n - 1), y + pow(2, n - 1));
        paint(n - 1, x + pow(2, n - 1), y - pow(2, n - 1));
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    paint(n, 0, pow(2, n) - 1);
    for(int i = 0; i < pow(2, n); i++)
    {
        for(int j = 0; j < pow(2, n + 1); j++)
        {
            if(board[i][j] == 0)
                board[i][j] = ' ';
        }
    }
    for(int i = 0; i < pow(2, n); i++)
    {
        for(int j = 0; j < pow(2, n + 1); j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}