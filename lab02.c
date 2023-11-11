#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return (s->top == -1);
}

int isFull(Stack* s) {
    return (s->top == MAX_SIZE - 1);
}

void push(Stack* s, char c) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->stack[++(s->top)] = c;
}

char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->stack[(s->top)--];
}

int isOperand(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
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
    }
    return -1;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initialize(&stack);
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            push(&stack, infix[i]);
        else if (infix[i] == ')') {
            while (!isEmpty(&stack) && stack.stack[stack.top] != '(')
                postfix[j++] = pop(&stack);
            if (!isEmpty(&stack) && stack.stack[stack.top] != '(')
                printf("Invalid Expression\n");
            else
                pop(&stack);
        }
        else {
            while (!isEmpty(&stack) && precedence(infix[i]) <= precedence(stack.stack[stack.top]))
                postfix[j++] = pop(&stack);
            push(&stack, infix[i]);
        }
    }
    while (!isEmpty(&stack))
        postfix[j++] = pop(&stack);
    postfix[j] = '\0';
}

void infixToPrefix(char* infix, char* prefix) {
    int i, j = 0;
    int len = strlen(infix);

    for (i = len - 1; i >= 0; i--) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    char reversedInfix[MAX_SIZE];
    strcpy(reversedInfix, infix);
    strrev(reversedInfix);

    char postfix[MAX_SIZE];
    infixToPostfix(reversedInfix, postfix);

    strrev(postfix);

    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX_SIZE];
    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    char postfix[MAX_SIZE];
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    char prefix[MAX_SIZE];
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}

 