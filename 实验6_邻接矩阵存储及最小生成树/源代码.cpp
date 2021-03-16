//预编译命令
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR  0
#define OVERFLOW -2
#define INFINITY 1000
#define MAX_VERTEX_NUM 20
//数据结构
typedef int Status;
typedef int VRType;
typedef char InfoType;
typedef char VertexType;
typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef struct ArcCell { // 弧的定义
	VRType  adj;    // VRType是顶点关系类型
	InfoType  *info;  // 该弧相关信息的指针
} ArcCell,  AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct// 图的定义
{ 
	VertexType  vexs[MAX_VERTEX_NUM]; 
	AdjMatrix    arcs;      // 弧的信息                     
	int    vexnum, arcnum;   // 顶点数，弧数      
	GraphKind   kind;     // 图的种类标志             
} MGraph;

//函数声明
int menu_select();
Status CreateUDN(MGraph &G);
int LocateVex(MGraph G,VertexType v);
void Input(char * & pc);
void DisplayUDN(MGraph G);
void MiniSpanTree_P(MGraph G, VertexType u);
int minimum(MGraph G);
Status JudgeAdj(MGraph G,VertexType v1,VertexType v2);
int VexDegree(MGraph G,VertexType v);

//主函数
int main()
{	
	MGraph G;
	Status s;
	VertexType v1,v2;
	int degree;
	for(;;)
	{
		switch(menu_select())
		{
		case 1:
			printf("创建无向网\n");
			s=CreateUDN(G);
			if(s)
				printf("创建无向网成功\n");
			else
				printf("创建无向网失败\n");
			break;
		case 2:
			printf("输出无向网的顶点数组与邻接矩阵\n");
			DisplayUDN(G);
			break;
		case 3:
			printf("请输入2个顶点信息（以空格隔开）：");
			getchar();	//吸收回车
			scanf("%c %c",&v1,&v2);
			s=JudgeAdj(G, v1, v2);
			if(s)
				printf("%c与%c两个顶点相邻\n",v1,v2);
			else
				printf("%c与%c两个顶点不相邻\n",v1,v2);			
			break;
		case 4:
			printf("计算1个顶点的度\n");
			printf("请输入1个顶点信息");
			getchar();	//吸收回车
			scanf("%c",&v1);
			degree=VexDegree(G,v1);
			printf("顶点%c的度为%d\n",v1,degree);
			break;
		case 5:
			printf("利用Prim算法构造最小生成树,其边集合依次为：\n");
			MiniSpanTree_P(G, G.vexs[0]);
			break;
		case 0:
			printf("程序结束，谢谢使用！\n"); 
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
	printf("1. 创建无向网\n");
	printf("2. 输出无向网的顶点数组与邻接矩阵  \n");
	printf("3. 判断2个顶点是不是相邻\n");
	printf("4. 计算1个顶点的度\n");	
	printf("5. 利用Prim算法构造最小生成树\n");
	printf("0.退出\n");
	printf("输入 0-5:");
	for(;;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>5)
			printf("\n输入错误，重选0－5：");
		else
			break;
	}
	return sn;
}

//采用邻接矩阵表示法，构造无向网
Status CreateUDN(MGraph &G)
{ 
	int i,j,k,IncInfo;
	VertexType v1,v2;
	VRType w;
	G.kind=UDN;
	printf("请输入无向网的顶点数，边数与是否含有边说明项：\n");
	scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);	
	getchar();   //吸收回车
	printf("请输入%d个顶点：\n",G.vexnum);
	for(i=0; i<G.vexnum; ++i)
		scanf("%c",&G.vexs[i]);
	for(i=0; i< G.vexnum; ++i)
	{
		for(j=0; j<G.vexnum; ++j)
		{
			G.arcs[i][j].adj=INFINITY;
			G.arcs[i][j].info=NULL;
		}
	}
	printf("请输入%d条边信息:v1 v2 w info：\n",G.arcnum);	
	for(k=0; k<G.arcnum;++k)
	{		
		getchar();	//吸收回车
		scanf("%c%c%d",&v1,&v2,&w);
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		if(i==-1||j==-1)
			return ERROR;
		G.arcs[i][j].adj=w;
		if(IncInfo)
			Input(G.arcs[i][j].info);
		G.arcs[j][i] = G.arcs[i][j];
	}	
	return OK;
}
//查找某一定点的下标
int LocateVex(MGraph G, VertexType v)
{
	int i;
	for(i=0; i<G.vexnum; ++i)
	{
		if(G.vexs[i]==v)
			return i;
	}
	return -1;
}
//输入关于边的相关信息
void Input(char * &pc)
{
	pc=(char*)malloc(10*sizeof(char));
	scanf("%s",pc);
}
//输出无向网的信息
void DisplayUDN(MGraph G)
{
	int i,j;
	printf("请输出图的顶点：");
	for(i=0; i<G.vexnum; ++i)
		printf("%c ",G.vexs[i]);
	printf("\n");
	printf("请输出图的邻接矩阵：\n");
	for(i=0; i< G.vexnum; ++i)
	{
		for(j=0; j<G.vexnum; ++j)
		{
			printf("%6d",G.arcs[i][j].adj);
			printf("%6s",G.arcs[i][j].info);
		}
		printf("\n");
	}
}
//closedge为MAX_VERTEX_NUM个元素的结构体数组，全局变量
struct {
	VertexType  adjvex;  // U集中的顶点序号
	VRType     lowcost;  // 边的权值
} closedge[MAX_VERTEX_NUM];	

//用普里姆算法从顶点u出发构造网G的最小生成树
void MiniSpanTree_P(MGraph G, VertexType u) 
{ 
	int k,j,i;
	k=LocateVex (G,u); //u为生成树根，k为生成树根下标
	for ( j=0; j<G.vexnum; ++j )  // 辅助数组初始化
	{
		if (j!=k) 
		{
			closedge[j].adjvex=u;
			closedge[j].lowcost=G.arcs[k][j].adj;
		}  
	}
	closedge[k].lowcost = 0;      // 初始，U＝{u}
	for (i=1; i<G.vexnum; ++i) 
	{
		k = minimum(G);     //选中的下一个顶点
		
		printf("%c-->%c%4d\n",closedge[k].adjvex, G.vexs[k],closedge[k].lowcost); //打印生成树中的一条边
		closedge[k].lowcost = 0; // G.vexs[k]进入U集合
		for (j=0; j<G.vexnum; ++j) 
		{			
			if (G.arcs[k][j].adj < closedge[j].lowcost)
			{
				closedge[j].adjvex=G.vexs[k];
				closedge[j].lowcost=G.arcs[k][j].adj;
			}
		}
	}	
}
//返回closedge数组中lowcost不为0且值最小的顶点的下标
int minimum(MGraph G)
{
	int i,min=INFINITY,mini=-1;
	for (i=0; i<G.vexnum; ++i)
	{
		if(closedge[i].lowcost!=0)
		{
			if(closedge[i].lowcost<min)
			{
				min=closedge[i].lowcost;
				mini=i;
			}
		}
	}
	return mini;	
}
//判断2个顶点是不是相邻
Status JudgeAdj(MGraph G,VertexType v1,VertexType v2)
{
	int i,j;
	i=LocateVex(G,v1);//找顶点v1所对应的下标号
	j=LocateVex(G,v2);
	if(i==-1||j==-1) //顶点v1或者顶点v2不存在		
		return ERROR;
	if(G.arcs[i][j].adj<INFINITY) //邻接矩阵中对应的边的权重值小于无穷大量
		return OK;
	else
		return ERROR;
}
//计算1个顶点的度
int VexDegree(MGraph G,VertexType v)
{
	int i,j,degree=0;
	i=LocateVex(G,v);//找顶点v1所对应的下标号
	if(i==-1) //顶点v1不存在		
		return ERROR;
	for(j=0;j<G.vexnum;j++)
	{
		if(G.arcs[i][j].adj<INFINITY) //邻接矩阵中对应的边的权重值小于无穷大量
			degree++;
	}
	return degree;	
}



