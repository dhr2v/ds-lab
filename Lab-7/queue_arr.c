#include <stdio.h>
#define N 5

int queue[N];
int f = -1, r = -1;

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
    for (int i = f; i <= r; i++) {
        printf("%d\t", queue[i]);
    }
}

void Enqueue(int num) {
    if (f == -1 && r == -1) {
        f = r = 0;
        queue[r] = num;
        return;
    }
    if (r == N - 1) {
        printf("Queue is full.\n");
        return;
    }
    queue[++r] = num;
}

void Dequeue() {
    if (f == r) {
        printf("Queue is already empty.\n");
        return;
    }
    printf("Dequeued %d\n", queue[++f]);
}