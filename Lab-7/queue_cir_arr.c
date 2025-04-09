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
    printf("\n");
}

void Enqueue(int num) {
    if (f == (r + 1) % N || (f == 0 && r == N - 1)) {
        printf("Queue is full.\n");
        return;
    }
    if (f == -1) {
        f = 0;
        r = (r + 1) % N;
        queue[r] = num;
        return;
    }
    r = (r + 1) % N;
    queue[r] = num;
}

void Dequeue() {
    if (f == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Dequeued %d\n", queue[f]);
    f = (f + 1) % N;
}