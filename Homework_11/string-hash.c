#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 500005
#define MAX_LEN_SINGAL 1005
#define N 500000

typedef struct node {
    char *s;
    struct node *next;
} Node;

int hash(char *s);
void add(Node *head, char *s);
void Freelist(Node **head);
void Freelinklist(Node *head);
int find(Node *head, char *str);

int main()
{
    int m, q;
    scanf("%d%d", &m, &q);
    Node **list = malloc(sizeof(Node *) * N);
    for (int i = 0; i < N; i++) {
        list[i] = malloc(sizeof(Node));
        list[i]->next = NULL;
        list[i]->s = malloc(sizeof(char) * 10);
        strcpy(list[i], "");
    }
    char *str = malloc(sizeof(char) * MAX_LEN_SINGAL);
    for (int k = 1; k <= m; k++) {
        scanf("%s", str);
        int index = hash(str);
        add(list[index], str);
    }
    for (int k = 1; k <= q; k++) {
        scanf("%s", str);
        int ansIndex = hash(str);
        int ans = find(list[ansIndex], str);
        if (ans) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    // free(str);
    // Freelist(list);
    return 0;
}

int hash(char *s)
{
    int len = strlen(s);
    int ret = 0;
    for (int i = 0; i < len; i++)
        ret = (ret + s[i] * (i + 1)) % N;
    return ret;
}

void add(Node *head, char *s)
{
    Node *new = malloc(sizeof(Node));
    int len = strlen(s);
    new->s = malloc(sizeof(char) * (len + 1));
    strcpy(new->s, s);
    new->next = NULL;

    while (head->next != NULL) {
        head = head->next;
    }
    head->next = new;
}

void Freelist(Node **head)
{
    for (int i = 0; i < N; i++) {
        Freelinklist(head[i]);
        free(head[i]);
    }
}

void Freelinklist(Node *head)
{
    if (head == NULL) {
        return;
    }
    while (head != NULL) {
        Node *pre = head;
        head = head->next;
        free(pre->s);
        free(pre);
    }
}

int find(Node *head, char *str)
{
    while (head != NULL) {
        head = head->next;
        if (head != NULL) {
            if (strcmp(head->s, str) == 0) {
                return 1;
            }
        }
    }
    return 0;
}