#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
}

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value){
    struct Node* newNode = (struct Node)malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->next = NULL;
    
    if(rear == NULL){
        rear = front = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    
    printf("enqueue %d\n", value);
}

void dequeue(){
    if(rear == NULL){
        printf("queue is empty\n");
        return;
    }
    
    struct Node* temp = front;
    front = front->next;
    
    printf("dequeued: %d",temp->data);
    free(temp);
}

void peek() {
    if(front == NULL){
        printf("Queue is empty\n");
    } 
    else{
        printf("Front element: %d\n", front->data);
    }
}

void display() {
    struct Node* temp = front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    peek();

    return 0;
}
