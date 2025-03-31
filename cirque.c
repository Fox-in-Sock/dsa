#include <stdio.h>
#include <stdlib.h>

#define n 5

int queue[n];
int rear = -1;
int front = -1;

void enque(int x){
    if ((rear + 1) % n == front){
        printf("Overflow\n");
    } else if (front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear = (rear + 1) % n;
        queue[rear] = x;
    }
    printf("Enqueued: %d\n", x);
}

void dequeue(){
    if (front == -1 && rear == -1){
        printf("The queue is empty\n");
    } else if (front == rear){
        printf("The dequeued data is %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("The dequeued data is %d\n", queue[front]);
        front = (front + 1) % n;
    }
}

void display(){
    if (front == -1 && rear == -1){
        printf("The queue is empty\n");
    } else if (front <= rear){
        printf("Queue elements:\n");
        for(int i = front; i <= rear; i++){
            printf("%d\n", queue[i]);
        }
    } else {
        printf("Queue elements:\n");
        for(int i = front; i < n; i++){
            printf("%d\n", queue[i]);
        }
        for(int i = 0; i <= rear; i++){
            printf("%d\n", queue[i]);
        }
    }
}

int main(){
    int choice, data;
    while(1){
        printf("\nQueue Operations Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enque(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
    return 0;
}
