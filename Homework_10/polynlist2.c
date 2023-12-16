#include <stdio.h>
#include <stdlib.h>

int p1, p2;
char name[15];
int P1[10005], P2[10005], P[10005], T[20010], M[10005];

void Print(int pmax, int arr[]);

int main()
{
    scanf("%d%d", &p1, &p2);
    scanf("%s", name);
    for (int i = p1; i >= 0; i--)
        scanf("%d", &P1[i]);
    for (int i = p2; i >= 0; i--)
        scanf("%d", &P2[i]);

    int pmax = (p1 > p2) ? p1 + 1 : p2 + 1;

    for (int i = 0; i <= pmax; i++) {
        P[i] = P1[i] + P2[i];
        M[i] = P1[i] - P2[i];
    }
    while (P[--pmax] == 0)
        ;
    Print(pmax, P);

    pmax = (p1 > p2) ? p1 + 1 : p2 + 1;
    while (M[--pmax] == 0)
        ;
    Print(pmax, M);

    pmax = p1 + p2 + 1;
    for (int i = 0; i <= p1; i++) {
        for (int j = 0; j <= p2; j++) {
            T[i + j] += P1[i] * P2[j];
        }
    }
    while (T[--pmax] == 0)
        ;
    Print(pmax, T);

    return 0;
}

void Print(int pmax, int arr[])
{
    for (int i = pmax; i >= 0; i--) {
        if (i > 1) {
            if (arr[i] == 0) {
                continue;
            } else if (arr[i] == 1 && i != pmax) {
                printf("+%s^%d", name, i);
            } else if (arr[i] == 1 && i == pmax) {
                printf("%s^%d", name, i);
            } else if (arr[i] == -1) {
                printf("-%s^%d", name, i);
            } else if (arr[i] > 0 && i != pmax) {
                printf("+%d%s^%d", arr[i], name, i);
            } else if (arr[i] > 0 && i == pmax) {
                printf("%d%s^%d", arr[i], name, i);
            } else if (arr[i] < 0) {
                printf("%d%s^%d", arr[i], name, i);
            }
        } else if (i == 1) {
            if (arr[i] == 0) {
                continue;
            } else if (arr[i] == 1 && i != pmax) {
                printf("+%s", name);
            } else if (arr[i] == 1 && i == pmax) {
                printf("%s", name);
            } else if (arr[i] == -1) {
                printf("-%s", name);
            } else if (arr[i] > 0 && i != pmax) {
                printf("+%d%s", arr[i], name);
            } else if (arr[i] > 0 && i == pmax) {
                printf("%d%s", arr[i], name);
            } else if (arr[i] < 0) {
                printf("%d%s", arr[i], name);
            }
        } else if (i == 0) {
            if (arr[i] > 0 && i != pmax) {
                printf("+");
            }
            if (arr[i] != 0) {
                printf("%d", arr[i]);
            } else if (arr[i] == 0 && pmax == 0) {
                printf("0");
            }
        }
    }
    printf("\n");
}