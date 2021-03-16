//*水仙花数是指一个N位正整数（N≥3），它的每个位上的数字的N次幂之和等于它本身。

#include <stdio.h>
#include <math.h>

int main()
{
    int i,j,k,s,n,sum;    
    scanf("%d",&n);
    
    for (i=pow(10,n-1);i<=pow(10,n);i++)
    {
        sum=0;
        k=i;
        for(j=0;j<n;j++)
        {
            s=k%10;
            sum+=pow(s,n);
            k=k/10;
        }
        if(sum == i)
            printf("%d\n",i);
    }
    return 0;
}