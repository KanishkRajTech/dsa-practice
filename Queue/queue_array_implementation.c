
// Problem Statement:
// Implement a Queue using an Array in C with the following functionalities:

// 1). Enqueue: Add an element to the rear of the queue.
// 2). Dequeue: Remove an element from the front of the queue.
// 3). Peek: Display the front element of the queue without removing it.
// 4). Display: Show all elements currently in the queue.


#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
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

// Fuction for Qnueue the element
void enqueue(data){
    if(rear == N-1)
        printf("Queue is Overflow");
    else if(front == -1 && rear == -1){
        front = rear =0;
        queue[rear] = data;
    }
    else{
        rear++;
        queue[rear] = data;
    }
    
}

// Function for Dequeue element
void dequeue(){
    if(front == -1 && rear == -1)
        printf("Queue is empty");
    else if(front == rear)
        front = rear = -1;
    else
        front++;
}

// Function to display the all elements
void display(){
    int i;
    if(front == -1 && rear == -1)
        printf("Queue is empty");
    else{
        for(i = front; i < rear +1; i++)
            printf("%d ",queue[i]);
    }
}

// Function to peek the element
void peek(){
    if(front == -1 && rear == -1)
        printf("Queue is empty");
    else
        printf("%d", queue[front]);
}
