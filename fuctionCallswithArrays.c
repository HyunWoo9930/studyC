#include <stdio.h>
#define ARRAY_SIZE 5

void inputNumbers(int num[], int len);
double computeAverage(int num[], int len);

int main() {
    int numbers[ARRAY_SIZE];

    inputNumbers(numbers, ARRAY_SIZE);
    printf("average: %.3lf", computeAverage(numbers, ARRAY_SIZE));

    return 0;
}

void inputNumbers(int num[], int len) {
    printf("Input %d numbers\n", len);
    for(int i = 0; i < len; i++) {
        scanf("%d", &num[i]);
    }
}

double computeAverage(int num[], int len) {
    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += num[i];
    }
    return sum / (double)len;
}