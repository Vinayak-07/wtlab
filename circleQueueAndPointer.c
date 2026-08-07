#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertBeginning(int value) {
    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the beginning\n", value);
}

void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("%d inserted at the end\n", value);
}

void insertAtPosition(int value, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insertBeginning(value);
        return;
    }

    struct Node *newNode = createNode(value);
    struct Node *temp = head;
    int i;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted at position %d\n", value, position);
}

void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    printf("%d deleted from beginning\n", temp->data);
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (head->next == NULL) {
        printf("%d deleted from end\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    printf("%d deleted from end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        deleteBeginning();
        return;
    }

    struct Node *temp = head;
    int i;

    for (i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("%d deleted from position %d\n", nodeToDelete->data, position);
    free(nodeToDelete);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

void freeList() {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at specific position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &position);
                insertAtPosition(value, position);
                break;
            case 4:
                deleteBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                displayList();
                break;
            case 8:
                freeList();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}



#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enQueue(int item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    queue[rear] = item;
    printf("%d inserted into the queue\n", item);
}

void deQueue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("%d deleted from the queue\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void peek() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Front element = %d\n", queue[front]);
    }
}

void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    i = front;

    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int choice, item;

    do {
        printf("\n--------Circular Queue--------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                enQueue(item);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Program ended\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
