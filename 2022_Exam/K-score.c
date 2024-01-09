#include <stdio.h>

int board[9];
int n1, n2, n3;

int checkline(int i, int j, int k);
void Swap(int *a, int *b, int *c);
void ChangeTwo(int *a, int *b);

int main()
{
    for (int i = 0; i < 9; i++) {
        scanf("%d", &board[i]);
    }
    scanf("%d%d%d", &n1, &n2, &n3);
    Swap(&n1, &n2, &n3);
    // printf("%d %d %d\n", n1, n2, n3);
    // printf("%d\n", checkline(0, 1, 3));
    int max = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 8; j++) {
            for (int k = j + 1; k < 9; k++) {
                if (checkline(i, j, k) == 1) {
                    continue;
                }
                int t1 = board[i], t2 = board[j], t3 = board[k];
                Swap(&t1, &t2, &t3);
                int temp = n1 * t1 + n2 * t2 + n3 * t3;
                // max = (max > temp) ? max : temp;
                if (temp > max) {
                    max = temp;
                    // printf("%d  %d  %d\n", i, j, k);
                    // printf("%d = %d*%d + %d*%d + %d*%d\n", temp, n1, t1, n2, t2, n3, t3);
                }
            }
        }
    }
    printf("%d\n", max);
    return 0;
}

int checkline(int i, int j, int k)
{
    if (i + j == k * 2)
        return 1;
    if (i + k == j * 2)
        return 1;
    if (j + k == i * 2)
        return 1;

    return 0;
}

void Swap(int *a, int *b, int *c)
{
    if (*a > *b)
        ChangeTwo(a, b);
    if (*b > *c)
        ChangeTwo(b, c);
    if (*a > *b)
        ChangeTwo(a, b);
}

void ChangeTwo(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}