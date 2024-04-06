//
// Created by 오현우 on 4/6/24.
//
#include <stdio.h>

void Swap(int *list, int min, int i) {
    int temp = list[i];
    list[i] = list[min];
    list[min] = temp;
}

void SelectionSort(int *list, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (list[min] > list[j]) {
                min = j;
            }
        }

        Swap(list, min, i);
    }
}

int main() {
    int list[5];

    list[0] = 6;
    list[1] = 5;
    list[2] = 3;
    list[3] = 4;
    list[4] = 2;

    SelectionSort(&list, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", list[i]);
    }
}