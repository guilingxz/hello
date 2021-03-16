 //!该方法可以快速求2的n次方和除以2的n次方
#include<stdio.h>
int main(void)
{
    int a=1;
    printf("%d",a<<2);//todo 二进制数a向左移位2位(<<2，即0001->0100),同理>>n就是向右移n位
    return 0;
}