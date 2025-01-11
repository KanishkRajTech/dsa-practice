// Problem Statement:
// -> Write a C program to implement a doubly linked list with the following functionalities:

// 1. Insert at the Beginning
// 2. Insert at the End
// 3. Insert at a Given Location
// 4. Delete from the Beginning
// 5. Delete from the End
// 6. Delete from a Specified Position
// 7. Reverse the Linked List
// 8. Display the Linked List

// Input/Output Requirements:
// -> The program should display a menu for the user to choose the desired operation.
// -> For insertion and deletion at a specific location, prompt the user to enter the position.
// -> After every operation, the updated linked list should be displayed.


/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *temp;

struct node* createNode(int );
void insert_at_beginning(int );
void insert_at_end(int);
void insert_at_loc(int );
void del_at_beg();
void del_at_end();
void del_at_loc();
void reverse();
void display();

int main()
{
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1) Insert at Beginning\n");
        printf("2) Insert at End\n");
        printf("3) Insert at a Given Location\n");
        printf("4) Delete from Beginning\n");
        printf("5) Delete from End\n");
        printf("6) Delete from Specified Position\n");
        printf("7) Reverse the Linked List\n");
        printf("8) Print the Linked List\n");
        printf("0) Exit\n");
    
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int data;
                printf("Enter the data to insert at beginning: ");
                scanf("%d", &data);
                insert_at_beginning(data);
                break;
            }
            case 2: {
                int data;
                printf("Enter the data to insert at end: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            }
            case 3: {
                int data;
                printf("Enter the data to insert at given location: ");
                scanf("%d", &data);
                insert_at_loc(data);
                break;
            }
            case 4: {
                del_at_beg();
                break;
            }
            case 5: {
                del_at_end();
                break;
            }
            case 6: {
                del_at_loc();
                break;
            }
            case 7: {
                reverse();
                break;
            }
            case 8:
                display();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!!\n");
        }
    } while (choice != 0);
    return 0;
}

// Function to insert a node at the beginning 
void insert_at_beginning(int data){
    struct node * newnode = createNode(data);
    
    newnode->next = head;
    head = newnode;
}

// Function to insert a node at the end
void insert_at_end(int data){
    struct node * newnode = createNode(data);
    newnode->next = 0;
    newnode->prev =0;
    
    if(head == 0)
        head = temp = newnode;
    else{
        while(temp->next != 0){
            temp = temp->next; 
        }
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
}

// Function to insert a Specified Position
void insert_at_loc(int data){
    int pos, count = 1;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos < 1) { 
        printf("Invalid position!\n");
        return;
    }

    struct node* newnode = createNode(data);
    newnode->next =0;
    newnode->prev = 0;
    
    if (pos == 1) { 
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head; 
    while (count < pos - 1 && temp != NULL) { 
        temp = temp->next;
        count++;
    }
 
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev =newnode;
    
}

// Function to delete at beginning
void del_at_beg(){
    temp = head;
    if(head == 0)
        printf("Empty linked List");
    else{
        head = temp->next;
        head->prev = 0;
        free(temp);
    }
}

// Function to delete at end
void del_at_end(){
    temp = head;
    while(temp->next != 0){
        temp = temp->next;
    }
    temp->prev->next = 0;
    free(temp);
}

// Function to delete at Specified location
void del_at_loc(){
    int pos, count = 1;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    
    temp = head; 
    
    if (pos == 1) { 
        head = head->next;
        free(temp);
        return;
    }

    struct node *nextnode, * prevnode = NULL; 
    
    while (count < pos && temp != NULL) { 
        temp = temp->next;
        count++;
    }

    if (temp == NULL) { 
        printf("Position out of range!\n");
    } else {
        temp->prev->next =temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

// Function for Reverse the dobly linkedlist
void reverse(){
    struct node * currentnode, *nextnode;
    
    currentnode = head;
    while(currentnode != 0){
        nextnode = currentnode->next;
        currentnode->next = currentnode->prev;
        currentnode->prev = nextnode;
        currentnode = nextnode;
    }
}

// Function to create a new node and allocate memory
struct node* createNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) { 
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
// Function to display the dobly linked List
void display(){
    temp = head;
    if(temp == 0){
        printf("The linked list is empty.\n");
        return;
    }
    while(temp->next != 0){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
}
