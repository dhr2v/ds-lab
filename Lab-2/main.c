// [x] Compute simple moving average
// [x] Compute exponential moving average

#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

void simple_moving_avg(int* arr, int size, int window_size);
float exp_moving_avg(float previous_ema, float current_value, float alpha);

int main() {
    int a[7] = {10, 20, 10, 30, 40, 35, 50};
    int n = sizeof(a) / sizeof(a[0]);

    int window_size = 2;
    
    // Simple Moving Average
    printf("SMA values:\n");
    simple_moving_avg(a, n, window_size);
    printf("\n");

    // Exponential Moving Average 
    float alpha = 2 / (1 + (float)window_size);

    printf("EMA values:\n");

    float ema = (float)a[0];
    printf("%.1f ", ema); 
    for (int i = 1; i < n; i++) {
        ema = exp_moving_avg(ema, (float)a[i], alpha);
        printf("%.1f ", ema);
    }

    return 0;
}

void simple_moving_avg(int* arr, int size, int window_size) {
    int sum = 0;
    float avg = 0;
    for (int i = 0; i < window_size - 1; i++) {
        printf("%.1f ", (float)arr[i]);
    }
    for (int i = 0; i <= size - window_size; i++) {
        sum = 0;
        for (int j = i; j < i + window_size; j++) {
            sum += arr[j];
        }
        avg = sum / window_size;
        printf("%.1f ", avg);
    }
}

float exp_moving_avg(float previous_ema, float current_value, float alpha) {
    return (alpha * current_value) + ((1 - alpha) * previous_ema);
}
