一、程序填空   共2题 （共计20分）
第1题 （10.0分）
/*-------------------------------------------------------
【程序填空】
---------------------------------------------------------

功能：以下程序的功能如(图1)。

-------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
main()
{ 
  int f;
  /***********SPACE***********/
 【?】;
  double t,pi;
  t=1;pi=t;f=1;n=1.0;
  /***********SPACE***********/
  while(【?】 )
  {
    n=n+2;
    /***********SPACE***********/
    【?】;
    t=f/n;
    pi=pi+t;
  }
  /***********SPACE***********/
  【?】;
   printf("pi=%10.6f\n",pi);
}

答案：

=======(答案1)=======
float n
=========或=========
double n

=======(答案2)=======
fabs(t)>=1e-6
=========或=========
fabs(t)>=0.000001
=========或=========
1e-6<=fabs(t)
=========或=========
0.000001<=fabs(t)

=======(答案3)=======
f=-f
=========或=========
f=-1*f
=========或=========
f=f*(-1)
=========或=========
f=f*-1
=========或=========
f=(-1)*f

=======(答案4)=======
pi= pi * 4
=========或=========
pi*=4


第2题 （10.0分）
/*-------------------------------------------------------
【程序填空】
---------------------------------------------------------

功能：输出由字符w构造成的形如W的图形。

w        ww        w
 w      w  w      w
  w    w    w    w
   w  w      w  w
    ww        ww

-------------------------------------------------------*/
#include <stdio.h>
void draw(int n)
{ 
  int i,j,k,r,m;
  /***********SPACE***********/
  for(i=1; 【?】;i++)
  {
    for(j=1;j<=2;j++)
    {
      for(r=1;r<i;r++)printf(" ");
        printf("w");
        /***********SPACE***********/
        for(k=1; 【?】 ;k++)printf(" ");
           printf("w");
           for(m=1;m<i;m++)printf(" ");
    }
    /***********SPACE***********/
    【?】;
  }
}
#include <conio.h>
main()
{
  int n;
  printf("input a number:");
  /***********SPACE***********/
  【?】;
  draw(n);
}

答案：

=======(答案1)=======
i<=n
=========或=========
n>=i

=======(答案2)=======
k<= 2 * n - 2 * i
=========或=========
 2 * n - 2 * i >=k

=======(答案3)=======
printf("\n")

=======(答案4)=======
scanf("%d",&n)


二、程序设计   共4题 （共计80分）
第1题 （20.0分）
/*-------------------------------------------------------
【程序设计】 
---------------------------------------------------------

题目：编写程序计算并输出：1 + 12 + 123 + 1234 + …… 的前n(设0<n<10)项的和sum，
      n从键盘输入。

      例如输入：3     则输出：136
      又如输入：6     则输出：137171

-------------------------------------------------------*/
#include <stdio.h>
void wwjt();

//计算1 + 12 + 123 + 1234 + …… 的前n(设0<n<10)项的和
long sum(int n)
{
/**********Program**********/




/**********  End  **********/
        return sum;
}

    
main()
{
        int n;
        printf("Input n: ");
        scanf("%d",  &n);        
        printf("sum=%ld\n",sum(n));
        wwjt();
}


void wwjt()
{

  FILE *IN,*OUT;
  int i,j;
  IN=fopen("in.dat","r");
  OUT=fopen("out.dat","w");
  for(i=0;i<3;i++)
  { 

    fscanf(IN,"%d",&j);
    fprintf(OUT,"%d\n",sum(j));
  }
  
  fclose(IN);
  fclose(OUT);
}

答案：    int i;
    long  k, sum;
    sum = 0;
    k = 0;
    for ( i=1; i<=n; i++ )
    {
        k = 10*k + i;
        sum += k;
    }

第2题 （20.0分）
/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：请编写fun函数程序，从键盘输入某一年，判断该年是否为
      闰年。

闰年的条件是：（1）能被4整除但不能被100整除。
              （2）能被400整除。符合任何一个条件就是闰年。
                   输入年份为整型

-------------------------------------------------------*/
#include <stdio.h>

void wwjt();

int fun(int year )
{

    /**********Program**********/

        
    /**********  End  **********/
}
    
void main( )
{  
    int year ;
        
    scanf("%d", &year); 
       
    if(fun(year) == 1)
        printf("yes");
    else
        printf("no");

    wwjt();
}

void wwjt()
{
        
    FILE *IN,*OUT;
    int j;
    int a;
    IN=fopen("in.dat","r");
    if(IN==NULL)
    {
        printf("Please Verify The Currernt Dir..It May Be Changed");
    }
    OUT=fopen("out.dat","w");
    if(OUT==NULL)
    {
        printf("Please Verify The Current Dir.. It May Be Changed");
    }
    for(j=0;j<3;j++)
    {
        fscanf(IN,"%d",&a);
        fprintf(OUT,"%d\n",fun(a));

    } 
        
    fclose(IN);
    fclose(OUT);
}




答案：    int leap;

    if((year % 4 == 0 && year % 100 != 0) || (year % 400 ==0))
        leap = 1;
    else
        leap = 0;

    return leap;


第3题 （20.0分）
/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：请编fun函数写程序，从键盘输入百分制成绩，要求输出
      等级制成绩A、B、C、D。90～100分为A，80～89分为B，
      60～79分为C，1～59分为D。不考虑小数，输入为整数，
      输出为字符。

-------------------------------------------------------*/
#include <stdio.h>

void wwjt();

char fun (int n)
{
  
    /**********Program**********/
  

    /**********  End  **********/
}

void main()
{
    int score,n;
    char p;
    scanf("%d",&score);
    n=score/10;
    p=fun(n);
    printf("%c" , p);
    wwjt();
}

void wwjt()
{
    FILE *IN,*OUT;
    int iIN,i;
    char cOUT;
    IN=fopen("in.dat","r");
    if(IN==NULL)
    {
        printf("Please Verify The Currernt Dir..it May Be Changed");
    }
    OUT=fopen("out.dat","w");
    if(OUT==NULL)
    {
        printf("Please Verify The Current Dir.. it May Be Changed");
    }
    for(i=0;i<5;i++)
    {  
        fscanf(IN,"%d",&iIN);
        cOUT=fun(iIN);
        fprintf(OUT,"%c\n",cOUT);
    }
    fclose(IN);
    fclose(OUT);
}

答案：    char s;
    switch(n)
    {
        case 10:
        case 9:s='A';break;
        case 8:s='B';break;
        case 7:
        case 6:s='C';break;
        default:s='D';
    }
    return s;


第4题 （20.0分）
/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

编写函数fun()，它的功能是求n以内(不包括n)同时能被5与11整
除的所有自然数之和的平方根s，并作为函数值返回。

例如：n为1000时，函数值应为s=96.979379。

注意：部分源程序给出如下。
请勿改动主函数main和其他函数中的任何内容，仅在函数
fun的花括号中填入所编写的若干语句。

试题程序：
-------------------------------------------------------*/
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double  fun(int n)
{
    double  s = 0.0;
    int  i;
 
    /**********Program**********/
    

    /**********  End  **********/
}

void main()
{
    FILE *wf;
    system("CLS");
    printf("s=%f\n", fun(1000));
    wf=fopen("out.txt", "w");
    fprintf(wf, "%f", fun(1000));
    fclose(wf);
}


答案：    for(i = 0; i < n; i++)     
    if(i % 5 == 0 && i % 11 == 0)     
        s = s + i;
    s = sqrt(s);           
    return  s;


