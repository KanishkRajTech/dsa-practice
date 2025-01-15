// Implement a Circular Deque Using an Array

// Write a program to implement a circular deque (double-ended queue) using an array in C. Your program should support the following operations:

// 1).Enqueue Front: Insert an element at the front of the deque.
// 2).Enqueue Rear: Insert an element at the rear of the deque.
// 3).Dequeue Front: Remove an element from the front of the deque.
// 4).Dequeue Rear: Remove an element from the rear of the deque.
// 5).Display: Display all elements in the deque in the correct order.

#include <stdio.h>
#define N 5

int deque[N];
int front = -1;
int rear = -1;

void enqueueFront(int data);
void enqueueRear(int data);
void dequeueFront();
void dequeueRear();
void display();

int main() {
    int ch, data;
    do {
        printf("\nMenu:\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data to enqueue at front: ");
                scanf("%d", &data);
                enqueueFront(data);
                break;
            case 2:
                printf("Enter data to enqueue at rear: ");
                scanf("%d", &data);
                enqueueRear(data);
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                display();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (ch != 0);

    return 0;
}

void enqueueFront(int data) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        deque[front] = data;
    } else if (front == 0) {
        front = N - 1;
        deque[front] = data;
    } else {
        front--;
        deque[front] = data;
    }
}

void enqueueRear(int data) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        deque[rear] = data;
    } else if (rear == N - 1) {
        rear = 0;
        deque[rear] = data;
    } else {
        rear++;
        deque[rear] = data;
    }
}

void dequeueFront() {
    if (front == -1 && rear == -1) {
        printf("Deque is empty\n");
    } else if (front == rear) {
        printf("Dequeued element: %d\n", deque[front]);
        front = rear = -1;
    } else if (front == N - 1) {
        printf("Dequeued element: %d\n", deque[front]);
        front = 0;
    } else {
        printf("Dequeued element: %d\n", deque[front]);
        front++;
    }
}

void dequeueRear() {
    if (front == -1 && rear == -1) {
        printf("Deque is empty\n");
    } else if (front == rear) {
        printf("Dequeued element: %d\n", deque[rear]);
        front = rear = -1;
    } else if (rear == 0) {
        printf("Dequeued element: %d\n", deque[rear]);
        rear = N - 1;
    } else {
        printf("Dequeued element: %d\n", deque[rear]);
        rear--;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;
    while (i != rear) {
        printf("%d -> ", deque[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", deque[rear]);
}
