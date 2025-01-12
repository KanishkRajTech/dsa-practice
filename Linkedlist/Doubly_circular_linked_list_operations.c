#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *tail,*temp;

struct node* createNode(int );
void display();
void insert_at_beginning(int );
void insert_at_end(int);
void insert_at_loc(int );
void del_at_beg();
void del_at_end();
void del_at_loc();

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
        printf("7) Print the Linked List\n");
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
            case 7:
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
// Function to insert the data at beginning
void insert_at_beginning(int data ){
    struct node *newnode;
    newnode = createNode(data);
    
    if(head == 0){
        head = tail = newnode;
        newnode->prev = tail;
        newnode->next = head;
    }
    else{
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = tail;
        tail->next = newnode;
        head = newnode;
    }
}

// Function to insert to end
void insert_at_end(int data){
    struct node *newnode;
    newnode = createNode(data);
    
    if(head == 0){
        head = tail = newnode;
        newnode->prev = tail;
        newnode->next = head;
    }
    else{
        newnode->prev = tail;
        tail->next = newnode;
        newnode->next = head;
        head->prev = newnode;
        tail = newnode;
    }
    
}

// Function to insert the data at Specified location
void insert_at_loc(int data ){
     int pos, count = 1;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos < 1) { 
        printf("Invalid position!\n");
        return;
    }
    else if(pos == 1){
        insert_at_beginning(data);
    }
    else{
        struct node *newnode;
        newnode = createNode(data);
        while(count < pos-1){
            temp = temp->next;
            count++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
}

// Function to delete the node at beginning
void del_at_beg(){
    temp = head;
    if( head == 0){
        printf("List is empty");
    }
    else if(head->next == head){
        head = tail =0;
        free(temp);
    }
    else{
        head = head->next;
        head->prev =tail;
        tail->next = head;
        free(temp);
    }
}

// Function to delete the node at end
void del_at_end(){
    temp = tail;
    if(head == 0){
        printf("List is empty");
    }
    else if(head->next == head){
        head = tail =0;
        free(temp);
    }
    else{
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
}

// Function to delete the node at Specified location
void del_at_loc(){
    int pos, count = 1;
    temp = head; 
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    else if(pos == 1){
        del_at_beg();
    }
    else{
        while( count < pos){
            temp= temp->next;
            count++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
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
    newnode->prev = NULL;
    return newnode;
}

// Function to Display the List
void display() {
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }
    struct node *temp = head;
    printf("Linked List Elements: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

