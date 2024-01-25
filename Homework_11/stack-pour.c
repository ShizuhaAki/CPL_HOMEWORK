#include <stdio.h>
#include <stdlib.h>

typedef struct stacknode {
    int val;
    struct stacknode *next;
} Stacknode;

typedef struct stack {
    struct stack *top;
} Stack;

void push(Stack *stack, int val);
void append(Stack *stack, Stacknode *node);
Stacknode *popAll(Stack *stack);
void printStack(Stack *stack);
void freeStack(Stack *stack);

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    Stack *stacks = malloc(sizeof(Stack) * n);
    for (int i = 0; i < n; i++) {
        stacks[i].top = NULL;
        push(&stacks[i], i + 1);
    }
    while (m--) {
        int pre, lat;
        scanf("%d%d", &pre, &lat);
        pre -= 1;
        lat -= 1;
        // 由于栈的标号是从0开始的
        Stacknode *node1 = popAll(&stacks[pre]);
        append(&stacks[lat], node1);
    }
    for (int i = 0; i < n; i++) {
        printStack(&stacks[i]);
        freeStack(&stacks[i]);
    }
    free(stacks);
    return 0;
}

void push(Stack *stack, int val)
{
    Stacknode *newnode = malloc(sizeof(Stacknode));
    newnode->val = val;
    newnode->next = stack->top;
    stack->top = newnode;
}

void append(Stack *stack, Stacknode *node)
{
    if (stack->top == NULL) {
        stack->top = node;
    } else {
        Stacknode *cur = stack->top;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = node;
    }
}

Stacknode *popAll(Stack *stack)
{
    Stacknode *temp = stack->top;
    stack->top = NULL;
    return temp;
}

void printStack(Stack *stack)
{
    if (stack->top == NULL) {
        printf("0\n");
    }
    Stacknode *cur = stack->top;
    while (cur) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

void freeStack(Stack *stack)
{
    Stacknode *cur = stack->top;
    while (cur) {
        Stacknode *p = cur;
        cur = cur->next;
        free(p);
    }
}