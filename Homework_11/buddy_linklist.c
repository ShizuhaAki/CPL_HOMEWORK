#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int id;
    int size;
    struct node *next;
} Node;

Node *head, *beforehead;
void Insert(int newid, int newsize);

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    getchar();
    head = malloc(sizeof(Node));
    head->id = 0;
    head->next = NULL;
    head->size = n;
    beforehead = malloc(sizeof(Node));
    beforehead->id = 0;
    beforehead->next = head;
    beforehead->size = 0;
    while (q--) {
        // printf("q = %d\n", q);
        char c;
        scanf("%c", &c);
        if (c == 'A') {
            int newid, newsize;
            scanf("%d%d", &newid, &newsize);
            Insert(newid, newsize);
        } else if (c == 'Q') {
            Node *cur = beforehead->next;
            int cnt = 0;
            while (cur != NULL) {
                cur = cur->next;
                cnt++;
            }
            printf("%d\n", cnt);
            cur = beforehead->next;
            while (cur != NULL) {
                printf("%d ", cur->id);
                cur = cur->next;
            }
            printf("\n");
        }
        getchar();
    }
    return 0;
}

void Insert(int newid, int newsize)
{
    Node *cur = beforehead, *pre = NULL;
    // int flagFinish = 0;
    int newsizeNumber = 0;
    while (pow(2, newsizeNumber) < newsize) {
        newsizeNumber++;
    }
    while (cur->next != NULL) {
        pre = cur;
        cur = cur->next;
        if (cur->id != 0) {
            continue;
        }
        if (cur->size < newsizeNumber) {
            continue;
        } else if (cur->size == newsizeNumber) {
            cur->id = newid;
            return;
        } else {
            int originSize = cur->size - 1;
            cur->size = originSize;
            Node *newnode = malloc(sizeof(Node));
            newnode->next = cur->next;
            newnode->id = 0;
            newnode->size = originSize;
            cur->next = newnode;
            cur = pre;
        }
    }
}