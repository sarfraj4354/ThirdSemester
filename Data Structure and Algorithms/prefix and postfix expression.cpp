#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1; // fixed initialization

// Stack operations
void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to reverse a string
void reverse(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

// Infix to Postfix conversion
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char item;

    printf("\n+---------------+----------------+----------------+\n");
    printf("| Scanned Symbol | Operator Stack | Operand Stack |\n");
    printf("+---------------+----------------+----------------+\n");

    for (i = 0; infix[i] != '\0'; i++) {
        item = infix[i];
        if (item == ' ')
            continue;

        if (isalnum(item)) {
            postfix[j++] = item;
            postfix[j] = '\0';
        } else if (item == '(') {
            push(item);
        } else if (item == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
                postfix[j] = '\0';
            }
            if (top != -1) pop(); // pop '('
        } else if (isOperator(item)) {
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix[j++] = pop();
                postfix[j] = '\0';
            }
            push(item);
        }

        char opStack[MAX] = "", operand_Stack[MAX] = "";
        if (top >= 0)
            strncpy(opStack, stack, top + 1);
        else
            strcpy(opStack, " ");
        strcpy(operand_Stack, postfix);
        printf("| %-13c | %-14s | %-14s |\n", item, opStack, operand_Stack);
    }

    while (top != -1) {
        postfix[j++] = pop();
        postfix[j] = '\0';

        char opStack[MAX] = "", operand_Stack[MAX] = "";
        if (top >= 0)
            strncpy(opStack, stack, top + 1);
        else
            strcpy(opStack, " ");
        strcpy(operand_Stack, postfix);
        printf("| %-13s | %-14s | %-14s |\n", " ", opStack, operand_Stack);
    }

    printf("+---------------+----------------+----------------+\n");
}

// Infix to Prefix conversion
void infixToPrefix(char infix[], char prefix[]) {
    char temp[MAX], postfix[MAX] = {0};
    strcpy(temp, infix);
    reverse(temp);

    // Swap parentheses
    for (int i = 0; temp[i] != '\0'; i++) {
        if (temp[i] == '(')
            temp[i] = ')';
        else if (temp[i] == ')')
            temp[i] = '(';
    }

    printf("\nConversion for Prefix (in reverse):\n");
    infixToPostfix(temp, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}

// Main driver
int main() {
    printf("\tCompiled by Sarfraj Alam\n");

    char infix[MAX], postfix[MAX] = {0}, prefix[MAX] = {0};

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    while (1) {
        int choice;
        printf("\nChoose conversion:\n");
        printf("1. Infix to Postfix\n");
        printf("2. Infix to Prefix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                top = -1;
                memset(postfix, 0, sizeof(postfix));
                infixToPostfix(infix, postfix);
                printf("\nPostfix expression: %s\n", postfix);
                break;

            case 2:
                top = -1;
                memset(prefix, 0, sizeof(prefix));
                infixToPrefix(infix, prefix);
                printf("\nPrefix expression: %s\n", prefix);
                break;

            case 3:
                printf("Program exited.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

