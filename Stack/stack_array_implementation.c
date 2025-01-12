#include <stdio.h>
#define N 5

int stack[N];
int top = -1;

void push();
void peek();
void pop();
void display();

int main() {
    int ch;
    do {
        printf("\nMenu\n");
        printf("1). Push\n");
        printf("2). Pop\n");
        printf("3). Peek\n");
        printf("4). Display\n");
        printf("0). Exit\n");
        printf("Select your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1: 
                push();
                break;
            case 2:
                pop();
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
                printf("Invalid choice!!\n");
        }
    } while (ch != 0);
    return 0;
}

void push() {
    int x;
    if (top == N - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter data: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("%d pushed onto the stack\n", x);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        int item = stack[top];
        top--;
        printf("%d popped from the stack\n", item);
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
