// Problem Statement:
// Implement a Queue using Two Stacks in C. The program should simulate a queue using two stacks (s1 and s2). Implement the following operations:

// 1).Enqueue: Insert an element into the queue by pushing it onto stack s1.
// 2).Dequeue: Remove the front element of the queue by transferring elements from s1 to s2, popping from s2, and then restoring elements to s1.
// 3).Display: Show all elements in the queue in order.

#include <stdio.h>
#define N 5

int s1[N], s2[N];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int data);
void push2(int data);
int pop1();
int pop2();
void enqueue(int data);
void dequeue();
void display();

int main() {
    int ch, data;
    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
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

void push1(int data) {
    if (top1 == N - 1) {
        printf("Stack Overflow on S1\n");
    } else {
        s1[++top1] = data;
    }
}

void push2(int data) {
    if (top2 == N - 1) {
        printf("Stack Overflow on S2\n");
    } else {
        s2[++top2] = data;
    }
}

int pop1() {
    if (top1 == -1) {
        printf("Stack Underflow on S1\n");
        return -1;
    } else {
        return s1[top1--];
    }
}

int pop2() {
    if (top2 == -1) {
        printf("Stack Underflow on S2\n");
        return -1;
    } else {
        return s2[top2--];
    }
}

void enqueue(int data) {
    push1(data);
    count++;
}

void dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is Empty\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        push2(pop1());
    }

    int b = pop2();
    printf("%d is dequeued\n", b);
    count--;

    for (int i = 0; i < count; i++) {
        push1(pop2());
    }
}

void display() {
    if (top1 == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i <= top1; i++) {
        printf("%d ", s1[i]);
    }
    printf("\n");
}
