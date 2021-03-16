/********************************
//*输出10*10方阵
#include <stdio.h>

int main(void)
{
    int i, j;

    for (j = 0; j < 10; j++)
    {
        for (i = 0; i < 10; i++)
            printf("*");
        printf("\n");
    }
    return 0;
}
***********************************/

/****************************************
//todo 输出等腰三角形
#include <stdio.h>

int main(void)
{
    int i, j;

    for (j = 0; j < 10; j++)
    {
        for (i = 0; i < 9 - j; i++)
            printf(" ");
        for (i = 0; i < 2 * j + 1; i++)
            printf("*");
        printf("\n");
    }
    return 0;
}
*****************************************/

/*******************************************
#include <stdio.h>

int main(void)
{
    int i, j;

    for (j = 0; j < 10; j++)
    {
        for (i = 0; i < 9 - j; i++)
            printf(" ");
        for (i = 0; i < 2 * j + 1; i++)
            printf("*");
        printf("\n");
    }

    for (j = 0; j < 10; j++)
    {
        for (i = 0; i < j+1; i++)
            printf(" ");
        for (i = 0; i < 17-2*j; i++)
            printf("*");
        printf("\n");
    }
    return 0;
}
********************************************/

//? 输出平行四边形
#include <stdio.h>
int main(void)
{
    int i, j;

    for (j = 0; j < 10; j++)
    {
        for (i = 0; i < j; i++)
            printf(" ");
        for (i = 0; i < 10; i++)
            printf("*");
        printf("\n");
    }
    return 0;
}