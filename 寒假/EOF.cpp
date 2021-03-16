#include <stdio.h>

int main()
{
    int ch = 0;
    while((ch = getchar()) != EOF)   //*EOF 为 end of file 文件结束标志
    {
        putchar(ch);
    }
    return 0;
}