/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int nodeNum(TreeNode* A) {
    if (A == NULL) return 0;
    return 1 + nodeNum(A->left) + nodeNum(A->right);
}

int Solution::kthsmallest(TreeNode* A, int B) {
    TreeNode* cur = A;
    int k = nodeNum(cur->left) - B + 1;
    while (k != 0) {
        while (k > 0) {
            cur = cur->left;
            k = k - nodeNum(cur->right) - 1;
        }
        while (k < 0) {
            cur = cur->right;
            k = k + nodeNum(cur->left) + 1;
        }
    }
    return cur->val;
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

let n be the number of node, h be the height of the tree

Space complexity:
- nodeNum: recursion depth: O(h)
- kthsmallest: constant number of variables, call nodeNum seperately each while loop -> O(h),
best case: O(log(n)) (balanced tree), worst case: O(n) (skewed tree)
=> O(h) space

Time complexity:
- nodeNum: visit each node once -> O(n)
- kthsmallest: O(n^2)
    + For balance tree, the subtree examined is halve each time -> the nodes examined are n/2 + n/4 +... ~ n
    -> O(n)
    + For generally expected and skewed tree, each time kthsmallest is called, the whole subtree to the left of
    the current node is examined, even though the latter subtree has less nodes than the former subtree, it is
    still O(n^2) in general
=> O(n^2) time
*/

/*
ALGORITHM EXPLAINATION

The nodeNum function is used to calculate the number of nodes in the tree with its root as the parameter.

Firstly, we call a variable k represent the number of nodes to the left of the root and itself. If k > B, it
suggests that the node we need to find is smaller than the current node, so we move to the left. Otherwise if k < B,
 that means the node we want to find is bigger than the current node, so we move the current node to the right.
In case k > B, after moving the current location to the left, we consider only the left part, so we minus the total
nodes to the right of the current node and the node we are originally from, then update it to k. In case k < B,
since we moved to the right, there are more nodes now, so we need to add those nodes to the left of the current
node and itself, then update it to k. We will continue those operations until k = B (reachable since there is a
restriction 1 <= B <= number of nodes, as long as we are still in the tree that is).
*/

/*
TEST CASE (restriction: 1 <= B <= n)

CASE 1: Input: 1 2 3 4 5 null null 6
               5
		Output: 2

CASE 2: Input: 0
               1
		Output: 0

CASE 3: Input: 2 5 12 50 43 null null
               3
		Output: 12
*/