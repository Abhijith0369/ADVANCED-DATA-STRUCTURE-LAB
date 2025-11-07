#include<stdio.h>
int q[5],i,item,size,front=-1,rear=-1;
void enqueue(int item)
{
    if(rear==size)
    {
        printf("Queue is full\n");
    }
    else
    {
        if(rear ==-1)
        {
            front=0;
            rear=0;
            q[rear]=item;
        }
        else
        {
            rear=rear+1;
            q[rear]=item;
        }
    }
}
void dequeue()
{
    if((front==-1)&&(rear==-1))
    {
        printf("Queue is empty\n");
    }
    else
    {
        if(front==rear)
        {
            printf("Deleted item is %d",q[front]);
            front=-1;
            rear=-1;
        }
        else
        {
            item=q[front];
            printf("Deleted item is %d",q[front]);
            front=front+1;
        }
    }
}
void display()
{
    for(i=front;i<=rear;i++)
    {
        printf("%d",q[i]);
    }
}
void main()
{
    int choice;
    printf("Enter thr size:");
    scanf("%d",&size);
    do
    {
        printf("Enter the choice");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the item to be inserted");
                scanf("%d",&item);
                enqueue(item);
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("Exit\n");
                break;
            }
            default : printf("Invalid choice");
        }
    }
    while(choice!=4);
}