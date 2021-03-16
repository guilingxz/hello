#include <stdio.h>
#define MAX 20
int main(void)
{
    int score[MAX];
    int n, i;
    int max, index;

    scanf("%d", &n);
    /****************************
    scanf("%d", &score[0]);
    max = score[0];
    index = 0;
    ****************************/
    for (i = 0; i < n; i++)
    {
        scanf("%d", &score[i]);
        if (score[i] > max || i==0)
        {
            max = score[i];
            index = i;
        }
    }
    printf("%d %d\n", max, index);

    return 0;
}