// Problem Statement:
// Implement a Circular Queue using an Array in C with the following functionalities:

// 1). Enqueue: Add an element to the rear of the queue.
// 2). Dequeue: Remove an element from the front of the queue.
// 3). Peek: Display the front element without removing it.
// 4). Display: Print all elements currently present in the queue.

#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int data);
void dequeue();
void display();
void peek();

int main() {
    int ch, data;
    do {
        printf("\nMenu\n");
        printf("1). Enqueue\n");
        printf("2). Dequeue\n");
        printf("3). Peek\n");
        printf("4). Display\n");
        printf("0). Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        } 
    } while (ch != 0);

    return 0;
}

void enqueue(int data) {
    if ((rear + 1) % N == front) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = data;
    } else {
        rear = (rear + 1) % N;
        queue[rear] = data;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("Dequeued element: %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        printf("Queue elements: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[rear]);
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}
