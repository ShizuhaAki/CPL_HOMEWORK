#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *next;
    struct node *pre;
    struct node *last_same;
} Node;

void append(char val);
char *query(int k);

Node *head = NULL;
Node *tail = NULL;

int main()
{
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        char s[2000005] = {0};
        scanf("%s", s);
        if (s[0] == '?') {
            // ²éÑ¯
            int k;
            scanf("%d", &k);
            char *answer = query(k);
            printf("%s\n", answer);
            free(answer);
        } else {
            // ×·¼Ó
            char *p = s;
            while (*p != '\0') {
                append(*p);
                // printf("finish %c\n", *p);
                p++;
            }
        }
    }
    while (head != NULL) {
        Node *p = head;
        head = head->next;
        free(p);
    }
    return 0;
}

void append(char val)
{
    Node *cur = head;
    if (head == NULL) {
        if (val == 'm' || val == 'M')
            return;
        cur = malloc(sizeof(Node));
        cur->data = val;
        cur->pre = NULL;
        cur->next = NULL;
        head = cur;
        tail = cur;
        // cur->last_same = NULL;
    } else {
        // printf("reach here\n");
        // while (cur->next != NULL) {
        //     cur = cur->next;
        // }
        cur = tail;
        // printf("%c\n", cur->data);
        if (val == 'm') {
            Node *p = cur;
            if (cur->data >= 'a' && cur->data <= 'z') {
                cur = cur->pre;
                free(p);
                p = NULL;
                tail = cur;
                if (cur != NULL)
                    cur->next = NULL;
                else {
                    head = NULL;
                }
            } else {
                while (p != NULL && (p->data < 'a' || p->data > 'z')) {
                    p = p->pre;
                }
                if (p == NULL) {
                    return;
                } else if (p->pre == NULL) {
                    Node *temp = head;
                    head = head->next;
                    free(temp);
                    head->pre = NULL;
                } else {
                    Node *p_pre = p->pre, *p_next = p->next;
                    p_pre->next = p_next;
                    p_next->pre = p_pre;
                    free(p);
                }
            }
        } else if (val == 'M') {
            Node *p = cur;
            if (cur->data >= 'A' && cur->data <= 'Z') {
                cur = cur->pre;
                free(p);
                p = NULL;
                tail = cur;
                if (cur != NULL)
                    cur->next = NULL;
                else {
                    head = NULL;
                }
            } else {
                while (p->data < 'A' || p->data > 'Z') {
                    p = p->pre;
                }
                if (p == NULL) {
                    return;
                } else if (p->pre == NULL) {
                    Node *temp = head;
                    head = head->next;
                    free(temp);
                    head->pre = NULL;
                } else {
                    Node *p_pre = p->pre, *p_next = p->next;
                    p_pre->next = p_next;
                    p_next->pre = p_pre;
                    free(p);
                }
            }
        } else {
            Node *newnode = malloc(sizeof(Node));
            newnode->next = NULL;
            newnode->data = val;
            newnode->pre = cur;
            cur->next = newnode;
            cur = cur->next;
            tail = cur;
        }
    }
}

char *query(int k)
{
    char *ans = malloc(sizeof(char) * (k + 1));
    ans[k] = '\0';
    Node *cur = tail;
    // while (cur->next != NULL) {
    //     cur = cur->next;
    // }
    while (k > 0) {
        ans[k - 1] = cur->data;
        cur = cur->pre;
        k--;
    }
    return ans;
}