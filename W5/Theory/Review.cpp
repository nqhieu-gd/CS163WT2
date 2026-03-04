#include <iostream>

struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
};

bool isBST(TreeNode* root) {
    return checkBST(root, INT_MAX, INT_MIN);
}

bool checkBST(TreeNode* root, int max, int min) {
    if (!root) return true;
    if (root->val > max || root->val < min) return false;
    if (root->left && root->left->val > root->val || root->right && root->right->val < root->val) return false;
    return (checkBST(root->left, root->val, min) && checkBST(root->right, max, root->val));
}