#include <stdio.h>
#include <stdlib.h>

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
    struct Node* prev = NULL;
    
    if(temp != NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }
    
    while(temp != NULL && temp->data != data){
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL){
        printf("value was not found");
        return;
    }
    
    prev->next = temp->next;
    free(temp);
}

void printlist(struct Node* head){
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->data;
    }
    printf("NULL\n");
}

int main()
{

    return 0;
}
