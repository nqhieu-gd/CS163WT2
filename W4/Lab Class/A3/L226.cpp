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

Let n be the height of tree

Space complexity: maximum recursion depth is n, no extra spaces is required
-> O(n) space

Time complexity: maximum recursion depth is n -> O(n) time
*/

/*
ALGORITHM EXPLAINATION

The insert function will find the location that we can add "data" in, such position must be lower than all of its right-sided
nodes and higher than all of its left-sided nodes. It means, if "data" is higher than the current node's data, insert it to
the tree to the right and vice versa, the recursion will stop until a null node is reached, that node will suffice the conditions
and such is the valid position for "data".
*/

/*
TEST CASE

CASE 1: Input: 10
		Output: 10

CSAE 2: Input: 2, 5, 1
		Output:       2
                       \
                        5
                       /
                      1

CASE 3: Input: 2, 5, 0, 4, 3
		Output:          2
                        / \
                       0   5
                          /
                         4
                        /
                       3

*/