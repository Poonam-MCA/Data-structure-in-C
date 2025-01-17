//PROGRAM TO CONVERT AN INFIX EXPRESSION INTO ITS EQUIVALENT PREFIX NOTATION 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char data[MAX_SIZE];
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

void push(struct Stack *stack, char c) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = c;
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    char c = stack->data[stack->top];
    stack->top--;
    return c;
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void infixToPrefix(char *infix, char *prefix) {
    struct Stack *stack = createStack();
    int i, j = 0;
    int length = strlen(infix);

    for (i = length - 1; i >= 0; i--) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            prefix[j++] = infix[i];
        } else if (infix[i] == ')') {
            push(stack, infix[i]);
        } else if (infix[i] == '(') {
            while (!isEmpty(stack) && stack->data[stack->top] != ')') {
                prefix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && stack->data[stack->top] != ')') {
                printf("Error: Mismatched parentheses\n");
                return;
            } else {
                pop(stack);
            }
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) < precedence(stack->data[stack->top])) {
                prefix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack)) {
        prefix[j++] = pop(stack);
    }

    for (i = 0; i < j / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[j - i - 1];
        prefix[j - i - 1] = temp;
    }

    prefix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
