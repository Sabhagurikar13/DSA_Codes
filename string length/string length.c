#include<stdio.h>
#include<string.h>

int stringLength(char []);

int main()
{
    char str[100];
    int c;

    printf("Enter string:");
    scanf("%s",str);

    c=stringLength(str);

    printf("%d\n",c);
}
int stringLength(char str[])
{
    int c=0;
    int i;

    for(i=0 ; str[i] ; i++)
    {
       c++;
    }

    return c;
}
