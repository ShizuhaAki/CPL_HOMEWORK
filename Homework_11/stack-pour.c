#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num[1000000];
    int cnt;
    struct node *next;
} Node;

int n, m;

Node *Init();
void operate(Node *head, int x, int y);
void Print(Node *head);

int main()
{
    scanf("%d%d", &n, &m);
    Node *head = Init();
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        operate(head, x, y);
    }
    Print(head);
    return 0;
}

Node *Init()
{
    if (n <= 0) {
        return NULL;
    }
    Node *head = malloc(sizeof(Node));
    head->cnt = 1;
    head->num[0] = 1;
    head->next = NULL;
    Node *cur = head;
    for (int i = 2; i <= n; i++) {
        Node *p = malloc(sizeof(Node));
        p->cnt = 1;
        p->next = NULL;
        p->num[0] = i;
        cur->next = p;
        cur = cur->next;
    }
    return head;
}

void Print(Node *head)
{
    while (head != NULL) {
        if (head->cnt == 0) {
            printf("0\n");
        } else {
            for (int k = 0; k < head->cnt; k++) {
                printf("%d ", head->num[k]);
            }
            printf("\n");
        }
        head = head->next;
    }
}

void operate(Node *head, int x, int y)
{
    Node *px = head, *py = head;
    while (x > 1) {
        x--;
        px = px->next;
    }
    while (y > 1) {
        y--;
        py = py->next;
    }
    for (int i = 0; i < px->cnt; i++) {
        py->num[i + py->cnt] = px->num[px->cnt - i - 1];
        px->num[px->cnt - i - 1] = 0;
    }
    py->cnt += px->cnt;
    px->cnt = 0;
}