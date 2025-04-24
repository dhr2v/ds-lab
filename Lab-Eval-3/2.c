#include <stdio.h>

#define QUEUE_CAPACITY 10000
#define STR_SIZE 100

void copyString(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int stringLength(const char *s) {
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

char queue[QUEUE_CAPACITY][STR_SIZE];
int front = 0, rear = 0;

void enqueue(const char *s) {
    if (rear >= QUEUE_CAPACITY) {
        printf("Queue overflow!\n");
        return;
    }
    copyString(queue[rear], s);
    rear++;
}

char *dequeue() {
    if (front >= rear)
        return NULL;
    return queue[front++];
}

void generateBinaryNumbers(int n) {
    enqueue("1");

    for (int i = 1; i <= n; i++) {
        char *s1 = dequeue();
        if (s1 == NULL)
            break;
        printf("%s\n", s1);

        char s0[STR_SIZE];
        int len = stringLength(s1);
        for (int j = 0; j < len; j++)
            s0[j] = s1[j];
        s0[len] = '0';
        s0[len + 1] = '\0';
        enqueue(s0);

        char s1_new[STR_SIZE];
        for (int j = 0; j < len; j++)
            s1_new[j] = s1[j];
        s1_new[len] = '1';
        s1_new[len + 1] = '\0';
        enqueue(s1_new);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    generateBinaryNumbers(n);
    return 0;
}