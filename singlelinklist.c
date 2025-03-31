#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new element at the beginning of the singly linked list
struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode; // return new head
}

// Function to insert a new element at the end of the singly linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode; // If list is empty, new node becomes head
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head; // return unchanged head
}

// Function to insert a new element at a specific position in the singly linked list
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        return insertAtFirst(head, data); // Handle insertion at the start
    }
    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return head; // Return unchanged list if position is invalid
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head; // return unchanged head
}

// Function to delete the first node of the singly linked list
struct Node* deleteFromFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head; // return new head
}

// Function to delete the last node of the singly linked list
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node* temp = head;
    if (temp->next == NULL) {
        free(temp);
        return NULL; // If only one node, return NULL
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head; // return unchanged head
}

// Function to delete a node at a specific position in the singly linked list
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (position == 0) {
        return deleteFromFirst(head); // Handle deletion at the start
    }
    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return head; // Return unchanged list if position is invalid
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    return head; // return unchanged head
}

// Function to print the LinkedList
void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver Code
int main() {
    struct Node* head = NULL;

    head = insertAtFirst(head, 10);
    printf("Linked list after inserting the node: 10 at the beginning \n");
    print(head);

    head = insertAtEnd(head, 20);
    printf("Linked list after inserting the node: 20 at the end \n");
    print(head);

    head = insertAtEnd(head, 5);
    printf("Linked list after inserting the node: 5 at the end \n");
    print(head);

    head = insertAtEnd(head, 30);
    printf("Linked list after inserting the node: 30 at the end \n");
    print(head);

    head = insertAtPosition(head, 15, 2);
    printf("Linked list after inserting the node: 15 at position 2 \n");
    print(head);

    head = deleteFromFirst(head);
    printf("Linked list after deleting the first node: \n");
    print(head);

    head = deleteFromEnd(head);
    printf("Linked list after deleting the last node: \n");
    print(head);

    head = deleteAtPosition(head, 1);
    printf("Linked list after deleting the node at position 1: \n");
    print(head);

    return 0;
}
