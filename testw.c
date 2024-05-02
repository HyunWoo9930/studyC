#include <stdio.h>

int main() {
    char arr1[3] = {'I', 'D', 'J'};
    int arr2[3] = {5,1,1};
    char *ptr1 = arr1;
    int *ptr2 = &arr2[1];
    char **pptr1 = &ptr1;

    printf("%p %p\n", ptr1, ptr2);
    printf("%c %d\n", *ptr1+3, *(ptr2+1));
    ptr1++;
    printf("%p\n", ptr1);

}