#include<stdio.h>

int fib(int);

int main()
{
    int n,p;

    printf("Enter n:");
    scanf("%d",&n);

    p=fib(n);

    printf("%d",p);
}

int fib(int n)
{
    int a=-1;
    int b=1;
    int c,i;

    for(i=1;i<=n;i++)
    {
        c=a+b;

        printf("%d\n",c);
        a=b;
        b=c;
    }
}
