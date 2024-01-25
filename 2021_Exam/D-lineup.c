#include <stdio.h>
#include <stdlib.h>
#define N 2505
typedef long long ll;

typedef struct node {
    int val;
    struct node *right, *down;
} Node;

Node *LineHead[N];
int m, n, q;

Node *buildLine(int lineID);
void linkDown(Node *p1, Node *p2);
Node *getnode(int x, int y);
ll getSum(int pos);
void goAndSwap(Node *p1, Node *p2, int len, int t);
// t = 1: go right; t = 0: go down;
void myswap(Node **p1, Node **p2);

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i <= n; i++) {
        LineHead[i] = buildLine(i);
        if (i >= 1) {
            linkDown(LineHead[i - 1], LineHead[i]);
        }
    }
    // printf("finish\n");
    while (q--) {
        int x1, y1, x2, y2, x3, y3, x4, y4, pos;
        scanf("%d%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &pos);
        Node *x1__y1_1 = getnode(x1, y1 - 1);
        Node *x3__y3_1 = getnode(x3, y3 - 1);
        Node *x1_1__y1 = getnode(x1 - 1, y1);
        Node *x3_1__y3 = getnode(x3 - 1, y3);
        Node *x2__y1 = getnode(x2, y1);
        Node *x4__y3 = getnode(x4, y3);
        Node *x1__y2 = getnode(x1, y2);
        Node *x3__y4 = getnode(x3, y4);
        goAndSwap(x1__y1_1, x3__y3_1, x2 - x1 + 1, 0);
        goAndSwap(x1_1__y1, x3_1__y3, y2 - y1 + 1, 1);
        goAndSwap(x2__y1, x4__y3, y2 - y1 + 1, 1);
        goAndSwap(x1__y2, x3__y4, x2 - x1 + 1, 0);
        printf("%lld\n", getSum(pos));
    }
    return 0;
}

Node *buildLine(int lineID)
{
    Node *head = malloc(sizeof(Node));
    Node *tmp = head;
    for (int i = 1; i <= m; i++) {
        tmp->right = malloc(sizeof(Node));
        tmp->right->val = lineID * m + i;
        tmp = tmp->right;
    }
    return head;
}

void linkDown(Node *p1, Node *p2)
{
    for (int k = 0; k <= m; k++) {
        p1->down = p2;
        p1 = p1->right;
        p2 = p2->right;
    }
}

Node *getnode(int x, int y)
{
    Node *p = LineHead[x];
    for (int i = 1; i <= y; i++) {
        p = p->right;
    }
    return p;
}

ll getSum(int pos)
{
    ll res = 0;
    Node *p = LineHead[pos]->right;
    for (int i = 1; i <= m; i++) {
        res += p->val;
        p = p->right;
    }
    return res;
}

void myswap(Node **p1, Node **p2)
{
    Node *tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void goAndSwap(Node *p1, Node *p2, int len, int t)
{
    if (t == 0) {
        for (int i = 0; i < len; i++) {
            myswap(&(p1->right), &(p2->right));
            p1 = p1->down, p2 = p2->down;
        }
    } else {
        for (int i = 1; i <= len; i++) {
            myswap(&(p1->down), &(p2->down));
            p1 = p1->right, p2 = p2->right;
        }
    }
}