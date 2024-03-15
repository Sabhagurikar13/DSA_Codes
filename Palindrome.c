#include<stdio.h>

int ispalindrome(int);

int main()
{
    int n;
    int p;

    printf("Enter n:");
    scanf("%d",&n);

    p=ispalindrome(n);

    if(p==1)
        printf("Palindrome");
    else
        printf("not Palindrome");
}

int ispalindrome(int n)
{
    int temp=n;
    int rev=0;
    int rem;

    while(n)
    {
        rem=n%10;
        rev=rev*10+rem;
        n=n/10;
    }
    if(temp==rev)
        return 1;
    else
        return 0;
}
