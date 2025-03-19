// Implementation of stack using array.

#include <stdio.h>
#include <stdlib.h>

#define N 5

int stack[N];
int top = -1;

/* FUNCTION DECLARATIONS */
void Push(int num);
void Pop();
void Display();

int main() {
    for (int i = 1; i <= 5; i++) Push(2 * i);

    Display();

    for (int i = 1; i <= 5; i++) if (i % 2 == 0) Pop();
    
    Display();

    return 0;
}

/* FUNCTION DEFINITIONS */
void Display() {
    int i = top;
    for (; i >= 0; i--) printf("| %2d |\n", stack[i]);
}

void Push(int num) {
    if (top == N - 1) { printf("Stack Overflow!\n"); return; }
    stack[++top] = num;
}

void Pop() {
    if (top == -1) { printf("Stack Underflow!\n"); return; }
    printf("Popped: %d\n", stack[top]);
    top--;
}

