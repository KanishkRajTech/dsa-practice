// Problem Statement:
// Implement a Queue using Linked List in C with the following functionalities:

// 1). Enqueue: Insert an element at the rear of the queue.
// 2). Dequeue: Remove an element from the front of the queue.
// 3). Peek: Display the front element without removing it.
// 4). Display: Print all elements currently present in the queue.

#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node * front = 0;
struct node * rear = 0;

void enqueue(int data);
void dequeue();
void display();
void peek();

int main()
{
     int ch, data;
    do{
        printf("Menu \n");
        printf("1). Enqueue \n");
        printf("2). Dequeue \n");
        printf("3). Peek \n");
        printf("4). Display \n");
        printf("0). Exit \n");
        printf("Enter your choice :-");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:{
                printf("Enter the data:-");
                scanf("%d",&data);
                enqueue(data);
                break;
            }
            case 2:{
                dequeue();
                break;
            }
            case 4:{
                display();
                break;
            }
            case 3:{
                peek();
                break;
            }
        } 
    }while(ch !=0);

    return 0;
}

// Function for Enqueue
void enqueue(data){
    struct node * newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = 0;
   
    if(front == 0 && rear == 0)
        front = rear = newnode;    
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

// Function for Dequeue
void dequeue(){
    struct node * temp;
    temp = front;
    if(front == 0 && rear==0)
        printf("List is empty\n");
    else{
        printf("%d",front->data);
        front = front->next;
        free(temp);
    }
}

// Function for Peek
void peek(){
    if(front == 0 && rear==0)
        printf("List is empty");
    else
        printf("%d",front->data);
}

// Function for Display
void display(){
    struct node *temp;
    if( front == 0 && rear ==0)
        printf("List is empty");
    else{
        temp = front;
        while(temp != 0){
            printf("%d",temp->data);
            temp = temp->next;
        }
    }
}
