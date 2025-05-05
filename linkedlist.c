struct Node{
    int data;
    struct Node* next;
}

void insertatbeg(struct Node** head ,int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertatend(struct Node** head ,int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    nextNode->next = NULL;
    
    if(*head == NULL){
        *head = newNode;
        return;
    }
    
    while(last->next != NULL){
        last = last->next;
    }
    
    last->next = newNode;
}

void insertAfter(struct Node* prev, int data){
    if(prev == NULL){
        printf("prev is NULL");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prev->next;
    prev->next = newNode;
}

void deleteByValue(struct Node** head, int data){
    struct Node* temp = *head;
    
    if(temp != NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }
    
    while(temp->data != NULL && temp->data != NULL){
        if(temp->next->data == data){
            struct Node* delete = temp->next;
            temp->next = delete->next;
            free(delete);
            return;
        }
        temp = temp->next;
    }
    
    printf("value was not found");
}

#include <iostream>

int main(int argc, char argv[][])
{
    std::cout<<"Hello World";

    return 0;
}
