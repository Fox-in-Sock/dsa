#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        return insertAtFirst(head, data);
    }
    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* deleteFromFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node* temp = head;
    if (temp->next == NULL) {
        free(temp);
        return NULL;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (position == 0) {
        return deleteFromFirst(head);
    }
    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return head;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    return head;
}

void print(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nSingly Linked List Menu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from a specific position\n");
        printf("7. Print the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtFirst(head, data);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter the value to insert and the position: ");
                scanf("%d %d", &data, &position);
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                head = deleteFromFirst(head);
                break;
            case 5:
                head = deleteFromEnd(head);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 7:
                printf("The current linked list is: ");
                print(head);
                break;
            case 8:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
