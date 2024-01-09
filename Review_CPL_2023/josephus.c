#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;
int n, q;
Node *Create(int num);
int JOJO();

int main()
{
    scanf("%d%d", &n, &q);
    head = Create(n);
    printf("%d\n", JOJO());
    return 0;
}

Node *Create(int num)
{
    Node *head = malloc(sizeof(Node)), *cur = head;
    for (int i = 1; i <= num; i++) {
        if (i == 1) {
            head->data = i;
            head->next = NULL;
        } else if (i != num) {
            Node *p = malloc(sizeof(Node));
            p->next = NULL;
            p->data = i;
            cur->next = p;
            cur = cur->next;
        } else {
            Node *p = malloc(sizeof(Node));
            p->next = head;
            p->data = i;
            cur->next = p;
        }
    }
    return head;
}

int JOJO()
{
    Node *cur = head, *pre = NULL;
    while (cur->next != cur) {
        for (int i = 1; i < q; i++) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        free(cur);
        cur = pre->next;
    }
    return cur->data;
}