// Problem Statement:
// -> Write a C program to create a circular linked list and display its elements. The program should:

// 1. Allow the user to input data for each node in the linked list.
// 2. Dynamically allocate memory for each new node.
// 3. Display all the elements of the linked list once the input process is complete.

// Input:
// -> An integer value for each node.
// -> A choice to either continue adding nodes or stop
// Output:
// -> A display of all elements in the linked list.


#include <stdio.h>
#include <stdlib.h> 

struct node {
    int data;
    struct node* next;
};

int main() {
    struct node *head, *newnode, *temp;
    head = 0;
    int choice = 1;

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if (head == 0) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        
        printf("Do you want to continue (0 to stop, 1 to continue)? ");
        scanf("%d", &choice);
        
        temp->next = head;
    }

    printf("Linked List Elements: ");
    if(head == 0){
        printf("Empty Linked List \n");;
    }
    else{
        temp = head;
        while(temp->next != head){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
    return 0;
}
