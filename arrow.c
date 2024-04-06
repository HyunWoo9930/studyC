#include <stdio.h>

typedef struct {
    char name[10];
    int scores[3];
} STUDENT;

int main() {
    STUDENT s1 = {"HyunWoo", 80, 70, 90};
    STUDENT* s2 = &s1;

    printf("%s\n", s1.name);
    for(int i = 0; i < 3; i++) {
        printf("%d\n", s2->scores[i]);
        /* arrow 함수
         * s1이 STUDENT 타입의 구조체 변수일 때,
         * s1.name이나 s1.scores[0]과 같이 점 연산자를 사용하여 s1의 멤버에 직접 접근합니다.
         * 반대로, s2가 STUDENT 타입의 구조체를 가리키는 포인터일 경우,
         * s2->name이나 s2->scores[0]과 같이 화살표 연산자를 사용하여 간접적으로 멤버에 접근합니다.
         * */
    }


    return 0;
}