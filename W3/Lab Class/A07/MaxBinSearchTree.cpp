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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> st;
        for (int i = 0; i < nums.size(); i++) {
            TreeNode* cur = new TreeNode(nums[i]);
            while (!st.empty() && st.top()->val < nums[i]) {
                cur->left = st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.top()->right = cur;
            }

            st.push(cur);
        }
        while (st.size() > 1)
            st.pop();
        return st.top();
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n be the size of nums

Space complexity: maximum storeage needed for stack is n
-> O(n) space

Time complexity: the loop traverses the whole nums vector, but each element only got added only once and got removed
once (except the largest element), each element got their right/left pointer assigned at most once
-> O(n) + O(n) + O(n) + O(n - 1) = O(n) time
*/

/*
ALGORITHM EXPLAINATION

At the start of each loop cycle, a node is created based on the current nums element

Let's say a node is "selected before" another node when there is a subtree that consists of itself as a root and that
node. So what the loop does is that: when the stack is empty, it simply push the current node; when the stack isn't empty, it examine
the stack, if the top element's value is smaller than the current nums element, that means the current element must has been
selected before the stack's top element, and since it was added to the stack before the current nums element, it must has been
to the left of that nums element, hence assign cur->left = st.top(); and if the condition isn't met, that means the current nums
element is smaller than the stack's top, and since it is to the right, it must be the stack's top's right subtree's root, hence
the assigning st.top()->right = cur; but we push the current nums element to stack nevertheless, so the stack will have more than
1 element if they are decreasing, hence the while loop. And all we've done is assigning the pointers while keeping the largest
element as the last one in stack (smaller elements got popped, but not larger ones), wee just pop the stack until only one element
is left and it is both stack's top and the binary tree's root
*/

/*
TEST CASE

CASE 1: Input: nums = [1,2,3,4,5]
		Output: [5,4,null,3,null,2,null,1,null]

CSAE 2: Input: nums = [5,4,3,2,1]
		Output: [5,null,4,null,3,null,2,null,1]

CASE 3: Input: nums = [1,2,5,0,4,3]
		Output: [5,2,4,1,null,0,3]

*/