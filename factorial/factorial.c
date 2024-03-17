#include<stdio.h>

int fact(int);

int main()
{
    int n,f;

    printf("Enter n:");
    scanf("%d",&n);

    f=fact(n);

    printf("Fact=%d\n",f);
}

int fact(int n)
{
    int f=1;
    int i;

    for(i=1;i<=n;i++)
        f=f*i;

    return f;
}

