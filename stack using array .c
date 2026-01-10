#include <stdio.h>

#define SIZE 5   // Maximum stack size

int top = -1;
int s[SIZE];

void push(int item)
{
    if (top == SIZE - 1)
    {
        printf("Stack is full (Overflow)\n");
    }
    else
    {
        top++;
        s[top] = item;
        printf("Inserted %d\n", item);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty (Underflow)\n");
    }
    else
    {
        int deleted = s[top];
        top--;
        printf("Popped element: %d\n", deleted);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack contents:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", s[i]);
        }
    }
}

int main()
{
    int choice, item;

    printf("Stack operations using Array\n");

    while (1)
    {
        printf("\n----------------\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
