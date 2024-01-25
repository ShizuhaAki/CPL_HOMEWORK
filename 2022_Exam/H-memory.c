#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int l, r;
    bool available;
    int id;
    struct node *next, *pre;
} Node;

Node *head;
int allocCnt = 0;

void Init(int n);
void ualloc(int size);
void ufree(int id);
void display();

int main()
{
    int T, n;
    scanf("%d%d", &T, &n);
    Init(n);
    // display();
    while (T--) {
        int opt;
        scanf("%d", &opt);
        if (opt == 1) {
            int size;
            scanf("%d", &size);
            ualloc(size);
            // display();
        } else if (opt == 2) {
            int id;
            scanf("%d", &id);
            ufree(id);
            // display();
        } else if (opt == 3) {
            display();
        }
    }
    return 0;
}

void Init(int n)
{
    head = malloc(sizeof(Node));
    head->available = true;
    head->l = 0;
    head->r = n;
    head->next = NULL;
    head->pre = NULL;
    head->id = 0;
}

void ualloc(int size)
{
    allocCnt++;
    for (Node *h = head; h != NULL; h = h->next) {
        if (h->available == false)
            continue;
        if (h->r - h->l < size) {
            continue;
        }
        if (h->r - h->l == size) {
            h->id = allocCnt;
            h->available = false;
            printf("%d\n", h->l);
            return;
        }
        Node *new = malloc(sizeof(Node));
        new->l = h->l;
        new->available = false;
        new->r = new->l + size;
        h->l += size;
        new->id = allocCnt;
        if (h->pre != NULL) {
            new->pre = h->pre;
            h->pre->next = new;
            h->pre = new;
            new->next = h;
        } else {
            new->pre = NULL;
            new->next = h;
            h->pre = new;
            head = new;
        }
        printf("%d\n", new->l);
        return;
    }
    printf("malloc fail\n");
}

void ufree(int id)
{
    bool flag = false;
    for (Node *h = head; h != NULL; h = h->next) {
        if (h->id == id && h->available == false) {
            h->available = true;
            h->id = 0;
            flag = true;
            Node *prev = h->pre, *next = h->next;
            if (prev && prev->available == true) {
                h->l = prev->l;
                if (prev->pre == NULL) {
                    h->pre = NULL;
                    head = h;
                } else {
                    h->pre = prev->pre;
                    h->pre->next = h;
                }
            }
            if (next && next->available == true) {
                h->r = next->r;
                if (next->next == NULL) {
                    h->next = NULL;
                } else {
                    h->next = next->next;
                    h->next->pre = h;
                }
            }
            break;
        }
    }
    if (flag == true) {
        printf("free success\n");
    } else {
        printf("free fail\n");
    }
}

void display()
{
    bool flag = true;
    for (Node *h = head; h != NULL; h = h->next) {
        if (h->available == false)
            continue;
        flag = false;
        printf("[%d,%d) ", h->l, h->r);
    }
    if (flag) {
        printf("NULL\n");
    } else {
        printf("\n");
    }
}