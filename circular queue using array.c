#include <stdio.h>

#define SIZE 5

int q[SIZE];
int front = -1, rear = -1;

void enqueue(int item) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full (Overflow)\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        q[rear] = item;
        printf("Inserted %d at index %d\n", item, rear);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty (Underflow)\n");
    } else {
        printf("Deleted item: %d from index %d\n", q[front], front);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", q[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, item;

    printf("--- Circular Queue Implementation (Size: %d) ---\n", SIZE);

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter item to insert: ");
                if (scanf("%d", &item) != 1) {
                    printf("Invalid input! Try again.\n");
                    while (getchar() != '\n');
                    break;
                }
                enqueue(item);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
