#include <stdio.h>
int main(void)
{
    int a = 1, b = 2;
    int z;

    z = (a < b) ? a : b;  //?条件表达式
    /********************
    z = (a < b) ? a : b;
    等同于
    if(a<b)
      z=a;
    else
      z=b;
    *********************/
    printf("%d", z);
    return 0;
}