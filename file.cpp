#include <stdio.h>
struct student
{
    char name[10];
    char sex;
    int age;
};
void loadfile();

int main()
{
    void loadfile();
    return 0;
}

void loadfile(int i=0)
{
    struct student stu[40];
    FILE *fp01, *fp02;
    fp01 = fopen("in.text", "r+");
    while (feof(fp01))
    {
        fscanf(fp01, "%s %c %d\n", stu[i].name, &stu[i].sex, &stu[i].age);
        printf("%s %c %d\n", stu[i].name, stu[i].sex, stu[i].age);
    }

    fclose(fp01);
}