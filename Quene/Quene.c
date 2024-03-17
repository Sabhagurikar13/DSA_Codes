#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct queue
{
    int items [MAX];
    int front;
    int rear;
};

void initilize(struct queue*);
void insert(struct queue*,int);
int dequeue(struct queue*);
int isfull(struct queue*);
int isempty(struct queue*);
int read(int);
void display(struct queue*);

int main()
{
    struct queue q;
    int e; int ch; int p; int d;

    initilize(&q);

    while(1)
    {
        printf("1.Add in queue.\n");
        printf("2.Remove the first added item.\n");
        printf("3.Display.\n");
        printf("4.Exit.\n");

        printf("Enter choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:printf("Enter item:");
                   scanf("%d",&e);
                   insert(&q,e);
                   break;

            case 2:p=dequeue(&q);
                   printf("%d",p);
                   break;

            case 3:display(&q);
                   break;

            case 4:exit(0);
                   break;

        }
    }
}

void initilize(struct queue*q)
{
    q->front=0;
    q->rear=-1;
}

void insert(struct queue*q,int e)
{
    if(isfull(&q))
        printf("Queue overflow.\n");

    else
    {
       q->rear++;
       q->items[q->rear]=e;
    }
}

int dequeue(struct queue*q)
{
    int e;

    if(isempty(&q))
    {
        printf("Queue underflow.\n");
        return;
    }

    else
    {
        e=q->items[q->front];
        q->front++;
        return e;
    }
}

int isfull(struct queue*q)
{
    if(q->rear==MAX-1)
        return 1;

    return 0;
}

int isempty(struct queue*q)
{
    if((q->rear)-(q->front)==-1)
        return -1;

    return 0;
}

int read(int e)
{
    printf("Enter item:");
    scanf("%d",&e);
    return e;
}

void display(struct queue*q)
{
        int i;

    for(i=q->front;i<=q->rear;i++)
    printf("%d\n",q->items[i]);
}
