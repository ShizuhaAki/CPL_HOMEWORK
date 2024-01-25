#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char val;
    struct node *next, *prev, *last_same;
} Node;

typedef struct list {
    struct node *head, *tail, *last_upper, *last_lower;
} List;

char s[2000005];
List *nodelist = NULL;

List *InitList();
void add(char c);
void DeleteUpper();
void DeleteLower();
void Query(int k);
void PrintAll();

int main()
{
    int q, k;
    nodelist = InitList();
    scanf("%d", &q);
    while (q--) {
        scanf("%s", s);
        if (s[0] == '?') {
            scanf("%d", &k);
            Query(k);
        } else {
            char *ptr = s;
            while (*ptr != '\0') {
                // printf("%c", *ptr);
                if (*ptr == 'm') {
                    DeleteLower();
                } else if (*ptr == 'M') {
                    DeleteUpper();
                } else {
                    add(*ptr);
                }
                ptr++;
            }
            // PrintAll();
        }
    }
    return 0;
}

List *InitList()
{
    List *list = malloc(sizeof(List));
    list->head = NULL;
    list->last_lower = NULL;
    list->last_upper = NULL;
    list->tail = NULL;
    return list;
}

void add(char c)
{
    Node *newnode = malloc(sizeof(Node));
    if (nodelist->head == NULL) {
        nodelist->head = newnode;
    } else {
        nodelist->tail->next = newnode;
    }
    newnode->prev = nodelist->tail;
    newnode->val = c;
    newnode->next = NULL;
    newnode->last_same = NULL;
    nodelist->tail = newnode;

    if (c >= 'a' && c <= 'z') {
        newnode->last_same = nodelist->last_lower;
        nodelist->last_lower = newnode;
    } else if (c >= 'A' && c <= 'Z') {
        newnode->last_same = nodelist->last_upper;
        nodelist->last_upper = newnode;
    }
}

void DeleteUpper()
{
    Node *p = nodelist->last_upper;
    if (p != NULL) {
        if (p == nodelist->head && p == nodelist->tail) {
            nodelist->head = NULL;
            nodelist->tail = NULL;
        } else if (p == nodelist->head) {
            nodelist->head = p->next;
        } else if (p == nodelist->tail) {
            nodelist->tail = p->prev;
        }
        if (p->prev != NULL)
            p->prev->next = p->next;
        if (p->next != NULL)
            p->next->prev = p->prev;
        nodelist->last_upper = p->last_same;
        free(p);
    }
}

void DeleteLower()
{
    Node *p = nodelist->last_lower;
    if (p != NULL) {
        if (p == nodelist->head && p == nodelist->tail) {
            nodelist->head = NULL;
            nodelist->tail = NULL;
        } else if (p == nodelist->head) {
            nodelist->head = p->next;
        } else if (p == nodelist->tail) {
            nodelist->tail = p->prev;
        }
        if (p->prev != NULL)
            p->prev->next = p->next;
        if (p->next != NULL)
            p->next->prev = p->prev;
        nodelist->last_lower = p->last_same;
        free(p);
    }
}

void Query(int num)
{
    num -= 1;
    Node *p = nodelist->tail;
    while (num--) {
        p = p->prev;
    }
    while (p) {
        printf("%c", p->val);
        p = p->next;
    }
    printf("\n");
}

void PrintAll()
{
    Node *p = nodelist->head;
    while (p) {
        printf("%c", p->val);
        p = p->next;
    }
    printf("\n");
}