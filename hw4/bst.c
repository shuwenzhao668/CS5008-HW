#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/* Function to create a new binary tree node */
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Function to free all nodes of a tree */
void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/* Function to insert a new node in the binary search tree */
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return newNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

/* Function to find the closest value to the target */
int closestValue(struct TreeNode* root, double target) {
    int closest = root->val;

    while (root != NULL) {
        /* Update closest value if current node is closer to the target */
        if (abs(root->val - target) < abs(closest - target)) {
            closest = root->val;
        }

        /* If target is less than current node value, go left */
        if (target < root->val) {
            root = root->left;
        }
        /* Otherwise, go right */
        else {
            root = root->right;
        }
    }

    return closest;
}

int main() {
    struct TreeNode* root = NULL;
    int n;
    printf("Enter the number of nodes in the binary search tree: ");
    scanf("%d", &n);

    printf("Enter the values of the nodes in the binary search tree:\n");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    double target;
    printf("Enter the target value: ");
    scanf("%lf", &target);

    int closest = closestValue(root, target);

    printf("Closest number = %d\n", closest);
    freeTree(root);

    return 0;
}