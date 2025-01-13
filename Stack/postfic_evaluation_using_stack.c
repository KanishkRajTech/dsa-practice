
// Problem Statement:
// Write a C program to evaluate a postfix expression using a stack. The program should:

// 1). Allow the user to input a valid postfix expression consisting of integers, operators (+, -, *, /, ^), and spaces.
// 2). Use a stack to store intermediate results during the evaluation process.
// 3). For each character in the postfix expression:
//     -> If it is an operand (number), push it onto the stack.
//     -> If it is an operator, pop the top two elements from the stack, apply the operator, and push the result back onto the stack.
// 4). Display the final result after evaluating the entire postfix expression.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function to push an element 
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

// Function to pop an element 
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        // Skip spaces
        if (expr[i] == ' ') {
            continue;
        }

        // If the character is a digit, push it onto the stack
        if (isdigit(expr[i])) {
            int num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--; 
            push(num);
        }
        // If the character is an operator, pop two elements and perform the operation
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^') {
            int A = pop();
            int B = pop();
            int result;

            switch (expr[i]) {
                case '+': result = B + A; break;
                case '-': result = B - A; break;
                case '*': result = B * A; break;
                case '/': 
                    if (A == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    result = B / A; 
                    break;
                case '^': result = pow(B, A); break;
                default:
                    printf("Invalid operator: %c\n", expr[i]);
                    exit(1);
            }
            // Push the result back onto the stack
            push(result);
        }
    }

    return pop();
}

int main() {
    char postfixExpr[MAX];

    printf("Enter a postfix expression: ");
    fgets(postfixExpr, MAX, stdin);  // Use fgets to allow spaces in input

    int result = evaluatePostfix(postfixExpr);
    printf("Result of postfix expression evaluation: %d\n", result);

    return 0;
}
