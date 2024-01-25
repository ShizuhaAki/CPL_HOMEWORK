/*
 *  悲！！！
 *  本来是准备跟着助教代码重新写的，因为找不到自己哪里错了
 *  然而看视频的第一眼就发现了：
 *  自己数组开小了、、、
 *  所以显示运行错误(数组越界了！！！)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define B 2000

typedef struct node {
    char arr[B];
    int index;
    struct node *next;
} Node;

Node *head;
Node *initlist(char *s);
void PrintList();
void Freelist();
void Query(int index);
void Insert(int pos, char *str);
void split(Node *pre, Node **cur, int diff);
void merge();

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    char *s = malloc(sizeof(char) * (n + 3));
    scanf("%s", s);
    head = initlist(s);
    free(s);
    while (q--) {
        char ch;
        getchar();
        scanf("%c", &ch);
        if (ch == 'Q') {
            int index;
            scanf("%d", &index);
            Query(index);
        } else if (ch == 'I') {
            int pos;
            char str[100005];
            scanf("%d%s", &pos, str);
            Insert(pos, str);
            // PrintList();
        }
    }
    Freelist();
    return 0;
}

Node *initlist(char *s)
{
    char *p = s;
    Node *dummy = malloc(sizeof(Node)), *cur = dummy;
    int len = strlen(s);
    int num = len / B;
    num = (len % B == 0) ? num : (num + 1);
    for (int i = 0; i < num; i++) {
        Node *new = malloc(sizeof(Node));
        new->index = 0;
        for (int j = 0; j < B; j++) {
            if (*p != '\0') {
                new->arr[j] = *p;
                p++;
                new->index++;
            } else {
                break;
            }
        }
        new->next = NULL;
        cur->next = new;
        cur = cur->next;
    }
    Node *head1 = dummy->next;
    free(dummy);
    return head1;
}

void PrintList()
{
    Node *p = head;
    while (p) {
        for (int i = 0; i < p->index; i++) {
            printf("%c", p->arr[i]);
        }
        p = p->next;
    }
    printf("\n");
}

void Freelist()
{
    Node *p = head;
    while (p != NULL) {
        Node *q = p;
        p = p->next;
        free(q);
    }
}

void Query(int index)
{
    int cnt = 0, cnt_pre = 0;
    Node *cur = head, *pre = NULL;
    while (cnt < index) {
        if (cur != NULL) {
            cnt_pre = cnt;
            cnt += cur->index;
            pre = cur;
            cur = cur->next;
        }
    }
    int diff = index - cnt_pre;
    printf("%c\n", pre->arr[diff - 1]);
}

void Insert(int pos, char *str)
{
    Node *newHead = initlist(str);
    Node *p_newhead = newHead;
    while (p_newhead->next != NULL) {
        p_newhead = p_newhead->next;
    }
    if (pos == 0) {
        p_newhead->next = head;
        head = newHead;
        return;
    }
    int cnt = 0, cnt_pre = 0;
    Node *cur = head, *pre = NULL;
    while (cnt < pos) {
        if (cur != NULL) {
            cnt_pre = cnt;
            cnt += cur->index;
            pre = cur;
            cur = cur->next;
        }
    }
    int diff = pos - cnt_pre;
    if (diff != pre->index) {
        split(pre, &cur, diff);
    }
    pre->next = newHead;
    p_newhead->next = cur;
    merge();
}

void split(Node *pre, Node **cur, int diff)
{
    Node *latter = *cur;
    *cur = malloc(sizeof(Node));
    (*cur)->next = latter;
    (*cur)->index = pre->index - diff;
    pre->index = diff;
    pre->next = (*cur);
    for (int i = 0; i < (*cur)->index; i++) {
        (*cur)->arr[i] = pre->arr[pre->index + i];
        pre->arr[pre->index + i] = 0;
    }
}

void merge()
{
    Node *cur = head;
    if (cur == NULL || cur->next == NULL) {
        return;
    }
    while (cur->next != NULL) {
        if (cur->index + cur->next->index > B) {
            cur = cur->next;
        } else {
            for (int i = 0; i < cur->next->index; i++) {
                cur->arr[i + cur->index] = cur->next->arr[i];
            }
            cur->index += cur->next->index;
            Node *tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
        }
    }
}