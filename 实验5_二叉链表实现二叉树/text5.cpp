#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR  0
#define OVERFLOW -2
//数据结构定义
typedef  int  Status;
typedef  int TElemType;   //数据元素为整型
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//函数声明
int menu_select();
Status InitBiTree(BiTree &T);
Status CreateBiTree(BiTree &T);
void PreOrderTraverse(BiTree T,Status(*Visit)(TElemType));
void PreOrderTraverse2(BiTree T,Status(*Visit)(TElemType));
void PreOrderTraverse3(BiTree T,Status(*Visit)(TElemType));
Status PrintElem(TElemType e);
void DisplayTree(BiTree T,int i);
Status BiTreeDepth(BiTree T);
void destroyBst(BiTree T);
void serach(BiTree T,int i);

void input(TElemType a[],int n);
void output(TElemType a[],int n);
int Locate(TElemType a[],TElemType ch,int m,int n);
Status Create(BiTree &T,TElemType pre[],TElemType in[],int m,int n,int len);
int WPL(BiTree T,int i);
int DegreeZero(BiTree T);
int DegreeOne(BiTree T);
int DegreeTwo(BiTree T);

//主函数
int main()
{
	BiTree T;
	Status s;
	TElemType pre[10],in[10];
	int len,wpl,n0,n1,n2,i;
	for(;;)
	{
		switch(menu_select())
		{
		case 1:
			s=InitBiTree(T);
			if(s)
				printf("初始化成功\n");
			else
				printf("初始化失败\n");
			break;
		case 2:
			printf("请输入二叉树的扩展先序序列：");			
			s=CreateBiTree(T);
			if(s)
				printf("创建成功\n");
			else
				printf("创建失败\n");
			break;
		case 3:
			printf("先序遍历序列为：\n");
			PreOrderTraverse(T,PrintElem);			
			break;
		case 4:
			printf("输出中序遍历序列\n");
			PreOrderTraverse2(T,PrintElem);
			break;
		case 5:
			printf("输出后序遍历序列\n");
			PreOrderTraverse3(T,PrintElem); 
			break;
		case 6:printf("凹入显示\n");
			DisplayTree(T,0);
			break;
		case 7:
			printf("求二叉树叶子结点的个数\n");
			n0=DegreeZero(T);
			printf("度为0的结点个数为%d.\n",n0);
			break;
		case 8:
			s=BiTreeDepth(T); 
		    printf("二叉树深度为：%d\n",s);
			break;
		case 9:
			printf("查找给定值:\n");
			scanf("%d",&i);
			serach(T,i);
			break;
		case 10:
			destroyBst(T);
			if(T)
				printf("销毁二叉树成功\n");
		    else 
		        printf("销毁二叉树失败\n");
			break;
		case 11:	
			printf("请输入二叉树的结点个数：");	
			scanf("%d",&len);
			printf("请输入二叉树的先序序列%d个元素：",len);
			input(pre, len);	output(pre,len);
			printf("请输入二叉树的中序序列%d个元素：",len);	
			input(in, len);		output(in,len);
			s=Create(T, pre, in, 0, 0, len);
			if(s)
				printf("创建成功\n");
			else
				printf("创建失败\n");
			break;
		case 12:
			printf("求带权路径长度");
			wpl=WPL(T,0);
			printf("带权路径长度为%d.\n",wpl);
			break;
		case 13:
			n1=DegreeOne(T) ; 
			printf("度为1的结点个数为%d.\n",n1);
			break;
		case 14:
			n2=DegreeTwo(T) ; 
			printf("度为2的结点个数为%d.\n",n2);
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
	printf("1.初始化一个空树（空树）\n");
	printf("2.用扩展的先序序列的方式创建二叉树\n");
	printf("3.输出先序遍历序列\n");
	printf("4.输出中序遍历序列\n");	
	printf("5.输出后序遍历序列\n");
	printf("6.凹入显示二叉树（中序）删除\n");	
	printf("7.求二叉树的叶结点的个数查找\n");
	printf("8.求二叉树的深度查找\n");	
	printf("9.查找二叉树中的某个给定值\n");
	printf("10.销毁二叉树\n");
	printf("11.已知先序，中序遍历序列，构造二叉树\n");
	printf("12.计算代权路径长度\n");
	printf("13.求度为1的结点的个数\n");
	printf("14.求度为2的结点的个数\n");
	printf("0.退出\n");
	printf("输入 0-14:");
	for(;;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>14)
			printf("\n输入错误，重选0－14：");
		else
			break;
	}
	return sn;
}
//初始化函数定义
Status InitBiTree(BiTree &T)
{
	T=NULL;
	return OK;
}
//创建二叉树
Status CreateBiTree(BiTree &T)
{
	TElemType ch;
	scanf("%d",&ch);
	if(ch==0)	  //输入为0的元素 
		T=NULL;
	else 
	{
		T=(BiTNode *)malloc(sizeof(BiTNode));
		if(!T)
			exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}
//先序遍历
void PreOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	if(T)
	{
		Visit(T->data); // 先访问根结点
		PreOrderTraverse(T->lchild,Visit);     
		PreOrderTraverse(T->rchild,Visit); 
	} 
}
//中序遍历 
void PreOrderTraverse2(BiTree T,Status(*Visit)(TElemType))
{
	if(T)
	{
		PreOrderTraverse2(T->lchild,Visit);     
		Visit(T->data); // 中访问根结点
		PreOrderTraverse2(T->rchild,Visit); 
	} 
}
//后序遍历
void PreOrderTraverse3(BiTree T,Status(*Visit)(TElemType))
{
	if(T)
	{
		PreOrderTraverse3(T->lchild,Visit);     
		PreOrderTraverse3(T->rchild,Visit);
		Visit(T->data); // 后访问根结点
	} 
} 
//打印一个数据元素函数
Status PrintElem(TElemType e)
{
	printf("%d\t",e);
	return OK;
}
//中序凹入显示
void DisplayTree(BiTree T,int i)
{
	int j;
	if (T == NULL) return;
	if(T->lchild!=NULL)
		DisplayTree(T->lchild,i+1); 	
	for(j=1;j<=i;j++) 	
		printf("\t");
	printf("       %d",T->data);
	for(j=i+1;j<=8;j++)		
		printf("--------");
	printf("\n");
	if(T->rchild!=NULL)
		DisplayTree(T->rchild,i+1);
}
//输入遍历序列数组
void input(TElemType a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
//输出输入的数组
void output(TElemType a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
//定位根结点的下标
int Locate(TElemType a[],TElemType ch,int m,int len)
{
	int i=m;
	while(i<m+len&&a[i]!= ch)
	{
		i++;
	}
	return i;
}
//已知先序、中序序列，构造二叉树
Status Create(BiTree &T,TElemType pre[],TElemType in[],int m,int n,int len)
{
	TElemType ch;
	int i,j;
	if(!len)
	{
		T=NULL; 
		return OK;			
	}
	else
	{
		ch=pre[m];	
		T=(BiTree)malloc(sizeof(TElemType));
		T->data=ch;	
		i=Locate(in,ch, n, len);
		j=i-n;  
		Create(T->lchild,pre,in,m+1,n,j);
		Create(T->rchild,pre,in,m+j+1,i+1,len-j-1);
		return OK;
	}
}
//计算代权路径长度
int WPL(BiTree T,int i)   
{ 
	if(T){
		if ((T->lchild==NULL)&&(T->rchild==NULL))
			return i*T->data;
		else 
			return WPL(T->lchild,i+1)+WPL(T->rchild,i+1);
	}
	else return 0;
} 
//计算度为0的结点的个数
int DegreeZero(BiTree T){
	int n0,ln0,rn0;
	if(!T) n0=0;
	else{
		ln0=DegreeZero(T->lchild);
		rn0=DegreeZero(T->rchild);
		if ((!T->lchild)&&(!T->rchild))
				n0=ln0+rn0+1;
			else
				n0=ln0+rn0;
	}
	return n0;
}
//计算度为1的结点的个数
int DegreeOne(BiTree T)   
{ 
	int n1,ln1,rn1;
	if(!T) n1=0;
	else
	{		
			ln1=DegreeOne(T->lchild);
			rn1=DegreeOne(T->rchild);
			if (T->lchild&&(!T->rchild)||(!T->lchild)&&(T->rchild))
				n1=ln1+rn1+1;
			else
				n1=ln1+rn1;		
	}
	return n1; 
}

//计算度为2的结点的个数
int DegreeTwo(BiTree T)   
{ 
	int n2,ln2,rn2;
	if(!T) n2=0;
	else
	{		
			ln2=DegreeTwo(T->lchild);
			rn2=DegreeTwo(T->rchild);
			if (T->lchild&&T->rchild)
				n2=ln2+rn2+1;
			else
				n2=ln2+rn2;		
	}
	return n2;
}
//二叉树的深度
Status BiTreeDepth(BiTree T){
    int lDepth = 0, rDepth = 0;
    if(T==NULL){
        return 0;
    }
    else{
        lDepth = BiTreeDepth(T->lchild);
        rDepth = BiTreeDepth(T->rchild);
    }
    return lDepth > rDepth?lDepth+1:rDepth+1;
}
//销毁树 
void destroyBst(BiTree T)
{
    if(T){
        destroyBst(T->lchild);
        destroyBst(T->rchild);
        free(T);
    }
}
//查找给定值
void serach(BiTree T,int i){
	if(T!=NULL){
		if(T->data==i){
			printf("查找到此数");
		}
		else{
			serach(T->lchild,i);
			serach(T->rchild,i);
		}
	}
}
