#include<stdio.h>
#include<string.h>

int countVowels(char[]);

int main()
{
    int c;
    char str[100];

    printf("Enter string:");
    scanf("%s",str);

    c=countVowels(str);

    printf("%d\n",c);
}
int countVowels(char str[])
{
    int i;
    int c=0;

    for(i=0 ; str[i] ; i++)
    {
        switch(str[i])
        {
            case 'A': ;
            case 'a': ;
            case 'E': ;
            case 'e': ;
            case 'I': ;
            case 'i': ;
            case 'O': ;
            case 'o': ;
            case 'U': ;
            case 'u': ;
            c++;
        }
    }
    return c;
}
