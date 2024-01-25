#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    int y;
    struct node *up, *right, *left, *down;
} Node;

Node world[501][501];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) {
            if (i == 1) {
                world[i][j].left = NULL;
                world[i][j].right = &world[i + 1][j];
            } else if (i == 500) {
                world[i][j].right = NULL;
                world[i][j].left = &world[i - 1][j];
            } else {
                world[i][j].left = &world[i - 1][j];
                world[i][j].right = &world[i + 1][j];
            }
            if (j == 1) {
                world[i][j].down = NULL;
                world[i][j].up = &world[i][j + 1];
            } else if (j == 500) {
                world[i][j].up = NULL;
                world[i][j].down = &world[i][j - 1];
            } else {
                world[i][j].down = &world[i][j - 1];
                world[i][j].up = &world[i][j + 1];
            }
            world[i][j].x = i;
            world[i][j].y = j;
        }
    }
    Node *pos = &world[1][1];
    Node *out = NULL;
    int flag = 0; // flag != 0: have moved
    for (int qn = 0; qn < n; qn++) {
        char ch;
        getchar();
        ch = getchar();
        if (ch == 'H') {
            if (pos != NULL && pos->left != NULL) {
                pos = pos->left;
                flag = 1;
            }
        } else if (ch == 'J') {
            if (pos != NULL && pos->down != NULL) {
                pos = pos->down;
                flag = 1;
            }
        } else if (ch == 'K') {
            if (pos != NULL && pos->up != NULL) {
                pos = pos->up;
                flag = 1;
            }
        } else if (ch == 'L') {
            if (pos != NULL && pos->right != NULL) {
                pos = pos->right;
                flag = 1;
            }
        } else if (ch == 'P') {
            printf("(%d, %d)\n", pos->x, pos->y);
            flag = 0;
        } else if (ch == 'X') {
            out = pos;
            flag = 0;
        }
        if (out != NULL && flag != 0) {
            if (out->right != NULL)
                out->right->left = out->left;
            if (out->left != NULL)
                out->left->right = out->right;
            if (out->up != NULL)
                out->up->down = out->down;
            if (out->down != NULL)
                out->down->up = out->up;
        }
    }
    return 0;
}