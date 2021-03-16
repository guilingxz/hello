#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem(struct ListNode *L, int m);
void printlist(struct ListNode *L)
{
    struct ListNode *p = L;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}

struct ListNode *readlist()
{
    int data;
    struct ListNode *head = NULL, *tail = NULL;
    //head=(struct ListNode *)malloc(sizeof(struct ListNode ));
    //tail=head;

    scanf("%d", &data);
    while (data != -1)
    {
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->data = data;
        p->next = NULL;
        if (tail)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
        }
    }
    return head;
}

struct ListNode *deletem(struct ListNode *L, int m)
{
    struct ListNode *p, *q;
    for (p = L; p != NULL; p = p->next)
    {
        q = p;
        if (p->date == m)
        {
            q->next = p->next;
            free(p);
        }
    }
    return L;
}