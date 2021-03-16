#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>

#define TURE 1
#define FLASE 0
#define ERROR 0
#define OVERFLOW -2
#define OK 1
#define INFLASEBLE -1
#define MaxSize 2500
#define Size 50
typedef int ElemType;
typedef int Status;
typedef struct {
	ElemType i;
	ElemType j;
	ElemType pre;
} LNode;
typedef struct {
	LNode data[MaxSize];
	ElemType front,rear;
} SqQueue;
Status InitQueue(SqQueue *Q) { //建立队列，使front，rear都指向0
	Q->front=0;
	Q->rear=0;
	return OK;
}
Status EnQueue(SqQueue *Q,ElemType x,ElemType y) { //坐标进队列
	(Q->data[Q->rear]).i=x;
	(Q->data[Q->rear]).j=y;
	(Q->data[Q->rear]).pre=Q->front;
	Q->rear++;
	return OK;
}
Status QueueEmpty(SqQueue Q) { //判断是否为空，空为假，不空为真
	if(Q.front==Q.rear) return FLASE;
	else return TURE;
}
//以上为队列
typedef struct {
	ElemType data[Size];
	ElemType top;
} SqStack;
Status InitStack(SqStack *S) { //使top的指针指向-1
	S->top=-1;
	return OK;
}
Status Push(SqStack *S,ElemType e) { //使栈顶的元素为e
	S->top++;
	S->data[S->top]=e;
	return OK;
}
ElemType Pop(SqStack *S,ElemType *e) { //使栈顶的元素出栈，且返回值为e
	*e=S->data[S->top];
	S->top--;
	return *e;
}
//以上为栈
Status PrintMigong(ElemType (*MAZE)[Size],ElemType m,ElemType n) {//打印迷宫
	ElemType i,j;
	printf("迷宫如下:\n");
	for(j=0; j<n+2; j++) {
		for(i=0; i<m+2; i++) {
			if(j==0) printf("%d ",i);
			else if(i==0) printf("%d",-j);
			else if(MAZE[i][j]==0)
				printf("□",MAZE[i][j]);
			else printf("■",MAZE[i][j]);
		}
		printf("\n");
	}
	return OK;
}
Status CreatMigong(ElemType (*MAZE)[Size],ElemType (*MARK)[Size],ElemType m,ElemType n) { //构造迷宫
	srand(time(NULL));
	ElemType i,j;
	for(i=0; i<m+2; i++)
		for(j=0; j<n+2; j++) {
			if(i==0||i==m+1||j==0||j==n+1)MAZE[i][j]=1;//建立围墙
			else MAZE[i][j]=rand()%2;//给迷宫的内部赋予随机数0或1
		}
	MAZE[1][1]=0,MAZE[m][n]=0;
	MARK[1][1]=1;//标记第一个点已经走
	return OK;
}
Status PrintPath(SqStack S,SqQueue Q,ElemType m,ElemType n) {//显示路径
	ElemType l,e;
	for(l=S.top; l>=0; l--) {
		Pop(&S,&e);
		printf("(%-2d,%-2d) -> ",Q.data[e].i,-Q.data[e].j);
	}
	printf("(%-2d,%-2d)\n",m,-n);
	return OK;
}
Status Sloution() {
	ElemType k,p,flag=0;
	ElemType nexti=1,nextj=1;
	//建立了队列Q，栈S
	SqQueue Q;
	SqStack S;
	InitQueue(&Q);
	InitStack(&S);
	ElemType Direction[8][2]= {{1,1},{0,1},{1,0},{-1,1},{1,-1},{0,-1},{-1,0},{-1,-1}};
	//用二维数组Direction存放八个方向上的位置偏移量
	ElemType MAZE[Size][Size]= {0}; //建立一个数组用于容纳迷宫
	ElemType MARK[Size][Size]= {0}; //建立一个标记是否走过的数组
	ElemType m,n;
	printf("请输入迷宫的行和列:");
	scanf("%d%d",&m,&n);//输入迷宫的行和列
	CreatMigong(MAZE,MARK,m,n);
	//打印迷宫
	PrintMigong(MAZE,m,n);
	//把起始点进入队列
	EnQueue(&Q,1,1);
	while(QueueEmpty(Q)) {
		for(k=0; k<8; k++) {//判断八个方向是否有可以走的，有就压进队列
			nexti=Q.data[Q.front].i+Direction[k][0];
			nextj=Q.data[Q.front].j+Direction[k][1];
			if(MAZE[nexti][nextj]||MARK[nexti][nextj]);
			else {
				MARK[nexti][nextj]=1;
				EnQueue(&Q,nexti,nextj);
				if(nexti==m&&nextj==n) { //一旦发现了出口，就退出循环
					flag=1;
					break;
				}
			}
		}
		Q.front++;//每判断完之后，头指针要加一
		if(flag==1) {//如果找到出口就压进栈中
			p=Q.rear-1;
			while(p) {
				p=Q.data[p].pre;
				Push(&S,p) ;
			}
			break;
		}
	}
	//输出迷宫路径
	printf("走出迷宫最短路经如下:\n");
	if(QueueEmpty(Q)) { //如果不是因为队列退出循环的，就把栈中的元素输出
		PrintPath(S,Q,m,n);
	} else printf("No path!\n");
	return OK;
}
int main() {
	while(1) {
		Sloution();
	}
	return 0;
}
/*迷宫问题。假设迷宫由m行n列构成，有一个入口和一个出口，入口坐标为（1，1），出口坐标为（m，n），试设计并验证以下算法：找出一条从入口通往出口的路径，或报告一个“无法通过”的信息。
(1) 用C语言实现顺序存储结构上队列的基本操作，然后利用该队列的基本操作找出迷宫的一条最短路径。
(2) 设计一个二维数组MAZE[m+2][n+2]表示迷宫，数组元素为0表示该位置可以通过，数组元素为1表示该位置不可以通行。MAZE[1][1]、MAZE[m][n]分别为迷宫的入口和出口。
(3) 输入迷宫的大小m行和n列，动态生成二维数组；由随机数产生0或1，建立迷宫，注意m*n的迷宫需要进行扩展，扩展部分的元素设置为1，相当于在迷宫周围布上一圈不准通过的墙。
(4) 要求输出模拟迷宫的二维数组；若存在最短路经，则由出口回溯到入口（出队列并利用栈实现），再打印从入口到出口的这条路径，例如(1,1)，……，(i,j)，……，(m,n)；若没有路径，则打印“No path!”。
(5) 迷宫的任一位置(i,j)上均有八个可以移动的方向，用二维数组Direction存放八个方向上的位置偏移量。
Direction[8][2]={{0,1},{1,1},{0,-1},{-1,-1},{1,1},{0,-1},{-1,-1},{0,1}};
(6) 为避免出现原地踏步的情况为了标志已经通过的位置，采用一个标志数组MARK[m+2][n+2]，初值均为0，在寻找路径的过程中，若通过了位置(i,j)，则将MARK[i][j]置为1。
(7) 为了记录查找过程中到达位置(i,j)及首次到达(i,j)的前一位置(i_pre,j_pre)，需要记住前一位置(i_pre,j_pre)在队列中的序号pre，即队列中数据元素应该是一个三元组(i,j,pre)。
(8) 搜索过程简单描述如下：将入口MAZE[1][1]作为第一个出发点，依次在八个方向上搜索可通行的位置，将可通行位置(i,j,pre)入队，形成第一层新的出发点，然后依次出队，即对第一层中各个位置分别搜索
它所在八个方向上的可通行位置，形成第二层新的出发点，…，如此进行下去，直至达到出口MAZE[m][n]或者迷宫所有位置都搜索完毕为止。*/