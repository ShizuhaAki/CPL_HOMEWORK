#include <stdio.h>
#define SIZE 20

int t;
char board[SIZE + 5][SIZE + 5];

int count(char signal);
int check(int x, int y, char signal);

int main()
{
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < SIZE; i++) {
            scanf("%s", board[i]);
        }
        if (count('*')) {
            printf("Lose\n");
        } else if (count('#') >= 2) {
            printf("Win\n");
        } else {
            printf("Not Sure\n");
        }
    }
    return 0;
}

int count(char signal)
{
    int cnt = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != '_')
                continue;
            if (check(i, j, signal))
                cnt++;
        }
    }
    return cnt;
}

int check(int x, int y, char signal)
{
    int sum = 1;
    int k = y - 1;
    while (k >= 0 && board[x][k] == signal) {
        k--;
        sum++;
    }
    k = y + 1;
    while (k < SIZE && board[x][k] == signal) {
        k++;
        sum++;
    }
    if (sum >= 5) {
        return 1;
    }

    sum = 1;
    k = x - 1;
    while (k >= 0 && board[k][y] == signal) {
        k--;
        sum++;
    }
    k = x + 1;
    while (k < SIZE && board[k][y] == signal) {
        k++;
        sum++;
    }
    if (sum >= 5) {
        return 1;
    }

    int i = x - 1, j = y - 1;
    sum = 1;
    while (i >= 0 && j >= 0 && board[i--][j--] == signal) {
        sum++;
    }
    i = x + 1;
    j = y + 1;
    while (i < SIZE && j < SIZE && board[i++][j++] == signal) {
        sum++;
    }
    if (sum >= 5) {
        return 1;
    }

    i = x - 1;
    j = y + 1;
    sum = 1;
    while (i >= 0 && j < SIZE && board[i--][j++] == signal) {
        sum++;
    }
    i = x + 1;
    j = y - 1;
    while (i < SIZE && j >= 0 && board[i++][j--] == signal) {
        sum++;
    }
    if (sum >= 5) {
        return 1;
    }

    return 0;
}