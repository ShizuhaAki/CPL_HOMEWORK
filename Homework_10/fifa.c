#include <stdio.h>
#include <stdlib.h>

int n;

typedef struct node {
    char name[25];
    char player[11][25];
    int atk[11];
    int def[11];
    int org[11];
    double average_atk;
    double average_def;
    double average_org;
} Team;

int cmpatk(const void *p1, const void *p2)
{
    double x = (((Team *)p2)->average_atk - ((Team *)p1)->average_atk);
    if (x > 0) {
        return 1;
    } else {
        return -1;
    }
}

int cmpdef(const void *p1, const void *p2)
{
    double x = (((Team *)p2)->average_def - ((Team *)p1)->average_def);
    if (x > 0) {
        return 1;
    } else {
        return -1;
    }
}

int cmporg(const void *p1, const void *p2)
{
    double x = (((Team *)p2)->average_org - ((Team *)p1)->average_org);
    if (x > 0) {
        return 1;
    } else {
        return -1;
    }
}

int main()
{
    scanf("%d", &n);
    Team arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i].name);
        int ATK = 0, DEF = 0, ORG = 0;
        for (int j = 0; j < 11; j++) {
            scanf("%s%d%d%d", arr[i].player[j], &arr[i].atk[j], &arr[i].def[j], &arr[i].org[j]);
            ATK += arr[i].atk[j];
            DEF += arr[i].def[j];
            ORG += arr[i].org[j];
        }
        arr[i].average_atk = (ATK * 1.0) / 11;
        arr[i].average_def = (DEF * 1.0) / 11;
        arr[i].average_org = (ORG * 1.0) / 11;
    }
    qsort(arr, n, sizeof(arr[0]), cmpatk);
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i].name);
    }
    printf("\n");
    qsort(arr, n, sizeof(arr[0]), cmpdef);
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i].name);
    }
    printf("\n");
    qsort(arr, n, sizeof(arr[0]), cmporg);
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i].name);
    }
    printf("\n");
    return 0;
}