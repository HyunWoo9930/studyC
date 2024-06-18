#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 3000

int arr[MAX_SIZE] = {0};

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createTreeNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* createTree(int* arr, int n) {
    if (n == 0) return NULL;

    TreeNode** nodes = (TreeNode**)malloc(n * sizeof(TreeNode*));
    for (int i = 0; i < n; ++i) {
        if (arr[i] != -1) {
            nodes[i] = createTreeNode(arr[i]);
        } else {
            nodes[i] = NULL;
        }
    }

    for (int i = 0, j = 1; j < n; ++i) {
        if (nodes[i] != NULL) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }

    TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

typedef struct QueueNode {
    TreeNode* node;
    unsigned long long position;
} QueueNode;

typedef struct Queue {
    QueueNode* data;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (QueueNode*)malloc(size * sizeof(QueueNode));
    q->front = 0;
    q->rear = 0;
    q->size = size;
    return q;
}

void enqueue(Queue* q, TreeNode* node, unsigned long long position) {
    q->data[q->rear].node = node;
    q->data[q->rear].position = position;
    q->rear = (q->rear + 1) % q->size;
}

QueueNode dequeue(Queue* q) {
    QueueNode node = q->data[q->front];
    q->front = (q->front + 1) % q->size;
    return node;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

int solution(TreeNode* root) {
    if (!root) return 0;

    Queue* q = createQueue(MAX_SIZE);
    enqueue(q, root, 0);
    int maxWidth = 0;

    while (!isEmpty(q)) {
        int size = (q->rear - q->front + q->size) % q->size;
        unsigned long long minPos = ULLONG_MAX, maxPos = 0;

        for (int i = 0; i < size; ++i) {
            QueueNode current = dequeue(q);
            TreeNode* node = current.node;
            unsigned long long position = current.position;

            if (node->left) enqueue(q, node->left, 2 * position + 1);
            if (node->right) enqueue(q, node->right, 2 * position + 2);

            if (position < minPos) minPos = position;
            if (position > maxPos) maxPos = position;
        }

        int width = maxPos - minPos + 1;
        if (width > maxWidth) maxWidth = width;
    }

    free(q->data);
    free(q);
    return maxWidth;
}

int main() {
    int i = 0, cnt = 0, answer = 0;
    char str[6000] = {0};
    char *s;
    scanf("%[^\n]", str);
    for (i = 2; i > 1; cnt += i > 0) {
        i = sscanf(str, "%d%*[ ]%[^\n]", &arr[cnt], str);
    }
    TreeNode* root = createTree(arr, cnt);
    answer = solution(root);
    printf("%d\n", answer);
    return 0;
}
