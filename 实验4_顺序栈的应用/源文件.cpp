//预编译命令
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define STACK_INIT_SIZE 10  //顺序栈存储空间的初始分配量
#define STACKINCREMENT 2    // 顺序栈存储空间的分配增量

//数据结构
typedef int Status;
typedef int SElemType;		//完成数制转换
//typedef char SElemType;	//完成括号匹配
typedef struct 
{
	SElemType *base;		// 存储空间基址
	SElemType *top;			// 存储空间基址
	int stacksize;			// 当前分配的存储容量(以sizeof(ElemType)为单位)
}SqStack;

//函数声明
int menu_select(); 
Status InitStack(SqStack &S);
Status CreateStack(SqStack &S,int n);
void PrintStack(SqStack S);
Status GetTop(SqStack S,SElemType &e);
Status Push(SqStack &S,SElemType e);
Status Pop(SqStack &S,SElemType &e);
Status StackEmpty(SqStack S);
Status DestroyStack(SqStack &S);

//主函数
int main()
{
	SqStack S;	
	Status s;
	int n;
	SElemType e;
	for(;;)
	{
		switch(menu_select())
		{
		case 1:
			s=InitStack(S);
			if(s)
				printf("初始化成功\n");
			else
				printf("初始化失败\n");
			break;
		case 2:
			printf("输入栈的长度:");
			scanf("%d",&n);
			s=CreateStack(S,n);
			if(s)
				printf("创建成功\n");
			else
				printf("创建失败\n");
			break;
		case 3:
			PrintStack(S);
			break;
		case 4:			
			s=GetTop(S,e);
			if(s)
				printf("栈顶元素为%d\n",e);
			else
				printf("栈为空，取栈顶元素失败\n");
			break;
		case 5:
			printf("输入入栈的元素值:");
			scanf("%d",&e);
			s=Push(S,e);
			if(s)
				printf("%d入栈成功\n",e);
			else
				printf("入栈失败\n");
			break;
		case 6:
			s=Pop(S,e);
			if(s)
				printf("%d出栈成功\n",e);
			else
				printf("栈为空，出栈失败\n");
			break;	
		case 7:
			s=StackEmpty(S);
			if(s)
				printf("栈为空\n");
			else
				printf("栈不为空\n");
			break;	
			
		case 8:
			s=DestroyStack(S);
			if(s)
				printf("销毁栈成功\n");
			else
				printf("销毁栈失败\n");
			break;	
		case 0:
			printf("程序结束，谢谢使用\n\n"); 
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
	printf("1.初始化栈\n");
	printf("2.创建栈\n");
	printf("3.显示栈\n");
	printf("4.取栈顶元素\n");
	printf("5.入栈\n");
	printf("6.出栈\n");
	printf("7.判断栈空否\n");
	printf("8.销毁栈\n");
	printf("0.退出\n");
	printf("输入 0-8:");
	for(;;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>8)
			printf("\n输入错误，重选0－8：");
		else
			break;
	}
	return sn;
}
// 构造一个最大空间为 STACK_INIT_SIZE的空顺序栈S
Status InitStack (SqStack &S){
	
	S.base=(SElemType *) malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!S.base) exit (OVERFLOW); //存储分配失败
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}
//输入n个元素入栈
Status CreateStack(SqStack &S,int n)
{
	int i;
	if(n>S.stacksize)
		return(ERROR);
	printf("输入%d个整型数:",n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",S.top++);
	}	
	return OK;
}
//输出顺序栈的元素
void PrintStack(SqStack S)
{
	SElemType * p;
	for(p=S.base;p<S.top;p++)
	{
		printf("%d\t",*p);
	}
}
// 栈不空，则用e返回栈顶元素
Status GetTop(SqStack S,SElemType &e)
{
	if(S.top==S.base) 
		return ERROR; 
	e = *(S.top-1);
	return OK;
}
//给定值e入栈
Status Push(SqStack &S,SElemType e)
{ 
	if(S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}
// 若栈不空，则删除S的栈顶元素，
// 用 e 返回其值，并返回OK；
// 否则返回ERROR
Status Pop (SqStack &S, SElemType &e) 
{     
    if (S.top==S.base) 
		return ERROR;
    e = *--S.top;
    return OK;
}
//判断栈空否
Status StackEmpty(SqStack S)
{
	if(S.top==S.base)
		return OK;
	else
		return ERROR;
}
//销毁栈
Status DestroyStack(SqStack &S)
{
	if(!S.base)
		return ERROR;
	free(S.base);
	return OK;
}

