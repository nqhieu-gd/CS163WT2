/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        root->right = invertTree(root->right);
        root->left = invertTree(root->left);
        TreeNode* sub = root->right;
        root->right = root->left;
        root->left = sub;
        return root;
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let h be the height of tree and n be the number of nodes

Space complexity: maximum recursion depth is h, no extra spaces is required
-> O(n) space

Time complexity: each node is visited once to check for its child nodes -> O(n) time
*/

/*
ALGORITHM EXPLAINATION

The invertTree function will change the root's right pointer to the left and the left pointer to the right, then it
do the same with the root's right and left pointers, swapping their left and right pointers, until it can not do that
anymore, the whole binary tree was inverted.
*/

/*
TEST CASE

CASE 1: Input: 10
		Output: 10

CSAE 2: Input: 2, 5, 1
		Output:       2
                     /  \
                    1    5

CASE 3: Input: 1, 2, 5, 0, 4, 3, 6
		Output:          1
                        / \
                       5   2
                      / \  / \
                     6   3 4  0

*/