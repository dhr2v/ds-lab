#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *f = NULL, *r = NULL;

void Display();
void Enqueue(int num);
void Dequeue();

int main() {
    for (int i = 1; i <= 5; i++) {
        Enqueue(i * 2);
    }

    Dequeue();
    Dequeue();

    Display();
    return 0;
}

void Display() {
    struct Node *temp = f;
    if (f == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Enqueue(int num) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;
    if (f == NULL) {
        f = r = newNode;
    } else {
        r->next = newNode;
        r = newNode;
    }
    printf("Enqueued: %d\n", num);
}

void Dequeue() {
    if (f == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    struct Node *temp = f;
    printf("Dequeued: %d\n", temp->data);
    f = f->next;
    free(temp);
    if (f == NULL) {
        r = NULL;
    }
}