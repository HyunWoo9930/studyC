#include <stdio.h>

typedef struct {
    int numerator;
    int demnominator;
} FRACTION;

int main() {
    FRACTION num1 = {2,3};
    FRACTION num2 = {1,2};
    FRACTION num3;

    num3.numerator = num1.numerator * num2.demnominator + num2.numerator * num1.demnominator;
    num3.demnominator = num1.demnominator * num2.demnominator;

    printf("%d/%d", num3.numerator, num3.demnominator);



    return 0;
}