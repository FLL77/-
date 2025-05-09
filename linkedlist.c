#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void addbeg(int value, struct Node** head){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
    
}

void addafternode(int value, struct Node* prev){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if(prev == NULL){
        return;
    }
    
    newNode->data = value;
    newNode->next = prev->next;
    prev->next = newNode;
}

void addlast(int value, struct Node** head){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->next = NULL;
    newNode->data = value;
    
    if(*head == NULL){
        *head = newNode;
        return;
    }
    
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newNode;
}

void deletebyvalue(int value, struct Node **head){
    struct Node* temp= *head;
    struct Node* prev = NULL;
    
    if(temp != NULL && temp->data == value){
        *head = temp->next;
        free(temp);
        return;
    }
    
    while(temp != NULL &&  temp->data != value){
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL){
        printf("value is not found\n");
        return;
    }
    
    prev->next = temp->next;
    free(temp);
}

void printlist(struct Node* head){
    if(head == NULL){
        printf("list is empty\n");
        return;
    }
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL");
}

int main() {
    struct Node* head = NULL;

    addbeg(10, &head);         // List: 10
    addbeg(20, &head);         // List: 20 -> 10
    addlast(5, &head);         // List: 20 -> 10 -> 5
    addafternode(15, head);    // List: 20 -> 15 -> 10 -> 5
    deletebyvalue(10, &head);  // List: 20 -> 15 -> 5
    deletebyvalue(100, &head); // Should print "value is not found"

    printlist(head);  // Expected output: 20 -> 15 -> 5 -> NULL

    return 0;
}

