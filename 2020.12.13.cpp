#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	int ID;
	char name[10];
	char sex;
	int age;
	double score;
	struct student *next;
};

void insert(struct student * np);
void showAll();
void createList();
void deleteFromList(int ID);
void searchByName(char name[]);
void search();
void showMenu();
int userSelect();
void LoadFromFile();
void insertIntoLink();
void quitLink();

struct student *head = NULL;	//	Head Node pointer
struct student *tail = NULL;	//	Head Node pointer

int main()
{
	int choice = 0;
	while(choice != -1)
	{
		showMenu();
		choice = userSelect();
	}	
	return 0;
}

int userSelect()
{
	int choice;
	printf("input your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		createList();
		break;
	case 2:
		LoadFromFile();
		break;
	case 3:
		insertIntoLink();
		break;
	case 4:
		int ID;
		printf("input a ID to be deleted:");
		scanf("%d",&ID);
		deleteFromList(ID);
		break;
	case 5:
		search();
		break;
	case 6:

		break;
	case 7:
		showAll();
		break;
	case 8:
		quitLink();
		break;
	default:
		printf("select error\n");
	}
	return choice;
}

void quitLink()
{
	struct student *s,*q;

	if(head == NULL)
	{
		printf("Link is empty\n");
		return;
	}
	for( q = head->next  ;  q != NULL  ; s =q , q = q->next  )
		free(s);
	free(s);
}

void showMenu()
{
	printf("==================================================================\n");
	printf("=\t1.create Link\n");
	printf("=\t2.Load From file\n");
	printf("=\t3.insert\n");
	printf("=\t4.delete\n");
	printf("=\t5.search\n");
	printf("=\t6.modify\n");
	printf("=\t7.show\n");
	printf("=\t8.exit\n");
	printf("==================================================================\n");
}

void insertIntoLink()
{
	//	new a node
	struct student * p = (struct student *) malloc(sizeof(struct student));
	//	scanf data
	printf("input ID,NAME,SEX,AGE,SCORE\n");
	scanf("%d %s %c %d %lf",&p->ID,p->name,&p->sex,&p->age,&p->score);
	
	//	insert()
	insert(p);
}

void LoadFromFile()
{
	int ID;
	FILE *fp = fopen("stu.txt","r");
	if(fp == NULL)
	{
		printf("file read ERROR\n");
		return;
	}

	createList();
	while(feof(fp) == NULL)
	{		
		//struct student * p = (struct student *) malloc(sizeof(struct student));
		struct student * p;
		int size = sizeof(struct student);
		p = (struct student *) malloc(size);

		fscanf(fp,"%d %s %c %d %lf\n",&p->ID,p->name,&p->sex,&p->age,&p->score);
		//printf("%6d%12s%3c%4d%6.1f\n",p->ID,p->name,p->sex,p->age,p->score);
				
		insert(p);
	}

	fclose(fp);
	showAll();
}

void Save2File()
{	
	struct student *p,*q;
	FILE *fp = fopen("stu.txt","w");
	if(fp == NULL)
	{
		printf("file read ERROR\n");
		return;
	}
	
	if(head == NULL)
	{
		printf("Link is empty\n");
		return;
	}
	for( q = head->next  ;  q != NULL  ; q = q->next  )
	{
		fprintf(fp,"%d %s %c %d %lf\n",p->ID,p->name,p->sex,p->age,p->score);
		//printf("%6d%12s%3c%4d%6.1f\n",p->ID,p->name,p->sex,p->age,p->score);		
	}
	fclose(fp);	
}


//	initiate
void createList()
{
	if(head == NULL)
	{
		struct student * p = (struct student *) malloc(sizeof(struct student));
		head = p;
		p->next = NULL;
		tail = p;
	}
}

// p insert to head
void insert(struct student * p)
{
	struct student * q;	//	serch

	if(head == NULL)
	{
		printf("Link is empty\n");
		return;
	}
	
	if(head->next == NULL)
	{
		head->next = p;
		p->next = NULL;
		tail = p;
		return;			//	
	}
	

	for( q = head->next  ;  q != NULL  ; q = q->next  )
	{
			if(p->ID < head->next->ID)	//	left of first node
			{
				p->next = head->next;
				head->next = p;
			}else if( q->next == NULL && q->ID < p->ID )	//	right of tail node
			{
				q->next = p;
				p->next = NULL;
				tail = p;
			}else if( q->ID < p->ID && q->next != NULL && q->next->ID > p->ID)
			{
				p->next = q->next;
				q->next = p;
			}
		}
}

void showAll()
{
	struct student * q;
	if(head == NULL)
	{
		printf("Link is empty\n");
		return;
	}
	for( q = head->next  ;  q != NULL  ; q = q->next  )
	{
		printf("%6d%12s%3c%4d%6.1f\n",q->ID,q->name,q->sex,q->age,q->score);		
	}
}

void deleteFromList(int ID)
{
	struct student * q,*p,*r;
	if(head == NULL)
	{
		printf("Link is empty\n");
		return;
	}
	for( q = head->next  ;  q != NULL  ; p = q , q = r )
	{
		r=q->next;
		if(q->ID == ID)
		{
			p->next = q->next;			
			free(q);
			//break;
		}			
	}
	showAll();
}

void search()
{
	char name[10];
	printf("input a ID to be search:");
	scanf(" %s",name);
	searchByName(name);

}

void searchByName(char name[])
{
	struct student * q;	
	int isFound = 0;
	if(head == NULL)
	{
		printf("Link is empty\n");
		return;
	}
	for( q = head->next  ;  q != NULL  ; q = q->next  )
	{
		if( strcmp(q->name ,  name) == 0 )
		{
			printf("%6d%12s%3c%4d%6.1f\n",q->ID,q->name,q->sex,q->age,q->score);
			isFound = 1;
		}
	}
	if(isFound == 0)
		printf("not found\n");
}