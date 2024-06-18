#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP 100

typedef enum {
    false, true
} bool;
typedef char Data;

typedef struct {
    Data data;
    int priority;
} HNode;

typedef struct {
    HNode items[MAX_HEAP + 1];
    int num;
} Heap;

void InitHeap(Heap *pheap) {
    pheap->num = 0;
}

bool IsEmpty(Heap *pheap) {
    return pheap->num == 0;
}

bool IsFull(Heap *pheap) {
    return pheap->num == MAX_HEAP;
}

int getParent(int idx) {
    return idx / 2;
}

void Insert(Heap *pheap, Data data, int priority) {
    HNode newNode;
    int idx = pheap->num + 1;
    if (IsFull(pheap)) exit(1);

    while (idx > 1) {
        int parent = getParent(idx);
        if (priority > pheap->items[parent].priority) {
            pheap->items[idx] = pheap->items[parent];
            idx = parent;
        } else break;
    }

    newNode.data = data;
    newNode.priority = priority;
    pheap->items[idx] = newNode;
    pheap->num++;
}

int getLchild(int idx) {
    return 2 * idx;
}

int getRchild(int idx) {
    return 2 * idx + 1;
}

int GetHighPriorityChild(Heap *pheap, int idx) {
    if (getLchild(idx) > pheap->num) {
        return 0;
    } else if (getLchild(idx) == pheap->num) {
        return getLchild(idx);
    } else {
        int left = getLchild(idx), right = getRchild(idx);
        if (pheap->items[left].priority > pheap->items[right].priority)
            return left;
        else
            return right;
    }
}

Data delete(Heap *pheap) {
    /**
     * 일단 제일 큰 item 1을 빼오고,
     * 가장 낮은 수 last를 빼온다.
     * 그리고, getHighPriorityChild를 실행해서 parent의 child중에 left,right둘중 더 우선순위가 큰 아이를 반환해서 child에 넣어준다.
     * 그리고, last와 비교를 해서 child가 더 크면, parent랑 child를 바꿔줌.
     * 그리고 parent는 한단계 내려가서 child로 넣어줌.
     * 이 단계가 다 끝나면, parent에 last를 넣어주고 num을 1감소 시켜준다.
     **/

    Data max = pheap->items[1].data;
    HNode last = pheap->items[pheap->num];
    int parent = 1, child;

    while (child = GetHighPriorityChild(pheap, parent)) {
        if (last.priority < pheap->items[child].priority) {
            pheap->items[parent] = pheap->items[child];
            parent = child;
        } else break;
    }

    pheap->items[parent] = last;
    pheap->num--;

    return max;
}

typedef Heap PQueue;

void InitQueue(Heap *ppqueue) {
    InitHeap(ppqueue);
}

bool IsPQEmpty(Heap *ppqueue) {
    return IsEmpty(ppqueue);
}

bool IsPQFull(Heap *ppqueue) {
    return IsFull(ppqueue);
}

void Enqueue(PQueue *ppqueue, Data data, int priority) {
    Insert(ppqueue, data, priority);
}

Data Dequeue(PQueue *ppqueue) {
    return delete(ppqueue);
}

void HeapSort(Data a[], int n) {
    /**
     * 정렬되지 않은 데이터들을
     * insert후 delete로 최댓값부터 빼주어 정렬해줌.
     **/

    Heap heap;
    InitHeap(&heap);

    for(int i = 0; i < n; i++) {
        Insert(&heap, a[i], a[i]);
    }
    for(int i = n-1; i >= 0; i++) {
        a[i] = delete(&heap);
    }
}