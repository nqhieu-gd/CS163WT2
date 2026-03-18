/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * typedef struct TreeNode treenode;
 * 
 * treenode* treenode_new(int val) {
 *     treenode* node = (treenode *) malloc(sizeof(treenode));
 *     node->val = val;
 *     node->left = NULL;
 *     node->right = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Root pointer of the tree 
 * @input B : Root pointer of the tree 
 * 
 * @Output Integer
 */
int isSameTree(treenode* A, treenode* B) {
    if (A == NULL) return (B == NULL);
    if (B == NULL) return (A == NULL);
    if (A->val != B->val) return 0;
    return isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

let n be the number of node, h be the height of the shorter subtree between root->left and root->right

Space complexity:
- isSameTree: maximum recursion depth: O(h) -> skewed tree: O(n), balanced tree: O(log(n))
- no extra spaces required
=> O(h) space

Time complexity: each node is visited at most once -> O(n)
*/

/*
ALGORITHM EXPLAINATION

2 trees are the same if they are either empty or give the same answer when we traverse them.

So firstly, if they are not empty, we traverse them in the exact same path, if they are the same tree, each time we visit a new node,
we get the same result when we compare the current node's value between 2 trees. And if at one node that isn't true, it means they
are not the same tree.
*/

/*
TEST CASE

CASE 1: Input: 1 2 3 4 5 null null 6
               
               (regular tree vs empty tree)
		Output: 0 (false)

CASE 2: Input: 
               
               (2 empty trees)
		Output: 1 (true)

CASE 3: Input: 2 5 12 50 43 null null
               2 5 12 50 43 null null
               (2 same trees)
		Output: 1 (true)
*/