// Problem Statement:
// -> Write a C program to implement a circular linked list with the following functionalities:

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

struct node* tail = NULL;

struct node* createNode(int data);
void insert_at_beginning(int data);
void insert_at_end(int data);
void insert_at_loc(int data, int pos);
void del_at_beg();
void del_at_end();
void del_at_loc(int pos);
void reverse();
void display();

int main() {
    int choice, data, pos;

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
            case 1:
                printf("Enter the data to insert at beginning: ");
                scanf("%d", &data);
                insert_at_beginning(data);
                break;
            case 2:
                printf("Enter the data to insert at end: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insert_at_loc(data, pos);
                break;
            case 4:
                del_at_beg();
                break;
            case 5:
                del_at_end();
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                del_at_loc(pos);
                break;
            case 7:
                reverse();
                break;
            case 8:
                display();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to create a new node
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

// Function to insert a node at the beginning
void insert_at_beginning(int data) {
    struct node* newnode = createNode(data);
    if (tail == NULL) {
        tail = newnode;
        tail->next = newnode;
    } else {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

// Function to insert a node at the end
void insert_at_end(int data) {
    struct node* newnode = createNode(data);
    if (tail == NULL) {
        tail = newnode;
        tail->next = newnode;
    } else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

// Function to insert a node at a specific position
void insert_at_loc(int data, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insert_at_beginning(data);
        return;
    }

    struct node* newnode = createNode(data);
    struct node* temp = tail->next;
    int count = 1;

    while (count < pos - 1 && temp != tail) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1) {
        printf("Position out of range!\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    if (temp == tail) {
        tail = newnode;
    }
}

// Function to delete a node from the beginning
void del_at_beg() {
    if (tail == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct node* temp = tail->next;
    if (tail == temp) {
        tail = NULL;
    } else {
        tail->next = temp->next;
    }
    free(temp);
}

// Function to delete a node from the end
void del_at_end() {
    if (tail == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct node* current = tail->next;
    if (current == tail) {
        free(tail);
        tail = NULL;
        return;
    }

    while (current->next != tail) {
        current = current->next;
    }

    current->next = tail->next;
    free(tail);
    tail = current;
}

// Function to delete a node at a specific position
void del_at_loc(int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (tail == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if (pos == 1) {
        del_at_beg();
        return;
    }

    struct node* temp = tail->next;
    struct node* prev = NULL;
    int count = 1;

    while (count < pos && temp != tail) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count != pos || temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    prev->next = temp->next;
    if (temp == tail) {
        tail = prev;
    }
    free(temp);
}

// Function to reverse the linked list
void reverse() {
    if (tail == NULL || tail->next == tail) {
        return; // No need to reverse if the list is empty or has one node
    }

    struct node *prev = NULL, *current = tail->next, *next = NULL, *head = tail->next;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    tail->next = prev;
    tail = head;
}

// Function to display the linked list
void display() {
    if (tail == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    struct node* temp = tail->next;
    printf("Linked List Elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}
