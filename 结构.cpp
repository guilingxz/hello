#include <stdio.h>
int main(void)
{
    struct student
    {
        int num;
        char name[10];
        int computer, english, math;
        double average;
    };
    struct student s1, s2;
    struct student *p = &s2;
    s1.num = 123;
    p->num = 123;
    printf("%d\n", sizeof(s1));
    return 0;
}
