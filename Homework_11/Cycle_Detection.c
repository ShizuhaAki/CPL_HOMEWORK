#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char s[25];
    struct node *next;
} Node;

void freeList(Node **list, int n);

int main()
{
    int n;
    scanf("%d", &n);
    Node **list = malloc(sizeof(Node *) * (n + 1));
    for (int i = 1; i <= n; i++) {
        list[i] = malloc(sizeof(Node));
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", list[i]->s);
        int index;
        scanf("%d", &index);
        if (index >= 1 && index <= n) {
            list[i]->next = list[index];
        } else {
            list[i]->next = NULL;
        }
    }
    // printf("%s\n%s\n", list[1]->s, list[2]->s);
    // printf("%s\n", list[1]->next->s);
    Node *p1 = list[1], *p2 = list[1];
    int flag = 1;
    while (p2 != NULL) {
        // printf("p2 origin: %s\n", p2->s);
        if (p2 != NULL) {
            p2 = p2->next;
        } else {
            break;
        }
        // printf("p2 changing: %s\n", p2->s);
        if (p2 != NULL) {
            p2 = p2->next;
        } else {
            break;
        }
        p1 = p1->next;
        // printf("p1: %s\n", p1->s);
        // printf("p2: %s\n", p2->s);
        if (p1 == p2) {
            // flag = 1;
            break;
        }
    }
    // printf("Finish Loop\n");
    if (p2 == NULL) {
        flag = 0;
    }
    if (flag == 0) {
        printf("-1\n");
    } else {
        p1 = list[1];
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        printf("%s\n", p1->s);
    }
    freeList(list, n);
    return 0;
}

void freeList(Node **list, int n)
{
    for (int i = 1; i <= n; i++) {
        free(list[i]);
    }
    free(list);
}