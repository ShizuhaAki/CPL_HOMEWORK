#include <stdio.h>
#include <stdlib.h>

int p1, p2;
char name[15];
int P1[10005] = {0}, P2[10005] = {0};
int P[10005], T[20010], M[10005];

int main()
{
    scanf("%d%d", &p1, &p2);
    scanf("%s", name);
    for (int i = p1; i >= 0; i--) {
        scanf("%d", &P1[i]);
    }
    for (int i = p2; i >= 0; i--) {
        scanf("%d", &P2[i]);
    }
    int pmax = (p1 > p2) ? p1 : p2;

    for (int i = 0; i <= pmax; i++) {
        P[i] = P1[i] + P2[i];
        M[i] = P1[i] - P2[i];
    }
    while (pmax > 0) {
        if (P[pmax] != 0) {
            break;
        } else {
            pmax--;
        }
    }
    for (int i = pmax; i >= 0; i--) {
        if (i > 1) {
            if (P[i] == 0) {
                continue;
            } else if (P[i] == 1 && i != pmax) {
                printf("+%s^%d", name, i);
            } else if (P[i] == 1 && i == pmax) {
                printf("%s^%d", name, i);
            } else if (P[i] == -1) {
                printf("-%s^%d", name, i);
            } else if (P[i] > 0 && i != pmax) {
                printf("+%d%s^%d", P[i], name, i);
            } else if (P[i] > 0 && i == pmax) {
                printf("%d%s^%d", P[i], name, i);
            } else if (P[i] < 0) {
                printf("%d%s^%d", P[i], name, i);
            }
        } else if (i == 1) {
            if (P[i] == 0) {
                continue;
            } else if (P[i] == 1 && i != pmax) {
                printf("+%s", name);
            } else if (P[i] == 1 && i == pmax) {
                printf("%s", name);
            } else if (P[i] == -1) {
                printf("-%s", name);
            } else if (P[i] > 0 && i != pmax) {
                printf("+%d%s", P[i], name);
            } else if (P[i] > 0 && i == pmax) {
                printf("%d%s", P[i], name);
            } else if (P[i] < 0) {
                printf("%d%s", P[i], name);
            }
        } else if (i == 0) {
            if (P[i] > 0 && i != pmax) {
                printf("+");
            }
            if (P[i] != 0) {
                printf("%d", P[i]);
            } else if (P[i] == 0 && pmax == 0) {
                printf("0");
            }
        }
    }
    printf("\n");

    pmax = (p1 > p2) ? p1 : p2;
    while (pmax > 0) {
        if (M[pmax] != 0) {
            break;
        } else {
            pmax--;
        }
    }
    for (int i = pmax; i >= 0; i--) {
        if (i > 1) {
            if (M[i] == 0) {
                continue;
            } else if (M[i] == 1 && i != pmax) {
                printf("+%s^%d", name, i);
            } else if (M[i] == 1 && i == pmax) {
                printf("%s^%d", name, i);
            } else if (M[i] == -1) {
                printf("-%s^%d", name, i);
            } else if (M[i] > 0 && i != pmax) {
                printf("+%d%s^%d", M[i], name, i);
            } else if (M[i] > 0 && i == pmax) {
                printf("%d%s^%d", M[i], name, i);
            } else if (M[i] < 0) {
                printf("%d%s^%d", M[i], name, i);
            }
        } else if (i == 1) {
            if (M[i] == 0) {
                continue;
            } else if (M[i] == 1 && i != pmax) {
                printf("+%s", name);
            } else if (M[i] == 1 && i == pmax) {
                printf("%s", name);
            } else if (M[i] == -1) {
                printf("-%s", name);
            } else if (M[i] > 0 && i != pmax) {
                printf("+%d%s", M[i], name);
            } else if (M[i] > 0 && i == pmax) {
                printf("%d%s", M[i], name);
            } else if (M[i] < 0) {
                printf("%d%s", M[i], name);
            }
        } else if (i == 0) {
            if (M[i] > 0 && i != pmax) {
                printf("+");
            }
            if (M[i] != 0) {
                printf("%d", M[i]);
            } else if (M[i] == 0 && pmax == 0) {
                printf("0");
            }
        }
    }
    printf("\n");

    pmax = p1 + p2;
    for (int i = 0; i <= p1; i++) {
        for (int j = 0; j <= p2; j++) {
            T[i + j] += P1[i] * P2[j];
        }
    }
    while (pmax > 0) {
        if (T[pmax] != 0) {
            break;
        } else {
            pmax--;
        }
    }
    for (int i = pmax; i >= 0; i--) {
        if (i > 1) {
            if (T[i] == 0) {
                continue;
            } else if (T[i] == 1 && i != pmax) {
                printf("+%s^%d", name, i);
            } else if (T[i] == 1 && i == pmax) {
                printf("%s^%d", name, i);
            } else if (T[i] == -1) {
                printf("-%s^%d", name, i);
            } else if (T[i] > 0 && i != pmax) {
                printf("+%d%s^%d", T[i], name, i);
            } else if (T[i] > 0 && i == pmax) {
                printf("%d%s^%d", T[i], name, i);
            } else if (T[i] < 0) {
                printf("%d%s^%d", T[i], name, i);
            }
        } else if (i == 1) {
            if (T[i] == 0) {
                continue;
            } else if (T[i] == 1 && i != pmax) {
                printf("+%s", name);
            } else if (T[i] == 1 && i == pmax) {
                printf("%s", name);
            } else if (T[i] == -1) {
                printf("-%s", name);
            } else if (T[i] > 0 && i != pmax) {
                printf("+%d%s", T[i], name);
            } else if (T[i] > 0 && i == pmax) {
                printf("%d%s", T[i], name);
            } else if (T[i] < 0) {
                printf("%d%s", T[i], name);
            }
        } else if (i == 0) {
            if (T[i] > 0 && i != pmax) {
                printf("+");
            }
            if (T[i] != 0) {
                printf("%d", T[i]);
            } else if (T[i] == 0 && pmax == 0) {
                printf("0");
            }
        }
    }
    printf("\n");
    return 0;
}