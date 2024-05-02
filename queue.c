#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 100

typedef enum {
    false, true
} bool;

typedef int Data;

typedef struct {
    Data item[MAX_COUNT];
    int front;
    int rear;
} Queue;

void InitQueue(Queue *pqueue) {
    pqueue->front = 0;
    pqueue->rear = 0;
}

bool IsFull(Queue *pqueue) {
    return pqueue->rear + 1 == pqueue->front;
}

bool IsEmpty(Queue *pqueue) {
    return pqueue->rear == pqueue->front;
}

void PrintQueue(Queue *pqueue) {
    for (int i = pqueue->front; i < pqueue->rear; i++) {
        printf("%d  ", pqueue->item[i]);
    }
    printf("\n");
}

void EnQueue(Queue *pqueue, Data item) {
    if (IsFull(pqueue)) {
        return;
    } else {
        pqueue->item[pqueue->rear] = item;
        pqueue->rear = (pqueue->rear + 1) % MAX_COUNT;
    }
}

void DeQueue(Queue *pqueue) {
    if (IsEmpty(pqueue)) {
        return;
    } else {
        pqueue->front = (pqueue->front + 1) % MAX_COUNT;
    }
}

Data Peek(Queue *pqueue) {
    if (IsEmpty(pqueue)) {
        return 0;
    } else {
        return pqueue->item[pqueue->front];
    }
}

bool IsCustomerArrived() {

}

void InsertCustomer(Queue *pqueue, int id, int clock) {

}

int RemoveCustomer(Queue *pqueue, int clock) {

}

void PrintStat(Queue *pqueue) {

}


int main() {
    int duration = 10, service_time = 0;
    int clock = 0, id = 1;
    Queue queue;
    InitQueue(&queue);

    while (clock < duration) {
        clock++;
        printf("Time : %d\n", clock);
        if (IsCustomerArrived()) {
            InsertCustomer(&queue, id, clock);
            id++;
        }
        if (service_time > 0) service_time--;
        else service_time = RemoveCustomer(&queue, clock);
    }

    PrintStat(&queue);


    return 0;
}
