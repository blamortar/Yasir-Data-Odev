#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if (top < 0) {
        return -1;
    } else {
        return stack[top--];
    }
}

int precedence(char symbol) {
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char item;
    char x;

    push('(');
    strcat(infix, ")");

    item = infix[i];

    while (item != '\0') {
        if (item == '(') {
            push(item);
        } else if (isalnum(item)) {
            postfix[j] = item;
            j++;
        } else if (isOperator(item)) {
            x = stack[top];
            while (isOperator(x) && precedence(x) >= precedence(item)) {
                postfix[j] = pop();
                j++;
                x = stack[top];
            }
            push(item);
        } else if (item == ')') {
            x = pop();
            while (x != '(') {
                postfix[j] = x;
                j++;
                x = pop();
            }
        }
        i++;
        item = infix[i];
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Infix ifadeyi girin: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix hali: %s\n", postfix);

    return 0;
}