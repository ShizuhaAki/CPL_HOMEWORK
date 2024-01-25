#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

int arr[5] = {1, 2, 3, 4, 5};
Node *head;

Node *Init_by_arr(int arr[], int n);
void query(Node *node);
Node *getnode();

int main()
{
    // head = Init_by_arr(arr, 5);
    // query(head);
    head = getnode();
    head->val = 1;
    Node *second = getnode();
    second->val = 2;
    head->next = second;
    return 0;
}

Node *Init_by_arr(int arr[], int n)
{
    Node *dummy = malloc(sizeof(Node));
    Node *new = dummy;
    for (int i = 0; i < n; i++) {
        Node *newnode = malloc(sizeof(Node));
        newnode->val = arr[i];
        newnode->next = NULL;
        new->next = newnode;
        new = new->next;
    }
    return dummy->next;
}

void query(Node *node)
{
    Node *now = node;
    while (now) {
        printf("%d ", now->val);
        now = now->next;
    }
}

Node *getnode()
{
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->val = 0;
    return node;
}