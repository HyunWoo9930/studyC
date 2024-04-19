#include <stdio.h>

void printArray(int *a, int len);

void printArray(int *a, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\n", *(a + i));
        printf("%d\n", a[i]);
    }
}

int main() {
    int a[6] = {1, 2, 3, 4, 5, 6};
    printArray(a, 6);
    return 0;

}