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
int  main()
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
		case 3:	printf("��ƽ����\n");
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
	printf("5.���ǰ3��\n");
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
	
}
//�������
void output(Student s[5])
{
	
}
