#include <stdio.h>
#include <stdlib.h>

struct student
{
	int ID;
	char name[10];
	char sex;
	int age;
	struct student *next;
};

struct student *creatLinkNode();
void insert(struct student *newNode, struct student *current);

struct student *head = NULL;
int main()
{
	//struct student stu[40];
	FILE *fp01, *fp02;
	int i = 0;
	fp01 = fopen("in.txt", "r+");
	while (feof(fp01) == 0)
	{
		struct student *newNode = creatLinkNode();
		fscanf(fp01, "%d %s %c %d\n", &newNode->ID, newNode->name, &newNode->sex, &newNode->age);
		printf("%12d %15s %3c %4d\n", newNode->ID, newNode->name, newNode->sex, newNode->age);

		if (head == NULL)
		{
			head = newNode;
			head->next = NULL;
		}
		else
		{
			struct student *p;
			for (p = head; p != NULL; p = p->next)
			{
				if (p->ID < newNode->ID && p->next != NULL && p->next->ID > newNode->ID)
				{
					insert(newNode, p);
				}

				if (p->ID < newNode->ID && p->next == NULL)
				{
					insert(newNode, p);
				}

				if (newNode->ID < head->ID)
				{
					newNode->next = head;
					head = newNode;
				}
			}
		}
	}
	fclose(fp01);
	return 0;
}

struct student *creatLinkNode()
{
	struct student *newNode = (struct student *)malloc(sizeof(struct student));
	if (newNode == NULL)
	{
		printf("creat node fail\n");
		exit(1);
	}
	return newNode;
}
//	插入在current节点之后
void insert(struct student *newNode, struct student *current)
{
	if (current->next == NULL)
	{
		current->next = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = current->next;
		current->next = newNode;
	}
}