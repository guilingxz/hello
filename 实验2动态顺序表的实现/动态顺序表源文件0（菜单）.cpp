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



//������
int main()
{
	
	for(;;)
	{
		switch(menu_select())
		{
		case 1:
			printf("��ʼ��\n");
			
			break;
		case 2:
			printf("����˳���\n");
			break;
		case 3:
			printf("���˳���\n");
			break;
		case 4:
			printf("���ò��뺯��\n");
			break;
		case 5:
			printf("����ɾ������\n");
			break;
		case 6:
			printf("���ò��Һ���\n");
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




