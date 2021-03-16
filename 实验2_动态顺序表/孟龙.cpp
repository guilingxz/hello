//预编译命令
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 10 // 表存储空间的初始分配量
#define LISTINCREMENT 2   // 线性表存储空间的分配增量
typedef int Status;
typedef char ElemType;
typedef struct
{
    ElemType *elem; // 存储空间基址
    int length;     // 当前长度
    int listsize;   // 当前分配的存储容量（以sizeof(ElemType)为单位）
} Sqlist;
//函数声明
int menu_select();                                                              //菜单
Status InitList_Sq(Sqlist &L);                                                  //初始化
Status CreatList_Sq(Sqlist &L, int n);                                          //创建
void PrintList_Sq(Sqlist L);                                                    //打印
Status ListInsert_Sq(Sqlist &L, int i, ElemType e);                             //插入第i个位置
Status ListDelete_Sq(Sqlist &L, int i, ElemType &e);                            //删除第i个位置
int LocateElem_Sq(Sqlist L, ElemType e, Status (*compare)(ElemType, ElemType)); //查找元素e的位置
Status equal(ElemType x, ElemType y);
int EmpytList(Sqlist &L);

int main()
{
    Sqlist L;
    Status s;
    int n, i;
    char e;
    for (;;)
    {
        switch (menu_select())
        {
        case 1:
            s = InitList_Sq(L);
            if (s)
                printf("初始化成功\n");
            else
                printf("初始化失败\n");
            break;
        case 2:
            printf("输入线性表的长度:");
            scanf("%d", &n);
            s = CreatList_Sq(L, n);
            if (s)
                printf("创建成功\n");
            else
                printf("创建失败\n");
            break;
        case 3:
            PrintList_Sq(L);
            break;
        case 4:
            printf("请输入插入的位序:");
            scanf("%d", &i);
            printf("请输入插入的新元素的值:");
            scanf(" %c", &e);
            s = ListInsert_Sq(L, i, e);
            if (s)
                printf("插入成功\n");
            else
                printf("插入失败\n");
            break;
        case 5:
            printf("输入删除的位序:");
            scanf("%d", &i);
            s = ListDelete_Sq(L, i, e);
            if (s)
                printf("删除了元素%d成功\n", e);
            else
                printf("删除失败\n");
            break;
        case 6:
            printf("请输入查找元素的值：");
            scanf("%c", &e);
            i = LocateElem_Sq(L, e, equal);
            if (i)
                printf("%c的逻辑位序是%d\n", e, i);
            else
                printf("查找失败!\n");
            break;
        case 7:
            if (EmpytList(L))
                printf("L为空表\n");
            break;
        case 8:
            printf("L的长度为%d\n", L.length);
            break;
        case 0:
            printf("程序结束，谢谢使用！\n\n");
            exit(0);
        }
    }
    return 0;
}
//菜单函数
int menu_select()
{
    int sn;
    printf("\n显示菜单\n");
    printf("1.初始化\n");
    printf("2.创建\n");
    printf("3.显示\n");
    printf("4.插入\n");
    printf("5.删除\n");
    printf("6.查找\n");
    printf("7.判断是否为空表\n");
    printf("8.返回表的长度\n");
    printf("输入 0-8:");
    for (;;)
    {
        scanf("%d", &sn);
        if (sn < 0 || sn > 8)
            printf("\n输入错误,重选0-8: ");
        else
        {
            break;
        }
    }
    return sn;
}
//初始化空的动态顺序表函数
Status InitList_Sq(Sqlist &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        return (OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}
//创建动态顺序表（输入n个元素）
Status CreatList_Sq(Sqlist &L, int n)
{
    int i;
    if (n > L.listsize)
        return (ERROR);
    printf("输入%d个整型数：", n);
    for (i = 1; i <= n; i++)
    {
        scanf("%c", &L.elem[i - 1]);
    }
    L.length = n;
    return OK;
}
//输出顺序表元素
void PrintList_Sq(Sqlist L)
{
    int i;
    for (i = 1; i <= L.length; i++)
    {
        printf("%c\t", L.elem[i - 1]);
    }
    printf("\n");
}
//插入新元素e到第i个位序
Status ListInsert_Sq(Sqlist &L, int i, ElemType e)
{
    ElemType *newbase, *q, *p;     //类c代码中不含变量定义，需要补充
    if (i < 1 || i > L.length + 1) //插入位置不合法
        return ERROR;
    if (L.length >= L.listsize) //当前储存空间不足
    {
        newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase)
            exit(OVERFLOW);          //存储位置失败
        L.elem = newbase;            //新基址
        L.listsize += LISTINCREMENT; //增加存储位置
    }
    q = &(L.elem[i - 1]); //要插入的位置
    for (p = L.elem + L.length - 1; p >= q; p--)
        *(p + 1) = *p; //插入位置之后的元素右移
    *q = e;
    ++L.length;
    return OK;
} //ListInsert_Sq
//删除第i个元素
Status ListDelete_Sq(Sqlist &L, int i, ElemType &e)
{
    ElemType *p, *q; //补出变量定义
    if ((i < 1) || (i > L.length - 1))
        return ERROR;
    p = &(L.elem[i - 1]);
    e = *p;
    q = L.elem + L.length - 1;
    e + *p;
    q = L.elem + L.length - 1;
    for (++p; p <= q; ++p)
        *(p - 1) = *p;
    --L.length;
    return OK;
}
//查找给定值的位序
int LocateElem_Sq(Sqlist L, ElemType e, Status equal(ElemType, ElemType))
//指向函数类型的指针作为形参
{
    ElemType *p; //补出变量定义
    int i;       //补出变量定义
    i = 1;       //当前元素的逻辑位序
    p = L.elem;  //当前元素的物理地址
    while (i <= L.length && !equal(*(p++), e))
        ++i;
    if (i <= L.length)
        return i;
    else
    {
        return 0;
    }

} //LocateElem_Sq
//判断两个数据元素是否相等的函数
Status equal(ElemType x, ElemType y) //为LocateElem_Sq函数准备第三个实参
{
    if (x == y)
        return OK;
    else
    {
        return ERROR;
    }
}
int EmpytList(Sqlist &L)
{
    if (L.length == 0)
        return 1;
    else
    {
        return 0;
    }
}
int length(Sqlist &L)
{
    return L.length;
}
 

 

 

 

 


