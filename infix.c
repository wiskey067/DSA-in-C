#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to initialize a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to push a character onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->array[++stack->top] = item;
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}

// Function to get the top element of the stack without popping
char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack(MAX_SIZE);
    int i, j;

    for (i = 0, j = -1; infix[i]; ++i) {
        if (isalnum(infix[i])) {
            postfix[++j] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[++j] = pop(stack);
            }
            pop(stack); // Discard the '('
        } else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(infix[i])) {
                postfix[++j] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(stack)) {
        postfix[++j] = pop(stack);
    }

    postfix[++j] = '\0';
}

// Function to check precedence of operators
int precedence(char ch) {
    if (ch == '^') {
        return 3;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else {
        return 0;
    }
}

// Main program
int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);

    return 0;
}
