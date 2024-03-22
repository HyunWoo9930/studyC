#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size1, size2;

    scanf("%d %d", &size1, &size2);

    int **m = malloc(sizeof(int *) * size1);

    for(int i = 0; i < size1; i++) {
        m[i] = malloc(sizeof(int) * size2);
    }

    for(int i = 0; i < size1; i++) {
        for(int j = 0; j < size2; j++) {
            m[i][j] = i+j;
        }
    }

    for(int i = 0; i < size1; i++) {
        for(int j = 0; j < size2; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }



    for(int i = 0; i < size1; i++) {
        free(m[i]);
    }

    free(m);

    return 0;
}