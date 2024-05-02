#include <stdio.h>

#define MAX_LIST 100

typedef enum {
    true, false
} bool;

typedef int Data;

typedef struct {
    Data items[MAX_LIST];
    int len;
} ArrayList;

void InitList(ArrayList *plist) {
    plist->len = 0;
}

bool IsEmpty(ArrayList *plist) {
    return plist->len == 0;
}

bool IsFull(ArrayList *plist) {
    return plist->len == MAX_LIST;
}

void InsertMiddle(ArrayList *plist, int pos, Data item) {
    if (IsFull(plist)) return;
    else {
        for (int i = plist->len - 1; i >= pos; i--) {
            plist->items[i + 1] = plist->items[i];
        }
        plist->items[pos] = item;
        plist->len++;
    }
}

void RemoveMiddle(ArrayList *plist, int pos) {
    if (IsEmpty(plist)) return;
    else {
        for (int i = pos; i < plist->len; i++) {
            plist->items[i] = plist->items[i + 1];
        }
        plist->len--;
    }
}

Data ReadItem(ArrayList *plist, int pos) {
    return plist->items[pos];
}

void PrintList(ArrayList *plist) {
    for(int i = 0; i < plist->len; i++) {
        printf("%d\n", plist->items[i]);
    }
}

int main() {
    ArrayList list;
    InitList(&list);
    InsertMiddle(&list, 0, 1);
    InsertMiddle(&list, 1, 2);
    InsertMiddle(&list, 1, 3);
    InsertMiddle(&list, 2, 4);
    RemoveMiddle(&list, 1);
    PrintList(&list);
    // List의 문제점 : 고정된 범위, 시간이 오래걸림 - O(n)
}