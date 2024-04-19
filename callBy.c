#include <stdio.h>

void swap1(int a, int b);
void swap2(int *a, int *b);

void swap1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 5, b = 7;
    swap1(a,b);
    printf("%d %d\n", a,b);
    swap2(&a, &b);
    printf("%d %d\n", a,b);

    return 0;
}