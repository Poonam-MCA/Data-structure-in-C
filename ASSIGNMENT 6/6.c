//PROGRAM TO EVALUATE A PREFIX EXPRESSION 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

struct Stack *createStack() {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

int evaluatePrefix(char *prefix) {
    struct Stack *stack = createStack();
    int i, operand1, operand2;

    // Process the expression from right to left
    for (i = strlen(prefix) - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            push(stack, prefix[i] - '0'); // Convert ASCII digit to integer
        } else {
            operand1 = pop(stack);
            operand2 = pop(stack);
            switch (prefix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero error\n");
                        return -1;
                    }
                    push(stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }
        }
    }

    return pop(stack); // The final element in the stack is the result
}

int main() {
    char prefix[MAX_SIZE];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    int result = evaluatePrefix(prefix);

    if (result != -1) {
        printf("Result: %d\n", result);
    }

    return 0;
}
