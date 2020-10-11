//Ԥ��������
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 10  //��洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 2    // ���Ա�洢�ռ�ķ�������
//���ݽṹ
typedef int Status;
typedef int ElemType;
typedef struct 
{
	ElemType *elem;  // �洢�ռ��ַ
	int length;      // ��ǰ����
	int listsize;    // ��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
} SqList;
//��������
int menu_select(); 
Status InitList_Sq(SqList &L);
Status CreatList_Sq(SqList &L,int n);
void PrintList_Sq(SqList L);
Status  ListInsert_Sq(SqList &L,int i,ElemType e);
Status ListDelete_Sq(SqList &L,int i,ElemType &e);
int LocateElem_Sq(SqList L,ElemType e, Status(*compare)(ElemType,ElemType));
Status equal(ElemType x,ElemType y);
//������
int main()
{
	SqList L;	
	Status s;
	int n,i,e;
	for(;;)
	{
		switch(menu_select())
		{
		case 1:
			s=InitList_Sq(L);
			if(s)
				printf("��ʼ���ɹ�\n");
			else
				printf("��ʼ��ʧ��\n");
			break;
		case 2:
			printf("�������Ա�ĳ���:");
			scanf("%d",&n);
			s=CreatList_Sq(L,n);
			if(s)
				printf("�����ɹ�\n");
			else
				printf("����ʧ��\n");
			break;
		case 3:
			PrintList_Sq(L);
			break;
		case 4:
            printf("����������λ��:");
            scanf("%d",&i);
			printf("������������Ԫ�ص�ֵ:");
			scanf("%d",&e);
			s= ListInsert_Sq(L,i,e);
			if(s)
				printf("����ɹ�!\n");
			else
				printf("����ʧ��!\n");
			break;
		case 5:
			printf("����ɾ����λ��");
			scanf("%d",&i);
			s=ListDelete_Sq(L,  i,  e);
			if(s)
				printf("ɾ����Ԫ��%d�ɹ�\n",e);
			else
				printf("ɾ��ʧ��\n");
			break;
			break;
		case 6:printf("��������ҵ�Ԫ�ص�ֵ:");
            scanf("%d",&e);
			i= LocateElem_Sq(L,e, equal);//ָ�������͵�ָ�����βΣ�ʵ����ͬ���͵ĺ�����equal
			if(i)
				printf("%d���߼�λ����%d\n",e,i);
			else
				printf("����ʧ��!\n");
			break;			
		case 0:
			printf("���������ллʹ�ã�\n\n"); 
			exit(0);
		}
	}
	return 0;
}
//�˵�����
int menu_select()
{
	int sn;
	printf("\n��ʾ�˵�\n");
	printf("1.��ʼ��\n");
	printf("2.����\n");
	printf("3.��ʾ\n");
	printf("4.����\n");
	printf("5.ɾ��\n");
	printf("6.����\n");
	printf("0.�˳�\n");
	printf("���� 0-6:");
	for(;;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>6)
			printf("\n���������ѡ0��6��");
		else
			break;
	}
	return sn;
}
//��ʼ���յĶ�̬˳�����
Status InitList_Sq(SqList &L)
{
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)  return(OVERFLOW);
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
}
//������̬˳�������n��Ԫ�أ�
Status CreatList_Sq(SqList &L,int n)
{
	int i;
	if(n>L.listsize)
		return(ERROR);
	printf("����%d��������:",n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&L.elem[i-1]);//��C�������޸�ʽ�����ַ�������Ҫ����
	}
	L.length=n;
	return OK;
}
//���˳���Ԫ��
void PrintList_Sq(SqList L)
{
	int i;
	for(i=1;i<=L.length;i++)
	{
		printf("%d\t",L.elem[i-1]);
	}
	printf("\n");
}
//������Ԫ��e����i��λ��
Status  ListInsert_Sq(SqList &L,int i,ElemType e)
{
	ElemType *newbase,*q,*p;  //��C�����в����������壬��Ҫ����
	if(i<1 ||i>L.length+1)//����λ�ò��Ϸ�
		return ERROR;
	if(L.length>=L.listsize)//��ǰ����ռ䲻��
	{
		newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)exit(OVERFLOW);//�洢λ��ʧ��
		L.elem=newbase;	//�»�ַ
		L.listsize+=LISTINCREMENT;//���Ӵ洢λ��
	}
	q=&(L.elem[i-1]);//Ҫ�����λ��
	for(p=&(L.elem[L.length-1]);p>=q;--p)
		*(p+1)=*p; 	//����λ��֮���Ԫ������
	*q=e;			//����e
	++L.length;
	return OK;//������1
}//ListInsert_Sq
//ɾ����i��Ԫ��
Status ListDelete_Sq(SqList &L,int i,ElemType &e)
{
	ElemType *p,*q;	//������������
	if((i<1)||(i>L.length))
		return ERROR;
	p=&(L.elem[i-1]);
	e=*p;
	q=L.elem+L.length-1;
	e=*p;
	q=L.elem+L.length-1;
	for(++p;p<=q;++p)*(p-1)=*p;
	--L.length;
	return OK;
}
//���Ҹ���ֵ��λ��
int LocateElem_Sq(SqList L,ElemType e, Status(*compare)(ElemType,ElemType))
			//ָ�������͵�ָ�����β�
{
	ElemType *p;/	/������������
	int i;		//������������
	i=1;		//��ǰԪ�ص��߼�λ��	
	p=L.elem;		//��ǰԪ�ص������ַ	
	while(i<=L.length&&!(*compare)(*(p++),e))
		++i;
	if(i<=L.length)
		return i;
	else
		return 0;
}//LocateElem_Sq
//�ж���������Ԫ���Ƿ���ȵĺ���
Status equal(ElemType x,ElemType y)//ΪLocateElem_Sq����׼��������ʵ��
{
	if(x==y)
		return OK;
	else
		return ERROR;
}
