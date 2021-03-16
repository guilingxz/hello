#include <stdio.h>
int main(void)
{
    char ch,before;
    int count = 0;

    scanf("%c", &ch);
    before = ' ';
    while (ch !='\n')
    {
        if (ch == ' ' && before != ' ')
            count++;
        before = ch;
        scanf("%c", &ch);
    }
    if (before != ' ')
        count++;
    printf("%d", count);
    return 0;
}