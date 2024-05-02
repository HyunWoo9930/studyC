#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false, true
} bool;

typedef int Data;

typedef struct _Node {
    Data item;
    struct _Node *next;
} Node;

typedef struct {
    Node *tail;
    int len;
} CircularList;

void InsertInitItem(CircularList *plist, Data data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->next = newNode;
    newNode->item = data;

    plist->len++;
    plist->tail = newNode;
}

void InsertFirst(CircularList *plist, Data data) {
    Node *cur = plist->tail->next;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->item = data;
    newNode->next = cur;
    plist->tail->next = newNode;
    plist->len++;
}

void InsertLast(CircularList *plist, Data data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->item = data;
    newNode->next = plist->tail->next;

    plist->tail->next = newNode;
    plist->tail = newNode;
    plist->len++;
}

void InsertMiddle(CircularList *plist, Data data, int pos) {
    Node *cur;
    cur = plist->tail;
    for (int i = 0; i < pos; i++) {
        cur = cur->next;
    }
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->item = data;
    newNode->next = cur->next;
    cur->next = newNode;
    plist->len++;
}

void RemoveInitItem(CircularList *plist) {
    free(plist->tail);
    plist->len--;
    plist->tail = NULL;
}

void RemoveFirst(CircularList *plist) {
    plist->tail->next = plist->tail->next->next;
    free(plist->tail->next);
    plist->len--;
}

void RemoveLast(CircularList *plist) {
    Node *cur = plist->tail;
    for (int i = 0; i < plist->len -1; i++) {
        cur = cur->next;
    }
    Node *tmp = cur->next;
    cur->next = tmp->next;

    free(tmp);
    plist->tail = cur;
    plist->len--;
}

int main() {

}