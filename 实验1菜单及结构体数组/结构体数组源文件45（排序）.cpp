/*
ѧ���ɼ�����Ĺ���
1. ����5λͬѧ����Ϣ
2. ���5λͬѧ����Ϣ
3. ��ƽ����
4. ����ƽ�����ɸߵ�������
5. ���ǰ3��ͬѧ����Ϣ
0. ����
*/
//�洢�ṹ�����Ա��˳��洢�ṹ  ���뺯���ڵ�80�� 
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
void output(Student s[5],int n);
void average(Student s[5]);
void sort(Student s[5]);
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
			output(stu,5);
			break;
		case 3:average(stu);
			printf("ƽ�����Ѿ����\n");
			break;
		case 4:
			sort(stu);
			 printf("����ƽ�����ɸߵ��������Ѿ����\n");
			break;
		case 5:printf("���ǰ3��ͬѧ����Ϣ\n");
			sort(stu);	//���ǰ3��֮ǰ������
			output(stu,3);
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
void output(Student s[5],int n)		//����һ������n��Ϊ���Ԫ�صĸ���
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("%d\t",s[i].num);   //�ṹ�����s[i]. num
		printf("%s\t",s[i].name);
		for(j=0;j<3;j++)
		{
			printf("%d\t",s[i].score[j]);
		}
		printf("%d\t",s[i].ave);
		printf("\n");
	}
}
//��ƽ����
void average(Student s[5])
{
	int i,j,sum;
	for(i=0;i<5;i++)
	{
		sum=0;
		for(j=0;j<3;j++)
		{
			sum+=s[i].score[j];		
		}
		s[i].ave=sum/3;
	}
}
//ð������
void sort(Student s[5])
{
	average(s);  //����֮ǰӦ�������ƽ����
	int i,j;
	Student t;
	for(i=4;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(s[j].ave<s[j+1].ave)	
			{
				t=s[j];
				s[j]=s[j+1];
				s[j+1]=t;
			}
		}		
	}
}
