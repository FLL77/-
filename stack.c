#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("pushed: %d\n",value);
}

void pop(){
    struct Node* temp = top;
    
    top = top->next;
    printf("popped: %d\n",temp->data);
    free(temp);
}

void peek(){
    if(top == NULL){
        printf("stack is empty\n");
    }
    else{
        printf("Top number: %d\n",top->data);
    }
}

void display(){
    if(top == NULL){
        printf("stack is empty");
        return;
    }
    
    struct Node* temp = top;
    
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    pop();
    display();

    peek();

    return 0;
}
