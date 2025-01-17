//MENU DRIVEN PROGRAM TO ACCOMPLISH THE FOLLOWING FUNCTIONALITIES IN STACK USING AN ARRAY 
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
int isFull() {
    return top == MAX_SIZE - 1;
}

// Function to insert an element into the stack
void push(int data) {
    if (isFull()) {
        printf("Stack is full.\n");
        return;
    }
    top++;
    stack[top] = data;
    printf("%d pushed.\n", data);
}

// Function to delete an element from the stack
void pop() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("%d popped.\n", stack[top]);
    top--;
}

// Function to return the value of the topmost element of the stack
int peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack[top];
}

// Function to display the elements of the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Top element: %d\n", peek());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
