#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max_queue 10

struct Node {
    int data;
    int priority;
    struct Node* nextNode;
};

/* Function to create a new node */
struct Node* newNode(int data, int priority) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->priority = priority;
    node->nextNode = NULL;
    return node;
}

/* Function to free all nodes of the queue */
void freeQueue(struct Node** head) {
    while (*head != NULL) {
        struct Node* temp = *head;
        *head = (*head)->nextNode;
        free(temp);
    }
}

/* Function to insert a new node in the priority queue */
void enqueue(struct Node** head, int data, int priority) {
    struct Node* new = newNode(data, priority);
    struct Node* current = *head;

    /* If the queue is empty or the new node has higher priority than the head node */
    if (*head == NULL || priority < (*head)->priority) {
        new->nextNode = *head;
        *head = new;
    }
    else {
        /* Traverse the queue until the correct position to insert the new node is found */
        while (current->nextNode != NULL && priority >= current->nextNode->priority) {
            current = current->nextNode;
        }
        new->nextNode = current->nextNode;
        current->nextNode = new;
    }
}

/* Function to delete the head node (node with the highest priority) from the priority queue */
void dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("Priority queue is empty.\n");
    }
    else {
        struct Node* temp = *head;
        *head = (*head)->nextNode;
        free(temp);
    }
}

/* Function to check if the priority queue is empty */
bool isEmpty(struct Node* head) {
    return head == NULL;
}

/* Function to check if the priority queue is full */
bool isFull(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->nextNode;
    }
    return count == max_queue;
}

void printQueue(struct Node* head){
    while(head!= NULL){
        printf("%d", head->data);
        if(head->nextNode != NULL){
            printf("->");
        }
        head = head->nextNode;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    int choice, data, priority;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull(head)) {
                    printf("Priority queue is full. Cannot insert new node.\n");
                    break;
                }
                printf("Enter the data value: ");
                scanf("%d", &data);
                printf("Enter the priority value: ");
                scanf("%d", &priority);
                enqueue(&head, data, priority);
                printf("The queue is: ");
                printQueue(head);
                break;

            case 2:
                dequeue(&head);
                printf("The queue is: ");
                printQueue(head);
                break;

            case 3:
                if (isEmpty(head)) {
                    printf("Priority queue is empty.\n");
                }
                else {
                    printf("Priority queue is not empty.\n");

                }
                break;

            case 4:
                if (isFull(head)) {
                    printf("Priority queue is full.\n");
                }
                else {
                    printf("Priority queue is not full.\n");
                }
                break;

            case 5:
                printf("Exiting...\n");
                 /* Free all nodes of the queue before exiting */
                freeQueue(&head);
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}