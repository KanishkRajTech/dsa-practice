
// Question:
// Write a C program to evaluate a prefix expression using a stack. The program should:

// 1). Read a prefix expression from the user.
// 2). Evaluate the expression by scanning it from right to left.
// 3). Use a stack to store intermediate results of the evaluation.
// 4). Support the following operators: +, -, *, /, ^.
// 5). Handle multi-digit operands and division by zero.
// 6). Display the final result of the prefix evaluation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// Function to evaluate a prefix expression
int evaluatePrefix(char* expr) {
    int i;

    for (i = strlen(expr) - 1; i >= 0; i--) {
        if (expr[i] == ' ') {
            continue;
        }

        if (isdigit(expr[i])) {
            int num = 0, base = 1;

            while (i >= 0 && isdigit(expr[i])) {
                num += (expr[i] - '0') * base;
                base *= 10;
                i--;
            }
            i++;  
            push(num);
        } 
        // If the character is an operator, pop two elements and perform the operation
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^') {
            int op1 = pop();
            int op2 = pop();
            int result;

            switch (expr[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': 
                    if (op2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    result = op1 / op2; 
                    break;
                case '^': result = pow(op1, op2); break;
                default:
                    printf("Invalid operator: %c\n", expr[i]);
                    exit(1);
            }

            push(result);
        }
    }

    return pop();
}

int main() {
    char prefixExpr[MAX];

    printf("Enter a prefix expression: ");
    fgets(prefixExpr, MAX, stdin); 

    int result = evaluatePrefix(prefixExpr);
    printf("Result of prefix expression evaluation: %d\n", result);

    return 0;
}
