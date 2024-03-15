#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

struct stack
{
    int data[SIZE];
    int top;
};

void push(struct stack*,int);
int pop(struct stack*);
int isempty(struct stack*);
int isfull(struct stack*);
int stacktop(struct stack*);
void display(struct stack);

int main()
{
    struct stack s;
    int e,p,ch;
    s.top=-1;

    while(1)
    {
        printf("1.Push the element in stacks\n");
        printf("2.Pop the element in stacks\n");
        printf("3.Display stacks\n");
        printf("4.Stack top\n");

        printf("Enter choise:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:printf("Enter element to be pushed:");
                   scanf("%d",&e);
                   push(&s,e);
                   break;

            case 2:p=pop(&s);
                   printf("Poped element=%d",p);
                   break;

            case 3:display(s);
                   break;

            case 4:p=stacktop(&s);
                   printf("%d",p);
                   break;

            case 5:exit(0);
        }
    }
}

int pop(struct stack*s)
{
    int e;

    if(isempty(&s))
    {
        printf("Stack underflow\n");
        return -1;
    }

    e=s->data[s->top];
    s->top--;
    return e;
}

int isfull(struct stack*s)
{
    if(s->top==SIZE-1)
        return 1;
    else
        return 0;
}

int isempty(struct stack*s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}

int stacktop(struct stack*s)
{
    return(s->data[s->top]);
}

void display(struct stack s)
{
    int i;

    if(isempty)
        printf("Stack empty");

    for(i=s.top;i>=0;i--)
        printf("%d\n",s.data[i]);
    return;
}

void push(struct stack*s,int e)
{
    if(isfull(&s))
    {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->data[s->top]=e;
}
