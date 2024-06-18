#include <stddef.h>
#include <stdlib.h>

typedef int Key;

typedef enum {
    false, true
} bool;

typedef struct _BSTNODE {
    Key key;
    struct _BSTNODE *left_child;
    struct _BSTNODE *right_child;
} BSTNode;

bool verify(BSTNode *root, int min, int max) {
    if (root == NULL)
        return true;
    if (root->key < min || root->key > max) {
        return false;
    } else return verify(root->left_child, min, root->key) && verify(root->right_child, root->key, max);
}

BSTNode *Search(BSTNode *root, Key key) { // recursive version
    if (root == NULL || root->key == key) return root;
    else if (root->key < key) return Search(root->right_child, key);
    else if (root->key > key) return Search(root->left_child, key);
}

BSTNode *Search2(BSTNode *root, Key key) { // iterative version
    BSTNode *cur = root;
    while (cur != NULL) {
        if (cur->key == key) return cur;
        else if (cur->key < key) {
            cur = cur->right_child;
        } else if (cur->key > key) {
            cur = cur->left_child;
        }
    }
    return cur;
}

void CreateLeftSubTree(BSTNode *root, Key key) {
    BSTNode *newNode = (BSTNode *) malloc(sizeof(BSTNode));
    newNode->key = key;
    newNode->left_child = NULL;
    newNode->right_child = NULL;
    root->left_child = newNode;
}

void CreateRightSubTree(BSTNode *root, Key key) {
    BSTNode *newNode = (BSTNode *) malloc(sizeof(BSTNode));
    newNode->key = key;
    newNode->left_child = NULL;
    newNode->right_child = NULL;
    root->right_child = newNode;
}

BSTNode *Insert(BSTNode *root, Key key) { // recursive version
    if (root->key == key) exit(1);
    if (root->key < key) {
        if (root->left_child == NULL) {
            CreateLeftSubTree(root, key);
        } else Insert(root->left_child, key);
    } else {
        if (root->right_child == NULL) {
            CreateRightSubTree(root, key);
        } else Insert(root->right_child, key);
    }
}

void Insert2(BSTNode *root, Key key) { // iterative version
    BSTNode *cur = root;
    while (cur != NULL) {
        if (cur->key == key) exit(1);
        if (cur->key < key) {
            if (cur->right_child == NULL) {
                CreateRightSubTree(cur, key);
                break;
            } else {
                cur = cur->right_child;
            }
        } else {
            if (cur->left_child == NULL) {
                CreateLeftSubTree(cur, key);
                break;
            } else {
                cur = cur->left_child;
            }
        }
    }
}

BSTNode *remove(BSTNode *root, Key key) { // 개어려움
    if(root == NULL) return NULL;
    if(root->key > key) {
        root->left_child = remove(root->left_child, key); // 잘 모르겠음
    } else if(root->key < key) {
        root->right_child = remove(root->right_child, key); // 잘 모르겠음
    } else {
        BSTNode *cur = root;
        if(root->right_child == NULL && root->left_child == NULL) {
//            DestroyNode(cur);
            root = NULL;
        } else if(root->right_child == NULL || root->left_child == NULL) {
            if(root->left_child != NULL) {
                root = root->left_child;
//                DestroyNode(cur);
            } else {
                root = root->right_child;
//                DestroyNode(cur);
            }
        } else {
            cur = cur->right_child;
            while (cur->left_child != NULL) {
                cur = cur->left_child;
            }
            root->key = cur->key;
            root->right_child = remove(root->right_child, cur->key);
        }
    }
    return root;
}
