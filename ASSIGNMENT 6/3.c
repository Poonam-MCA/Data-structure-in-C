//PROGRAM TO CONVERT AN INFIX EXPRESSION INTO TIS EQUIVALENT POSTFIX NOTATION 
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

void infixToPostfix(char *infix, char *postfix) {
    struct Stack *stack = createStack();
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && stack->data[stack->top] != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && stack->data[stack->top] != '(') {
                printf("Error: Mismatched parentheses\n");
                return;
            } else {
                pop(stack);
            }
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(stack->data[stack->top])) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
