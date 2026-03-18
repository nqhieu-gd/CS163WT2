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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return nodeComp(root->left, root->right);
    }

    bool nodeComp(TreeNode*& root1, TreeNode*& root2) {
        if (root1 == nullptr) return (root2 == nullptr);
        if (root2 == nullptr) return (root1 == nullptr);
        if (root1->val != root2->val) return false;
        return nodeComp(root1->left, root2->right) && nodeComp(root1->right, root2->left);
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

let n be the number of node, h be the height of the shorter subtree between root->left and root->right

Space complexity:
- nodeComp: maximum recursion depth: O(h) -> skewed tree: O(n), balanced tree: O(log(n))
- no extra spaces required
=> O(h) space

Time complexity: nodeComp: each node is visited at most once -> O(n)



ALGORITHM EXPLAINATION

The root's mirror image is itself so we don't need to consider the root if it is not an empty tree.

We only need to consider its left and right subtree, what we will do is just casually traverse both subtree at a mirrored step,
meaning when we go left from the right subtree, we go right from the left subtree and vice versa. At each step, we compare the
node's value, if it is the same to the very end, we have 2 mirrored subtree, hence the tree is symmetric. Otherwise, if at a
certain step where they differ (one being a null pointer, the other isn't or their stored value doesn't match) the tree is not
symmetric.



TEST CASE

CASE 1: Input: (empty tree)
		Output: true

CASE 2: Input: 1 2 2 5 4 3 5 (balanced tree with only one error node)
		Output: false

CASE 3: Input: 1 2 null 3 4 null null 5 6 7 8 null null null null (empty right subtree)
		Output: false
*/