#include <stdio.h>
#define MAX_SIZE 5

// Queue array and indices
int q[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue is full (Overflow). Cannot enqueue %d.\n", item);
    }
    else
    {
        if (front == -1)   // First insertion
        {
            front = 0;
        }
        rear++;
        q[rear] = item;
        printf("%d enqueued at index %d.\n", item, rear);
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty (Underflow). Cannot dequeue.\n");
    }
    else
    {
        int deleted_item = q[front];
        printf("Deleted item is %d\n", deleted_item);

        if (front == rear)   // Queue becomes empty
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, item;
    printf("Queue size is fixed to %d.\n", MAX_SIZE);

    do
    {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    }
    while (choice != 4);

    return 0;
}
