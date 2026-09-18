#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;   
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node* createNewNode(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertBeginning(int value){
    struct Node *newNode = createNewNode(value);
    if(head == NULL){
        head = tail = newNode;
    }else{
        newNode->next = head;   
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at beginning \n", value);
}

void insertEnd(int value){
    struct Node *newNode = createNewNode(value);
    if(head == NULL){
        head = tail = newNode;
    }else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("%d inserted at end \n", value);
}

void insertAtPosition(int value, int pos){
    struct Node *newNode, *temp;

    if(pos == 1){
        insertBeginning(value);   
        return;
    }
    newNode = createNewNode(value);
    temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("invalid position \n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode;
    temp->next = newNode;   
    printf("%d inserted at position %d \n", value, pos);
}

void deleteBeginning(){
    struct Node *temp;
    if(head == NULL){
        printf("list is empty \n");
        return;
    }
    temp = head;
    if(head == tail){
        head = tail = NULL;
    }else{
        head = head->next;
        head->prev = NULL;
    }
    printf("%d deleted from beginning \n", temp->data);
    free(temp);
}

void deleteEnd(){
    struct Node *temp;
    if(tail == NULL){
        printf("list is empty \n");
        return;
    }
    temp = tail;
    if(head == tail){
        head = tail = NULL;
    }else{
        tail = tail->prev;
        tail->next = NULL;
    }
    printf("%d deleted from end \n", temp->data);
    free(temp);
}

void deletePosition(int pos){  
    struct Node *temp;
    if(head == NULL){
        printf("list is empty \n");
        return;
    }
    if(pos == 1){
        deleteBeginning();
        return;
    }
    temp = head;
    for(int i = 1; i < pos && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("invalid position \n");
        return;
    }
    if(temp == tail){
        deleteEnd();
        return;
    }
    temp->prev->next = temp->next;   
    temp->next->prev = temp->prev;
    printf("%d deleted from position %d \n", temp->data, pos);
    free(temp);
}

void displayForward(){
    struct Node *temp = head;
    if(head == NULL){
        printf("list is empty\n");
        return;
    }
    printf("Forward: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward(){
    struct Node *temp = tail;   /* was head — must start from tail */
    if(tail == NULL){
        printf("list is empty\n");
        return;
    }
    printf("Backward: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    insertBeginning(20);
    insertBeginning(10);
    insertEnd(40);
    insertAtPosition(30, 3);
    displayForward();
    displayBackward();
    deleteBeginning();
    displayForward();
    deleteEnd();
    displayForward();
    deletePosition(2);
    displayForward();
    return 0;
}
