
// Problem Statement:
// -> Write a C program to implement a singly linked list with the following functionalities:

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


#include <stdio.h>
#include <stdlib.h> 


struct node {
    int data;            
    struct node* next;  
};

struct node* head = NULL, *temp; 


struct node* createNode(int);
void insert_at_beginning(int);
void insert_at_end(int);
void insert_at_loc(int);
void del_at_beg();
void del_at_end();
void del_at_loc();
void reverse();
void display();

int main() {
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
void insert_at_beginning(int data) {
    struct node* newnode = createNode(data);
    newnode->next = head; 
    head = newnode;
}

// Function to insert a node at the end
void insert_at_end(int data) {
    struct node* newnode = createNode(data); 
    if (head == NULL) { 
        head = newnode;
        return;
    }
    struct node* temp = head; 
    while (temp->next != NULL) { 
        temp = temp->next;
    }
    temp->next = newnode;
}

// Function to insert a node at a specific position 
void insert_at_loc(int data) {
    int pos, count = 1;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos < 1) { 
        printf("Invalid position!\n");
        return;
    }

    struct node* newnode = createNode(data);

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

    if (temp == NULL) { 
        printf("Position out of range!\n");
    } else {
        newnode->next = temp->next; 
        temp->next = newnode;
    }
}

// Function to delete a node from the beginning 
void del_at_beg() {
    if (head == NULL) { 
        printf("List is empty, nothing to delete.\n");
        return;
    }
    temp = head; 
    head = head->next;
    free(temp); 
}

// Function to delete a node from the end
void del_at_end() {
    if (head == NULL) { 
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct node* prenode;
    temp = head;
    
    while (temp->next != NULL) { 
        prenode = temp;
        temp = temp->next;
    }
    
    if (temp == head) {
        head = NULL;
    } else {
        prenode->next = NULL; 
    }
    
    free(temp); 
}

// Function to delete a node at a specific position
void del_at_loc() {
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

    struct node* prevnode = NULL; 
    while (count < pos && temp != NULL) { 
        prevnode = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) { 
        printf("Position out of range!\n");
    } else {
        prevnode->next = temp->next; 
        free(temp);
    }
}

// Function to reverse the linked list
void reverse() {
    struct node *nextnode, *prenode, *currentnode;
    prenode = NULL;
    currentnode = nextnode = head;
    while (nextnode != NULL) { 
        nextnode = nextnode->next; 
        currentnode->next = prenode; 
        prenode = currentnode; 
        currentnode = nextnode; 
    }
    head = prenode; 
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

// Function to display the linked list
void display() {
    struct node* temp = head; 
    if (temp == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    printf("Linked List Elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
