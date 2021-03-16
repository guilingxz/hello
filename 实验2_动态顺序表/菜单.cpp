//预编译命令
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 10  //表存储空间的初始分配量
#define LISTINCREMENT 2    // 线性表存储空间的分配增量
//数据结构
typedef int Status;
typedef int ElemType;
typedef struct 
{
	ElemType *elem;  // 存储空间基址
	int length;      // 当前长度
	int listsize;    // 当前分配的存储容量(以sizeof(ElemType)为单位)
} SqList;
//函数声明
int menu_select(); 



//主函数
int main()
{
	
	for(;;)
	{
		switch(menu_select())
		{
		case 1:
			printf("初始化\n");
			
			break;
		case 2:
			printf("创建顺序表\n");
			break;
		case 3:
			printf("输出顺序表\n");
			break;
		case 4:
			printf("调用插入函数\n");
			break;
		case 5:
			printf("调用删除函数\n");
			break;
		case 6:
			printf("调用查找函数\n");
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
	printf("0.退出\n");
	printf("输入 0-6:");
	for(;;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>6)
			printf("\n输入错误，重选0－6：");
		else
			break;
	}
	return sn;
}



