// Problem Statement:
// Create a Circular Queue Implementation using a Linked List in C. The program should support the following operations:

// 1).Enqueue: Insert an element at the rear of the queue, ensuring circular linkage.
// 2).Dequeue: Remove and display the front element of the queue, handling the case when the queue is empty or contains only one element.
// 3).Peek: Display the front element without removing it.
// 4).Display: Show all elements in the queue in circular order, starting from the front.

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


void enqueue(data){
    struct node *newnode;
    newnode  = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next =0;
    
    if(rear == 0){
        front = rear = newnode;
        rear->next = front;
    }
    else{
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void dequeue(){
    struct node * temp = front;
    if(front == NULL)
        printf("Queue is Empty\n");
    else if(front == rear){
        front = rear = 0;
        free(temp);
    }
    else{
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void peek(){
    if(front == 0 && rear == 0)
        printf("Queue is Empty\n");
    else
        printf("%d",front->data);
}

void display(){
    struct node * temp;
    temp = front;
    if(temp == 0 && rear == 0)
        printf("Queue is Empty\n");
    else{
        while(temp->next != front){
            printf("%d ->",temp->data);
            temp = temp->next;
        }
        printf("%d",front->data);
    }
}