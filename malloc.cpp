#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 1000;
    int *p;
    p = (int *)malloc(n * sizeof(int));
    if (p == 0)
        exit(0);
    free(p);

    return 0;
}

