#include <stdio.h>

#define MAX_STACK 100

typedef enum {
    false, true
} bool;

typedef int Data;

typedef struct {
    Data item[MAX_STACK];
    int top;
} Stack;

void InitStack(Stack *pstack) {
    pstack->top = -1;
}

bool IsEmpty(Stack *pstack) {
    return pstack->top == -1;
}

bool IsFull(Stack *pstack) {
    return pstack->top == MAX_STACK - 1;
}

void Push(Stack *pstack, Data item) {
    if (IsFull(pstack)) {
        return;
    } else {
        pstack->top++;
        pstack->item[pstack->top] = item;
    }
}

void Pop(Stack *pstack) {
    if (IsEmpty(pstack)) {
        return;
    } else {
        pstack->top--;
    }
}

Data Peek(Stack *pstack) {
    if (IsEmpty(pstack)) {
        return -1;
    } else {
        return pstack->item[pstack->top];
    }
}

void PrintStack(Stack *pstack) {
    for (int i = 0; i <= pstack->top; i++) {
        printf("%d\n", pstack->item[i]);
    }
}

bool isOperator(char item) {
    if (item == '*' || item == '+' || item == '/' || item == '-') return true;
    else return false;
}

int calculate(int a, int b, char operator) {
    switch (operator) {
        case '+':
            return b + a;
        case '-':
            return b - a;
        case '*':
            return b * a;
        case '/':
            return b / a;
    }
}

void CalculatePostfix(char *list, int len) {
    Stack stack;
    InitStack(&stack);
    for (int i = 0; i < len; i++) {
        if (!isOperator(list[i])) {
            Push(&stack, list[i]);
        } else {
            int a = Peek(&stack);
            Pop(&stack);
            int v;
            int b = Peek(&stack);
            Pop(&stack);
            int result = calculate(a, b, list[i]);
            Push(&stack, result);
        }
    }
    printf("%d\n", Peek(&stack));
}

bool isBigger(char a, char b) {
    if (a == '*' || a == '/') {
        if (b == '+' || b == '-') {
            return true;
        }
    }
    return false;
}

void PrintPrefix(char *list, int len) {
    Stack stack;
    InitStack(&stack);

    for (int i = 0; i < len; i++) {
        if (!isOperator(list[i])) {
            printf("%d ", list[i]);
        } else {
            if (IsEmpty(&stack)) {
                Push(&stack, list[i]);
            } else if (isBigger(Peek(&stack), list[i])) { // 원래 stack 안에 있는 연산이 더 높으면, 그 연산 Pop 후 푸시
                printf("%d ", Peek(&stack));
                Pop(&stack);
                Push(&stack, list[i]);
            } else {
                Push(&stack, list[i]);
            }
        }
    }
    while (!IsEmpty(&stack)) {
        printf("%d ", Peek(&stack));
        Pop(&stack);
    }
    printf("\n");
}

int main() {
    char prefix[5] = {2, 3, 4, '*', '+',};
    CalculatePostfix(&prefix, 5);
    char rhkfgh[5] = {2, '+', 3, '*', 4,};
    PrintPrefix(&rhkfgh, 5);

    return 0;
}