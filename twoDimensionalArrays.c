#include <stdio.h>

int main() {
    int row, col, matrix[6][6];

    for(row = 0; row < 6; row++) {
        for(col = 0; col < 6; col++) {
            if(row > col) {
                matrix[row][col] = -1;
            } else if (col > row) {
                matrix[row][col] = 1;
            } else {
                matrix[row][col] = 0;
            }
        }
    }

    return 0;
}
