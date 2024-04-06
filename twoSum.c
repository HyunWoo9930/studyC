#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

void solution(int *num, int size, int target, int *result) {
    for (int i = 0; i < size - 1; i++) {
        if(num[i] > target) {
            break;
        }
        for (int j = 1; j < size; j++) {
            if(num[j] > target) {
                break;
            }
            if (num[i] + num[j] == target) {
                result[0] = i;
                result[1] = j;
                break;
            }
        }
    }

    return;
}

int main() {
    int len = 0, i = 0, target = 0;
    int num[105] = {0,};
    int result[2] = {0,};

    // 배열의 원소 개수와 target 입력 받음
    scanf("%d %d", &len, &target);
    if (len < 0 || len > 105) {
        printf("error!\n");
    }

    // 문제에 주어진 정수 배열 입력
    for (i = 0; i < len; i++) {
        scanf("%d", &num[i]);
    }


    solution(num, len, target, result);
    printf("%d %d \n", result[0], result[1]);

    return 0;
}