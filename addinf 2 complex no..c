#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct complex
{
    double real;
    double img;
};

void readcomplex(struct complex*);
void displaycomplex(struct complex*);
struct complex addComplex(struct complex*,struct complex*);

int main()
{
    struct complex c1,c2,c3;

    readcomplex(&c1);
    readcomplex(&c2);

    c3=addComplex(&c1,&c2);

    displaycomplex(&c3);
}

void readcomplex(struct complex*p)
{
    printf("Enter complex no.");
    scanf("%lf%lf",p->real,p->img);
}

void displaycomplex(struct complex* q)
{
    printf("real=%lf",q->real);
    printf("imaginary=%lf",q->img);
}

struct complex addComplex(struct complex*c1,struct complex*c2)
{
    struct complex *c3;

    c3->real=c1->real+c2->real;
    c3->img=c1->img+c2->img;

}

