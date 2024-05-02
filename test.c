#include <stdio.h>

int main() {
    char c = 'A';
    char *pc = &c;
    char **ppc = &pc;
    // if c의 주소 = 100000
    // if pc의 주소 = 123456
    // if pc의 주소 = 134567
    printf("%p %p\n", pc, ppc); // 100000 , 123456
    printf("%p %p\n", &pc, &ppc); // 123456 , 134567
    printf("%d ", sizeof(pc)); // 4
    printf("%d\n", sizeof(ppc)); // 4
    printf("%p %p\n", pc, pc+1); // 100000 , 100004
    printf("%p %p\n", &c, &c+1); // 100000 , 100004
    printf("%p %p\n", &pc, &pc +1); // 123456 , 123460
    return 0;
}