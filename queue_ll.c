#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* enqueue(struct Node* rear, int data) {
    struct Node* newNode = createNode(data);
    if (rear == NULL) {
        return newNode;
    }
    rear->next = newNode;
    return newNode;
}

struct Node* dequeue(struct Node* front) {
    if (front == NULL) {
        printf("Queue underflow! The queue is empty.\n");
        return front;
    }
    struct Node* temp = front;
    int dequeuedData = temp->data;
    front = temp->next;
    free(temp);
    printf("%d dequeued from queue.\n", dequeuedData);
    return front;
}

int peek(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return front->data;
}

int isEmpty(struct Node* front) {
    return front == NULL;
}

void printQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Print Queue\n");
        printf("5. Check if Queue is Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                if (rear == NULL) {
                    front = rear = enqueue(rear, value);
                } else {
                    rear = enqueue(rear, value);
                }
                break;
            case 2:
                front = dequeue(front);
                if (front == NULL) rear = NULL; // If the queue becomes empty, rear should also be NULL.
                break;
            case 3:
                value = peek(front);
                if (value != -1)
                    printf("Front element is %d\n", value);
                break;
            case 4:
                printQueue(front);
                break;
            case 5:
                if (isEmpty(front))
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
