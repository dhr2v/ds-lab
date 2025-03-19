#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

/* FUNCTION DECLARATIONS */
void Push(int num);
void Pop();
void Display();

struct Node* top = NULL;

int main() {
    for (int i = 1; i <= 10; i++) Push(2 * i);

    Display();

    Pop();
    Pop();

    printf("Popped twice.\n");

    Display();

    return 0;
}

/* FUNCTION DEFINITIONS */

void Display() {
    struct Node* p = top;
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    while (p != NULL) {
        printf("| %2d |\n", p->data);
        p = p->next;
    }
}

void Push(int num) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));

    p->data = num;
    p->next = top;  
    p->prev = NULL; 

    if (top != NULL) {
        top->prev = p; 
    }

    top = p;
}

void Pop() {
    if (top == NULL) {
        printf("Stack is empty. Nothing to pop.\n");
        return;
    }

    struct Node* temp = top;
    top = top->next;  

    if (top != NULL) {
        top->prev = NULL; 
    }

    free(temp); 
}
