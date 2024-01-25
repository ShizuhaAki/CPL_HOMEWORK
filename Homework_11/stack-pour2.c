#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int val;
    struct stack *next;
} Stack;

typedef struct list {
    int index;
    struct stack *stack;
    struct list *next;
} List;

List *Initlist(int i);
Stack *Initstack(int i);
void change(int x, int y, List *head);
void PrintList(List *list);
void PrintStack(Stack *stack);
void FreeList(List *list);
void FreeStack(Stack *stack);
List *GetListByIndex(List *head, int index);

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    List *head = malloc(sizeof(List));
    head->index = 0;
    head->next = NULL;
    head->stack = NULL;
    List *p = head;
    for (int i = 1; i <= n; i++) {
        p->next = Initlist(i);
        p = p->next;
    }
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        change(x, y, head);
    }
    PrintList(head->next);
    FreeList(head->next);
    free(head);
    return 0;
}

List *Initlist(int i)
{
    List *new = malloc(sizeof(List));
    new->next = NULL;
    new->index = i;
    new->stack = Initstack(i);
    return new;
}

Stack *Initstack(int i)
{
    Stack *new = malloc(sizeof(Stack));
    new->val = -1;
    new->next = malloc(sizeof(Stack));
    new->next->val = i;
    new->next->next = NULL;
    return new;
}

void PrintList(List *list)
{
    while (list != NULL) {
        PrintStack(list->stack);
        list = list->next;
    }
}

void PrintStack(Stack *stack)
{
    if (stack->next == NULL) {
        printf("0\n");
        return;
    } else {
        Stack *cur = stack->next;
        while (cur) {
            printf("%d ", cur->val);
            cur = cur->next;
        }
        printf("\n");
    }
}

void FreeList(List *list)
{
    while (list != NULL) {
        List *p = list->next;
        if (list->stack)
            FreeStack(list->stack);
        free(list);
        list = p;
    }
}

void FreeStack(Stack *stack)
{
    while (stack) {
        Stack *p = stack->next;
        free(stack);
        stack = p;
    }
}

void change(int x, int y, List *head)
{
    List *p1 = GetListByIndex(head, x), *p2 = GetListByIndex(head, y);
    while (p1->stack->next != NULL) {
        Stack *q1 = p1->stack, *q2 = p2->stack;
        while (q1->next->next != NULL) {
            q1 = q1->next;
        }
        while (q2->next != NULL) {
            q2 = q2->next;
        }
        q2->next = q1->next;
        q1->next = NULL;
    }
}

List *GetListByIndex(List *head, int index)
{
    while (head->index != index) {
        head = head->next;
    }
    return head;
}