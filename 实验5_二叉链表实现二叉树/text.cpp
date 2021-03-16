#include<stdio.h>
#include<stdlib.h>
#define ok 1
#define error 0
#define overflow -2
typedef struct treenode{
	int data;
	struct treenode *lchild,*rchild;
}treenode,*tree;

int menu();
int inittree(tree &t);
int createtree(tree &t);
void input(int a[],int n);
void output(int a[],int n);
void firsttree(tree t);
void middletree(tree t);
void lasttree(tree t);
int leaft(tree t);
int dfs(tree t);
int search(tree t,int e,int &s);
int destory(tree &t);
void display(tree t,int i);
int locate(int a[],int ch,int m,int n);
int create(tree &t,int pre[],int in[],int m,int n,int len);
int wpltree(tree t,int i);
int degreeone(tree t);
int degreetwo(tree t);

int main(){
	tree t;
	int pre[10],in[10];
	int len,wpl,n1,n2,s=0,count=0,e;
	int m,n,j=0;
	while(1){
		switch(menu()){
			case 1:s=inittree(t);
				   if(s){
				   	printf("初始化成功 \n");
				   }else{
				   	printf("初始化失败\n");
				   }
				   break;
				   
			case 2:printf("请输入先序遍历的数据\n");
				   s=createtree(t);
				   if(s){
				   	printf("创建成功\n");
				   }else{
				   	printf("创建失败\n");
				   }
				   break;
				   
			case 3:printf("该树的先序遍历结果如下 :\n");
				   firsttree(t);
				   printf("\n");
				   break;
				   
			case 4:printf("该树的中序遍历结果如下 :\n");
				   middletree(t);
				   printf("\n");
				   break;
				   
			case 5:printf("该树的后序遍历结果如下 :\n");
				   lasttree(t);
				   printf("\n");
				   break;
				   
			case 6:printf("树的中序凹入显示如下:\n");
				   j=0;
				   display(t,j);
				   break;
				   
			case 7:
				   s=leaft(t);
				   if(s){
				   
				   printf("该树有%d个叶子结点\n",s);}
				   else{
				   	printf("该树为空树\n");
				   }
				   break;
				   
			case 8:printf("该树的深度搜索如下\n");
				   dfs(t);
				   break;
				   
			case 9:printf("请输入需要查找的值\n");
				   scanf("%d",&e);
				   search(t,e,s);
				   if(s){
				   	printf("该二叉树里有此值\n");
				   }else{
				   	printf("未找到该值\n");
				   }
				   break;
				   
			case 10:s=destory(t);
				    if(s){
				    	printf("销毁成功\n");
				    }else{
				    	printf("销毁失败\n");
				    }
				    break;
				    
			case 11:printf("请输入二叉树的长度\n");
					scanf("%d",&len);
				    printf("请输入长度为%d的先序遍历的结果\n",len);
					for(j=0;j<len;j++){
						scanf("%d",&pre[j]);
					}
					printf("请输入长度为%d的中序遍历的结果\n",len);
					for(j=0;j<len;j++){
						scanf("%d",&in[j]);
					}
					m=n=0;
					s=create(t,pre,in,m,n,len);
					if(s){
						printf("创建成功\n");
					}else{
						printf("创建失败\n");
					}
					break; 
					
					
			case 12:j=0;
					s=wpltree(t,j);
					if(s){
						printf("该二叉树带权路径长度为%d\n",s);
					}else{
						printf("该树为空树\n");
					}
					break;
					
			case 13:s=degreeone(t);
					if(s){
						printf("度为1的结点有%d个\n",s);
					}else{
						printf("该树无度为1的结点\n");
					}
					break;
					
			case 14:s=degreetwo(t);
					if(s){
						printf("度为2的结点有%d个\n",s);
					}else{
						printf("该树无度为2的结点\n");
					}
					break;
			
			case 0:printf("感谢使用本软件\n");
					exit(0);
		}
	} 
	return 0;
}

int menu(){
	int sn;
	printf("\n显示菜单\n");
	printf("1.初始化空树\n");
	printf("2.先序创建二叉树\n");
	printf("3.输出先序遍历序列\n");
	printf("4.输出中序遍历序列\n");
	printf("5.输出后序遍历序列\n");
	printf("6.凹入显示二叉树\n");
	printf("7.求二叉树的叶节点个数\n");
	printf("8.求二叉树的深度查找\n");
	printf("9.查找二叉树的某个定值\n");
	printf("10.销毁二叉树\n");
	printf("11.已知先序，中序遍历，构造二叉树\n");
	printf("12.计算带权路径的长度\n");
	printf("13.求度为1的结点的个数\n");
	printf("14.求度为2的结点的个数\n");
	printf("0.退出\n");
	printf("请输入0~14\n");
	while(1){
		scanf("%d",&sn);
		if(sn>14||sn<0){
			printf("error : please input 0~14\n");
		}else{
			break;
		}
	}
	return sn;
}

int inittree(tree &t){
	t=NULL;
	return ok;
}

int createtree(tree &t){
	int i;
	scanf("%d",&i);
	if(i==0){
		t=NULL;
	}
	else{
		
		t=(tree)malloc(sizeof(treenode));
		if(!t){
			return overflow;
		}
		t->data=i;
		createtree(t->lchild);
		createtree(t->rchild);
		
	}
	return ok;
}

void firsttree(tree t){
	if(t){
		printf("%d\t",t->data);
		firsttree(t->lchild);
		firsttree(t->rchild);
	}
}

void middletree(tree t){
	if(t){
		middletree(t->lchild);
		printf("%d\t",t->data);
		middletree(t->rchild);
	}
}

void lasttree(tree t){
	if(t){
		lasttree(t->lchild);
		lasttree(t->rchild);
		printf("%d\t",t->data);
	}
}
int leaft(tree t){
	if(!t){
		return 0;
	}else if(t->lchild==NULL&&t->rchild==NULL){
		return 1;
	}else{
		return leaft(t->lchild)+leaft(t->rchild);
	}
}

void display(tree t,int i)
{
	int j;
	if(t->lchild!=NULL)
		display(t->lchild,i+1); 	
	for(j=1;j<=i;j++) 	
		printf("\t");
	printf("       %d",t->data);
	for(j=i+1;j<=8;j++)		
		printf("--------");
	printf("\n");
	if(t->rchild!=NULL)
		display(t->rchild,i+1);
}

int dfs(tree t){
	if(!t){
		return error;
	}
	else{
		printf("%d\t",t->data);
		dfs(t->lchild);
		dfs(t->rchild);
	}
}

int search(tree t,int e,int &s){
	int i=0;
	s=i;
	if(!t){
		return error;
	}else{
		search(t->lchild,e,s);
		search(t->rchild,e,s);
		i=(t->data==e?1:0);
	}
	if(i){
		s=i;
	}	
}

int destory(tree &t){
	if(!t){
		return error;
	}else{
		destory(t->lchild);
		destory(t->rchild);
		free(t);
		
	}
	return ok;
}


int locate(int a[],int ch,int m,int len)
{
	int i=m;
	while(i<m+len&&a[i]!= ch)
	{
		i++;
	}
	return i;
}

int create(tree &t,int pre[],int in[],int m,int n,int len)
{
	int ch;
	int i,j;
	if(!len)
	{
		t=NULL; 
		return error;			
	}
	else
	{
		ch=pre[m];	
		t=(tree)malloc(sizeof(int));
		t->data=ch;	
		i=locate(in,ch, n, len);
		j=i-n;  
		create(t->lchild,pre,in,m+1,n,j);
		create(t->rchild,pre,in,m+j+1,i+1,len-j-1);
		return ok;
	}
}

int wpltree(tree t,int i){
	if(t){
	
	if(t->lchild==NULL&&t->rchild==NULL){
		return i*t->data;
	}else{
		return wpltree(t->lchild,i+1)+(t->rchild,i+1);
	}
}
	else return 0;
}

int degreeone(tree t)   
{ 
	int n1,ln1,rn1;
	if(!t) n1=0;
	else
	{		
			ln1=degreeone(t->lchild);
			rn1=degreeone(t->rchild);
			if (t->lchild&&(!t->rchild)||(!t->lchild)&&(t->rchild))
				n1=ln1+rn1+1;
			else
				n1=ln1+rn1;		
	}
	return n1;
}


int degreetwo(tree t)   
{ 
	int n2,ln2,rn2;
	if(!t) n2=0;
	else
	{		
			ln2=degreetwo(t->lchild);
			rn2=degreetwo(t->rchild);
			if (t->lchild&&t->rchild)
				n2=ln2+rn2+1;
			else
				n2=ln2+rn2;		
	}
	return n2;
}
