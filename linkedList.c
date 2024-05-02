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
    int len;
    Node *head;
} LinkedList;

void InitList(LinkedList *plist) {
    plist->head = NULL;
    plist->len = 0;
}

bool IsEmpty(LinkedList *plist) {
    return plist->len == 0;
}

void InsertFirst(LinkedList *plist, Data item) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->next = NULL;
    if (plist->head == NULL) {
        plist->head = newNode;
    } else {
        Node *cur = plist->head;
        plist->head = newNode;
        newNode->next = cur;
    }
    plist->len++;
}

void InsertMiddle(LinkedList *plist, int pos, Data item) {
    Node *cur = plist->head;
    for (int i = 0; i < pos; i++) {
        cur = cur->next;
    }
    Node *newNode = malloc((sizeof(Node)));
    newNode->item = item;
    newNode->next = cur->next;
    cur->next = newNode;
    plist->len++;
}

void RemoveMiddle(LinkedList *plist, int pos) {
    Node *cur;
    cur = plist->head;
    for (int i = 0; i < pos; i++) {
        cur = cur->next;
    }
    Node *tmp = cur->next;
    cur->next = tmp->next;
    free(tmp);
    plist->len--;
}

void ReadItem(LinkedList *plist, int pos) {
    Node *cur;
    cur = plist->head->next;
    for(int i = 0; i < pos; i++) {
        cur = cur->next;
    }
    printf("%d", cur->item);
}

void PrintList(LinkedList *plist) {
    Node *cur = plist->head;
    for(int i = 0; i < plist->len; i++) {
        printf("%d\n", cur->item);
        cur = cur->next;
    }
}

LinkedList *Concatenate(LinkedList *plist1, LinkedList *plist2) {
    if(plist1->head == NULL) return plist2;
    else if(plist2->head == NULL) return plist1;
    else {
        Node* cur = plist1->head->next;
        while(cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = plist2->head->next;
        free(plist2->head);
        return plist1;
    }
}

void Reverse(LinkedList *plist) {
    Node *cur,*prev;
    prev = plist->head->next;
    cur = prev->next;
    for(int i = 0; i < plist->len; i++) {
        cur->next = prev;
        prev->next = NULL;
        prev = cur;
        cur = cur->next;
    }
}

int main() {

}