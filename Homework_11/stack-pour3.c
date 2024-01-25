#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

struct node *newnode();
struct node *initstack(int n);
void put(struct node *x, struct node *y);
void printstack(struct node *stack);

int main()
{
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    Node **stack = malloc((n + 1) * sizeof(Node *));
    for (int i = 1; i <= n; i++)
        stack[i] = initstack(i);
    while (m--) {
        scanf("%d%d", &x, &y);
        put(stack[x], stack[y]);
    }
    for (int i = 1; i <= n; i++)
        printstack(stack[i]->next);
    return 0;
}

Node *newnode()
{
    Node *newnode = malloc(sizeof(Node));
    return newnode;
}

Node *initstack(int n)
{
    Node *new = newnode();
    new->val = -1;
    new->next = newnode();
    new->next->val = n;
    new->next->next = NULL;
    return new;
}

void put(struct node *x, struct node *y)
{
    if (x->next == NULL)
        return;
    while (x->next->next != NULL)
        put(x->next, y);
    while (y->next != NULL)
        y = y->next;
    y->next = x->next;
    x->next = NULL;
}

void printstack(struct node *stack)
{
    if (stack == NULL)
        printf("0");
    while (stack != NULL) {
        printf("%d ", stack->val);
        stack = stack->next;
    }
    printf("\n");
}