#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int n) {
    struct Node *newNode, *temp;
    int value;
    for (int  i = 1;i<=n;i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("enter data: ");
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            temp = newNode;
        }else{
            temp->next = newNode;
            temp = newNode;
        }
    }
}

void displayList() {
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp -> next;
    }
    printf("NULL \n");
}
void reversed(){
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;
    while(current != NULL){
        next= current->next;
        current->next=prev;
        prev=current;
        current= next;
    }
    head = prev;
}
int main() {
    int n;
    printf("enter the number of nodes\n");
    scanf("%d",&n);

    createNode(n);

    printf("\n ORiginal linked list : ");
    displayList();

    reversed();

    printf("\n Reversed Linked list: ");
    displayList();
   

    return 0;
}
