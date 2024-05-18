#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[200] = {0,};

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *removeSubtree(TreeNode *root) {
    if (root == NULL) {
        return NULL;
    }

    root->left = removeSubtree(root->left);
    root->right = removeSubtree(root->right);

    if (root->val == 0 && ((root->left == NULL) && root->right == NULL)) {
        free(root);
        return NULL;
    }

    return root;
}
TreeNode *createNode(int val) {
    TreeNode *newNode = (TreeNode *) malloc(sizeof(TreeNode));
    newNode->val = val;
    // 왼쪽과 오른쪽 자식 노드를 초기화하지 않습니다.
    return newNode;
}

TreeNode *solution(int size) {
    if (arr[0] == -1)
        return NULL;

    TreeNode *queue[size];
    int front = 0, rear = 0;

    TreeNode *root = createNode(arr[0]);
    queue[rear++] = root;

    int index = 1;
    while (index < size) {
        TreeNode *current = queue[front++];

        if (index < size && arr[index] != -1) {
            current->left = createNode(arr[index]);
            queue[rear++] = current->left;
        }
        index++;

        if (index < size && arr[index] != -1) {
            current->right = createNode(arr[index]);
            queue[rear++] = current->right;
        }
        index++;
    }

    return root;
}


void printNode(TreeNode *node) {
    if (node == NULL) {
        printf("-1 ");
        return;
    }

    printf("%d ", node->val);
    if(node->left == NULL && node->right == NULL) {
        return;
    }
    printNode(node->left);
    printNode(node->right);
}

int main() {

    // DO NOT MODIFY //
    int i=0, cnt=0;
    char str[400] = {0,};
    char *s;
    scanf("%[^\n]", str);
    for (i = 2; i > 1; cnt += i > 0) {
        i = sscanf(str, "%d%*[ ]%[^\n]", &arr[cnt], str);
    }
    // 위 코드를 수행하면 arr 에는 각 원소에 입력으로 받은 노드들이 저장됩니다.
    ///////////////////

    // print tree as array

    TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
    root->val = arr[0];
    root->left = NULL;
    root->right = NULL;

    root = solution(cnt);
    printNode(root);
    printf("\n");
    root = removeSubtree(root);
    printNode(root);

    return 0;
}
