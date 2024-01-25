#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[15];
    struct node *father;
    // struct node *itself;
    struct node *son1;
    struct node *son2;
} Node;

Node *head;
Node *search(Node *start, char *s);
void Freelist(Node *start);
int Query(Node *start);

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    while (n--) {
        char s1[20], s2[20];
        scanf("%s%s", s1, s2);
        Node *new = malloc(sizeof(Node));
        strcpy(new->name, s1);
        new->father = NULL;
        new->son1 = NULL;
        new->son2 = NULL;
        if (strcmp(s2, "~~~") == 0) {
            head = new;
        } else {
            Node *p = search(head, s2);
            // printf("p->s = %s(s2)\n", p->name);
            if (p->son1 == NULL) {
                p->son1 = new;
                new->father = p;
            } else {
                p->son2 = new;
                new->father = p;
            }
            // printf("father: %s\n", p->father->name);
            // printf("%s\n", p->name);
            // printf("son1: %s\n", p->son1->name);
            // printf("p->son1 == NULL:%d, p->son2 == NULL:%d\n", p->son1 == NULL, p->son2 == NULL);
        }
    }
    while (q--) {
        char s1[10], s2[20];
        scanf("%s%s", s1, s2);
        if (strcmp(s1, "query") == 0) {
            Node *cur = search(head, s2);
            printf("%d\n", Query(cur));
        } else if (strcmp(s1, "remove") == 0) {
            Node *cur = search(head, s2);
            // printf("%s\n", cur->name);
            // printf("father: %s\n", cur->father->name);
            // printf("son1: %s\nson2: %s\n", cur->father->son1->name, cur->father->son2->name);
            if (cur->father == NULL) {
                head = NULL;
                Freelist(head);
            } else {
                if (cur->father->son1 != NULL && strcmp(cur->father->son1->name, s2) == 0) {
                    cur->father->son1 = NULL;
                    Freelist(cur);
                } else {
                    cur->father->son2 = NULL;
                    Freelist(cur);
                }
            }
        }
    }
    if (head != NULL) {
        Freelist(head);
    }
    return 0;
}

Node *search(Node *start, char *s)
{
    if (start == NULL) {
        return NULL;
    } else {
        if (strcmp(start->name, s) == 0) {
            return start;
        } else {
            Node *p1 = search(start->son1, s);
            Node *p2 = search(start->son2, s);
            return (p1 == NULL) ? p2 : p1;
        }
    }
}

void Freelist(Node *start)
{
    if (start == NULL) {
        return;
    }
    Freelist(start->son1);
    Freelist(start->son2);
    free(start);
}

int Query(Node *start)
{
    if (start == NULL)
        return 0;
    // int cnt = 0;
    // cnt += Query(start->son1);
    // cnt += Query(start->son2);
    // cnt += 1;
    // return cnt;
    return 1 + Query(start->son1) + Query(start->son2);
}