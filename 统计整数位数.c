#include <stdio.h>
int main(void)
{
    int count, number,i;
    printf("Enter a number:\n");
    scanf("%d", &number);
i=number;
    /* ////这一步负数变正没有意义！
    if (i < 0)
    {
        i = -i;
    }
    */
    count = 0;
    do
    {
        i = i / 10;
        printf("%d\n", i), //todo 将循环中number值的每次变换表示出来
            count++;
    } while (i != 0);
    printf("%d countains %d digits.\n",number,count);
    
    return 0;
}