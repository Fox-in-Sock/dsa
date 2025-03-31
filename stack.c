#include <stdio.h>
#define MAX 5  // Renamed to follow naming conventions

int stack[MAX];
int top = -1;

// Function to check if the stack is empty
int isempty() {
    return top == -1;  
}

// Push function to insert an element into the stack
void push() {
    int data;
    printf("Enter the number: ");
    scanf("%d", &data);

    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = data;
        printf("Pushed %d onto the stack\n", data);
    }
}

// Pop function to remove an element from the stack
void pop() {
    if (isempty()) {
        printf("Stack underflow\n");
    } else {
        int x = stack[top--];
        printf("The value popped is %d\n", x);
    }
}

// Display function to print the elements of the stack
void display() {
    if (isempty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Stack Operations Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
