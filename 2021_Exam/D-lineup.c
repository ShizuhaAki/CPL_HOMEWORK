#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        char board[20][21] = {0};
        for (int i = 0; i < 20; i++) {
            scanf("%s", board[i]);
        }
    }
    return 0;
}