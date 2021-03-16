#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
int menu_select();                                    //菜单
void CreateList_h(LinkList &L, int n);                //头插法建立单链表
void CreateList_t(LinkList &L, int n);                //尾插法建立单链表
void PrintList_L(LinkList L);                         //遍历元素
Status GetElem_L(LinkList &L, int i, ElemType &e);    //得到第i个位置的元素
Status ListInsert_L(LinkList &L, int i, ElemType e);  //向第i个位置插入元素
Status ListDelete_L(LinkList &L, int i, ElemType &e); //删除第i个位置的元素
int LocateElem_L(LinkList L, ElemType e);             //返回元素e的位置
void Free(LinkList &L);                               //销毁链表
int main()
{
    LinkList head;
    int c, i, n, e;
    while (1)
    {
        menu_select();
        scanf("%d", &c);
        switch (c)
        {
        case 0:
            return 0;
            Free(head);
            break;
        case 1:
            printf("请输入你要创建的长度\n");
            scanf("%d", &n);
            CreateList_h(head, n);
            break;
        case 2:
            printf("请输入你要创建的长度\n");
            scanf("%d", &n);
            CreateList_t(head, n);
            break;
        case 3:
            printf("遍历单链表的\n");
            PrintList_L(head);
            break;
        case 4:
            printf("请输入你查找的位序i\n");
            scanf("%d", &i);
            GetElem_L(head, i, e);
            printf("元素是:%d\n", e);
            break;
        case 5:
            printf("删除位序i位置的元素\n");
            scanf("%d", &i);
            if (ListDelete_L(head, i, e))
                printf("删除成功\n删除的元素是:%d\n", e);
            else
                printf("删除失败\n");
            break;
        case 6:
            printf("输入你查找的值\n");
            scanf("%d", &i);
            if (LocateElem_L(head, i) != -1)
            {
                printf("查找成功\n");
                printf("该值的位置是:%d\n", LocateElem_L(head, e));
            }
            else
                printf("查询不到\n");
            break;
        case 7:
            printf("请输入你插入的位置和值\n");
            scanf("%d %d", &i, &e);
            if (ListInsert_L(head, i, e))
                printf("插入成功\n");
            else
                printf("插入失败\n");
        }
    }
}
int menu_select()
{

    printf("0.退出\n");
    printf("1.头插法建立\n");
    printf("2.尾插法建立\n");
    printf("3.输出单链表\n");
    printf("4.查找线性表第i个位序,保存到e\n");
    printf("5.删除指定位序i的元素，并保存到e\n");
    printf("6.查找等于给定值的第一个元素的逻辑位序\n");
    printf("7.插入一个元素到第i个位置\n");
    printf("请输入你的选择\n");
    return 1;
}
void CreateList_h(LinkList &L, int n) //头插法
{
    int i;
    LinkList newnode;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    for (i = 0; i < n; i++)
    {
        printf("请输入第%d元素的值: ", i + 1);
        newnode = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &newnode->data);
        newnode->next = L->next;
        L->next = newnode;
    }
}
void CreateList_t(LinkList &L, int n)
{
    int i;
    LinkList newnode, tail;
    L = (LNode *)malloc(sizeof(LNode));
    tail = L;
    for (i = 0; i < n; i++)
    {
        printf("请输入第%d元素的值: ", i + 1);
        newnode = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &newnode->data);
        tail->next = newnode;
        tail = newnode;
    }
    tail->next = NULL;
}
void PrintList_L(LinkList L)
{
    LinkList p = L->next;
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}
Status GetElem_L(LinkList &L, int i, ElemType &e)
{
    int j = 1;
    LinkList p = L->next;
    while (p != NULL && j < i)
    {
        j++;
        p = p->next;
    }
    if (p == NULL || j > i)
    {
        return ERROR;
    }
    else
    {
        e = p->data;
        return true;
    }
}
Status ListInsert_L(LinkList &L, int i, ElemType e)
{
    int j = 1;
    LinkList p = L->next, newnode;
    while (p != NULL && j < i - 1)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
    {
        return ERROR;
    }
    else
    {
        newnode = (LNode *)malloc(sizeof(LNode));
        newnode->data = e;
        newnode->next = p->next;
        p->next = newnode;
        return true;
    }
}
int LocateElem_L(LinkList L, ElemType e)
{
    LinkList p = L->next;
    int i = 1;
    while (p->data != e && p != NULL)
    {
        i++;
        p = p->next;
    }
    if (p == NULL)
    {
        return -1;
    }
    else
    {
        return i;
    }
}
Status ListDelete_L(LinkList &L, int i, ElemType &e)
{
    int j = 1;
    LinkList p = L->next, q;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p->next == NULL)
    {
        return ERROR;
    }
    if (p != NULL)
    {
        q = p->next;
        e = q->data;
        p->next = q->next;
        free(q);
        return true;
    }
}
void Free(LinkList &L)
{
    LinkList p = L->next, q = p->next;
    while (p != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }
    free(L);
}
