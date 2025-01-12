// Problem Statement:
// Implement a Stack using a Linked List in C. The program should support the following operations:

// Push: Add an element to the top of the stack.
// Pop: Remove and display the top element from the stack.
// Peek: Display the top element without removing it.
// Display: Print all elements of the stack from top to bottom.

#include <stdio.h>
#include <stdlib.h> 

struct node {
    int data;
    struct node *link;
};

struct node *top = NULL; 

void push(int data);
void pop();
void peek();
void display();

int main() {
    int data, ch;
    do {
        printf("\nMenu\n");
        printf("1) Push\n");
        printf("2) Pop\n");
        printf("3) Peek\n");
        printf("4) Display\n");
        printf("0) Exit\n");
        printf("Select your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1: 
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
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
                printf("Invalid choice!\n");
        }
    } while (ch != 0);
    return 0;
}

// Function to push an element onto the stack
void push(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = data;
    newnode->link = top;
    top = newnode;
    printf("Pushed %d onto the stack\n", data);
}

// Function to pop an element 
void pop() {
    if (top == NULL) {
        printf("Stack underflow! No elements to pop.\n");
    } else {
        struct node *temp = top;
        printf("Popped %d from the stack\n", top->data);
        top = top->link;
        free(temp);
    }
}

// Function to display the top element 
void peek() {
    if (top == NULL) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

// Function to display all elements 
void display() {
    if (top == NULL) {
        printf("Stack is empty!\n");
    } else {
        struct node *temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}
