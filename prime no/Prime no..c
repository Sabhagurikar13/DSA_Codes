#include<stdio.h>
#include<math.h>

int isprime(int);

int main()
{
    int n;
    int p;

    printf("Enter n:");
    scanf("%d",&n);

    p=isprime(n);

    if(p==1)
        printf("Prime");

    else
        printf("Not prime");
}

int isprime(int n)
{
  int i;

  for(i=2 ; i<=sqrt(n) ; i++)
  {
      if(n%i==0)
          return 0;
  }

  return 1;

}
