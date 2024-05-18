#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[200] = { 0, };
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* CreateBinaryTree(int cnt) {
    // 배열을 노드로 생성
    TreeNode* node[200] = { NULL };
    for (int i = 0; i < cnt; i++) {
        if (arr[i] == -1)
            node[i] = NULL; // -1은 NULL값을 할당
        else
            node[i] = createNode(arr[i]);
    }

    // NULL을 세는 변수로 인덱스 값 조절
    int ncnt = 0;
    for (int i = 0; i < cnt; i++) {
        if (node[i] == NULL) {
            ncnt++;
        } else {
            int LeftIndex = (i - ncnt) * 2 + 1;
            int RightIndex = (i - ncnt) * 2 + 2;

            if (LeftIndex < cnt && node[LeftIndex] != NULL) {
                node[i]->left = node[LeftIndex];
            }

            if (RightIndex < cnt && node[RightIndex] != NULL) {
                node[i]->right = node[RightIndex];
            }
        }
    }
    return node[0];
}

TreeNode* removeSubtree(TreeNode *root) {
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

void printTree(TreeNode *root) {
    if (root == NULL) {
        printf("-1 ");
        return;
    }

    // 배열을 이용한 큐 구현
    TreeNode* queue[200];
    int front = 0, rear = 0;

    // 루트 노드를 큐에 추가
    queue[rear++] = root;

    while (front < rear) {
        TreeNode* current = queue[front++];

        if (current != NULL) {
            printf("%d ", current->val);
            if(current->right == NULL && current->left == NULL) {
                return;
            }
                queue[rear++] = current->left;
                queue[rear++] = current->right;
        } else {
            printf("-1 ");
        }
    }
}

int main() {
    // DO NOT MODIFY //
    int i = 0, cnt = 0;
    char str[400] = { 0, };
    char* s;
    scanf("%[^\n]", str);
    for (i = 2; i > 1; cnt += i > 0) {
        i = sscanf(str, "%d%*[ ]%[^\n]", &arr[cnt], str);
    }
    // 위 코드를 수행하면 arr 에는 각 원소에 입력으로 받은 노드들이 저장됩니다.
    ///////////////////

    TreeNode* root = NULL;
    root = CreateBinaryTree(cnt);
    root = removeSubtree(root);
    // Print the tree
    printTree(root);

    return 0;
}