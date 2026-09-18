#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;   
};

struct Node *head = NULL;

struct Node* createNewNode(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertBeginning(int value){
    struct Node *newNode;
    struct Node *last;
    newNode = createNewNode(value);
    if(head == NULL){
        head = newNode;
        newNode->next=newNode;
        newNode->prev=newNode;
    }else{
        last = head->prev;
        newNode->next= head;
        newNode->prev = last;
        last->next= newNode;
        head->prev=newNode;
        head = newNode;
    }
    printf("%d inserted at beginning \n", value);
}

void insertEnd(int value){
    struct Node *newNode;
    struct Node *last;
    newNode = createNewNode(value);
    if(head == NULL){
        head = newNode;
        newNode->next=newNode;
        newNode->prev=newNode;
    }else{
        last = head->prev;
        newNode->next= head;
        newNode->prev = last;
        last->next= newNode;
        head->prev=newNode;
    }
    printf("%d inserted at end \n", value);
}

void insertAtPosition(int value, int pos){
    struct Node *newNode, *temp;
    int i;

    if(pos == 1){
        insertBeginning(value);   
        return;
    }
    if(head == NULL){
        printf("invalid position \n");
        return;
    }
    temp = head;
    for(int i = 1; i < pos - 1; i++){
        temp = temp->next;
        if(temp == head){
            printf("invalid position\n");
            return;
        }
    }
    newNode = createNewNode(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    printf("%d inserted at position %d \n", value, pos);
}

void deleteBeginning(){
    struct Node *temp;
    struct Node *last;
    if(head == NULL){
        printf("list is empty \n");
        return;
    }
    temp = head;
    if(head->next == head){
        head  = NULL;
        free(temp);
        printf("Node deleted from begninning\n");
        return;
    }
    last = head->prev;
    head = head->next;

    last->next = head;
    head-> prev = last;

    printf("%d deleted from beginning \n", temp->data);
    free(temp);
}

void deleteEnd(){
    struct Node *last, *secondLast;
    if(head->next == head){
        printf("Node deleted from end\n");
        free(head);
        head  = NULL;
        return;
    }
    last = head->prev;
    secondLast = last->prev;
    secondLast->next = head;
    head -> prev = secondLast;
    printf("%d deleted from end \n", head->data);
    free(last);
}

void deletePosition(int pos){  
    struct Node *temp;
    int i;
    if(head == NULL){
        printf("list is empty \n");
        return;
    }
    if(pos == 1){
        deleteBeginning();
        return;
    }
    temp = head;
    for(int i = 1; i < pos; i++){
        temp = temp->next;
        if(temp == head){
            printf("invalid position");
            return;
        }
    }
    if(temp == head ->prev){
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
    temp = head;
    printf("forward:");
    do{
        printf("%d",temp->data);
        temp = temp->next;
    }while(temp!=head);
    printf("\n");
}

void displayBackward(){
    struct Node *temp;
    struct Node *last;
    if(head == NULL){
        printf("list is empty\n");
        return;
    }
    last = head->prev;
    temp = last;
    printf("Backward: ");
    do{
        printf("%d",temp->data);
        temp = temp->prev;
    }while(temp!=last);
    printf("\n");
}

int main()
{
    insertBeginning(20);
    insertBeginning(10);
    insertEnd(30);
    insertEnd(40);

    displayForward();
    displayBackward();
    
    insertAtPosition(25,3);
    displayForward();

    deleteBeginning();
    displayForward();
    
    deleteEnd();
    displayForward();
    
    deletePosition(2);
    displayForward();
    displayBackward();
    return 0;
}
