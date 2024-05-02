#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 1000

typedef enum {
    false, true
} bool;
/* do not modify */
////////////////////////////////
typedef int Data;
typedef struct _Node {
    Data item;
    struct _Node *next;
} Node;
////////////////////////////////

typedef struct {
    Node *head;
    Node *tail;
    int len;
} LinkedList;

typedef struct {
    Node *items[MAX_QUEUE];
    int front, rear;
} Queue;

/// Queue 함수 구현

void InitQueue(Queue *pqueue) {
    pqueue->front = pqueue->rear = 0;
}

bool IsQueueEmpty(Queue *pqueue) {
    return pqueue->front == pqueue->rear;
}

bool IsFull(Queue *pqueue) {
    return pqueue->front
           == (pqueue->rear + 1) % MAX_QUEUE;
}

Node *Peek(Queue *pqueue) {
    if (IsQueueEmpty(pqueue))
        exit(1);
    return pqueue->items[pqueue->front];
}

void EnQueue(Queue *pqueue, Node *data) {
    if (IsFull(pqueue))
        exit(1);
    pqueue->items[pqueue->rear] = data;
    pqueue->rear = (pqueue->rear + 1) % MAX_QUEUE;
}

void DeQueue(Queue *pqueue) {
    if (IsQueueEmpty(pqueue))
        exit(1);
    pqueue->front = pqueue->front + 1;
}

/// LinkedList 함수 구현

void InitList(LinkedList *plist) {
    plist->head = NULL;
    plist->tail = NULL;
    plist->len = 0;
}

void InsertFirst(LinkedList *plist, Data data) {
    plist->len = plist->len + 1;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->item = data;
    newNode->next = NULL;
    if (plist->head == NULL)
        plist->head = newNode;
    if (plist->tail == NULL)
        plist->tail = newNode;
}

void InsertLast(LinkedList *plist, Data data, int pos) {
    plist->len = plist->len + 1;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->item = data;
    newNode->next = NULL;
    plist->tail = newNode;
    Node *cur;
    cur = plist->head;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }
    cur->next = newNode;
}

bool IsListEmpty(LinkedList *plist) {
    return plist->len == 0;
}

Node *PeekFirstNode(LinkedList *plist) {
    Node *tmp = plist->head;
    plist->len--;
    plist->head = tmp->next;
    return tmp;
}

Node *PeekLastNode(LinkedList *plist) {
    Node *tmp = plist->tail;
    plist->len--;
    Node *cur = plist->head;
    for (int i = 0; i < plist->len - 1; i++) {
        cur = cur->next;
    }
    cur->next = NULL;
    plist->tail = cur;
    return tmp;
}

void PrintList(LinkedList *plist) {
    Node *current = plist->head;
    while (current != NULL) {
        printf("%d ", current->item);
        current = current->next;
    }
    printf("\n");
}

int main() {
    /* do not modify */
    ////////////////////////////////
    int input[1000];
    int len = 0, i = 0;

    scanf("%d", &len);
    for (i = 0; i < len; ++i) {
        scanf("%d", &input[i]);
    }
    ////////////////////////////////

    // good luck!

    LinkedList plist;
    InitList(&plist);

    InsertFirst(&plist, input[0]);
    for (i = 1; i < len; i++) {
        InsertLast(&plist, input[i], i);
    }

    Queue queue;
    InitQueue(&queue);

    for(int k = 0; k < len/2; k++) {
        Node *node = PeekFirstNode(&plist);
        EnQueue(&queue, node);
        node = PeekLastNode(&plist);
        EnQueue(&queue, node);
    }
    if(!IsListEmpty(&plist)) {
        Node *node = PeekFirstNode(&plist);
        EnQueue(&queue, node);
    }

    LinkedList resultList;
    InitList(&resultList);
    InsertFirst(&resultList, Peek(&queue)->item);
    DeQueue(&queue);

    i = 1;
    while(!IsQueueEmpty(&queue)) {
        InsertLast(&resultList, Peek(&queue)->item, i++);
        DeQueue(&queue);
    }

    PrintList(&resultList);

    return 0;
}
