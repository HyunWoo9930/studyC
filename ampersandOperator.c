#include <stdio.h>

int main() {
    char c = 'A';
    char* pc = &c; // pc는 c의 주소 포인터

    printf("%c %p\n", c, pc);
    printf("%p %p\n", &c, &pc);
    printf("%d %d\n", sizeof(c), sizeof(pc));
// A 0x16dde364b
// 0x16dde364b 0x16dde3640
// 1 8
    return 0;
}