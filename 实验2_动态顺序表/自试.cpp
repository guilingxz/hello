//预编译命令
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 10  //表春初空间的初始分配量
#define LISTINCREMENT 2    //线性表春初空间的分配增量
//数据结构
typedef int Status;
typedef int ElemType;
typedef struct
{
    ElemType *elem;  //存储空间基址
    int lenght；
    int listsize       //当前长度
