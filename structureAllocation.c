#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    int score[3];
    int total;
} STUDENT;

int main() {
    int n;
    scanf("%d", &n);

    STUDENT *s = malloc(sizeof(STUDENT) * n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i].name);

        s[i].total = 0;
        for (int j = 0; j < 3; j++) {
            scanf("%d", &s[i].score[j]);
            s[i].total += s[i].score[j];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", s[i].total);
    }
    free(s);
    // malloc으로 동적 할당을 하면
    // 꼭 free를 해줘야함.


    return 0;
}