#include <stdio.h>
#include <stdlib.h>

struct student
{
    int ID;
    char name[10];
    char sex;
    int age;
    struct student*next;
};



 int main()
 {
     FILE *fp = fopen("stu.txt","r");
     struct student *newNode = (struct student *)malloc(sizeof(struct student));
     fscanf(fp,"%d %s %c %d %lf",&p->ID,p->name,&p->sex,&p->age);
     printf("%6d%12s%3c%4d%6.lf\n",p->ID,p->name,p->sex,p->age);

     fclose(fp);
    return 0;
 }