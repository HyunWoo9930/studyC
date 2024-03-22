#include <stdio.h>
#include <stdlib.h>

int main() {
    int **m = malloc(sizeof(int *) * 3);

    for(int i = 0; i < 3; i++) {
        m[i] = malloc(sizeof(int) * 4);
    }

    m[0][0] = 1;
    m[1][0] = 5;
    m[2][3] = 2;

    printf("%d\n", m[0][0]);
    printf("%d\n", m[1][0]);
    printf("%d\n", m[2][3]);
    printf("%d\n", m[2][2]);

    for(int i = 0; i < 3; i++) {
        free(m[i]);
    }
    free(m);

    return 0;
}