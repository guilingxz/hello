//Ԥ��������
#include<stdio.h>
#include<stdlib.h>
//���ݽṹ����
typedef struct
{
	int num;
	char name[20];
	int score[3];
	int ave;
}Student;   //�ṹ�����Ͷ���
//��������
int menu_select(); 
void input(Student s[5]);
void output(Student s[5]);

//������
int main()
{
	Student stu[5];   //׼��ʵ��
	for(;;)
	{
		switch(menu_select())
		{
		case 1:printf("������5λͬѧ����Ϣ\n"); 
			input(stu);//��������
			break;
		case 2:	printf("���5λͬѧ����Ϣ\n");
			output(stu);
			break;
		case 3:	printf("ƽ�����Ѿ����\n");
			break;
		case 4:printf("����ƽ�����ɸߵ�������\n");
			break;
		case 5:printf("���ǰ3��ͬѧ����Ϣ\n");
			break;
		case 0:printf("ллʹ�ñ����\n"); 
			exit(0);
		}
	}
	return 0;
}
//�˵�����
int menu_select()
{
	int sn;
	printf("\n1.����5λͬѧ����Ϣ\n");
	printf("2.���5λͬѧ����Ϣ\n");
	printf("3.��ƽ����\n");
	printf("4.����\n");
	printf("5.���ǰ����\n");
	printf("0.����\n");
	printf("Input 0��5:");
	for(; ;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>5)
			printf("\n���������ѡ0��5��");
		else
			break;
	}
	return sn;
}
//���뺯��
void input(Student s[5])
{
	int i,j;
	for(i=0;i<5;i++)
	{
		scanf("%d",&s[i].num);
		scanf("%s",s[i].name);
		for(j=0;j<3;j++)
		{
			scanf("%d",&s[i].score[j]);
		}		
	}
}
//�������
void output(Student s[5])
{
	int i,j;
	for(i=0;i<5;i++)
	{
		printf("%d\t",s[i].num);
		printf("%s\t",s[i].name);
		for(j=0;j<3;j++)
		{
			printf("%d\t",s[i].score[j]);
		}
		printf("%d\t",s[i].ave);
		printf("\n");
	}
}
