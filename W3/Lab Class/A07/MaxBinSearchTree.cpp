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
        TreeNode* head = nullptr;
        Construct(nums, 0, nums.size() - 1, head);
        return head;
    }

    void Construct(vector<int>& nums, int beg, int end, TreeNode*& head) {
        int idx = beg;
        for (int i = beg + 1; i <= end; i++) {
            if (nums[i] > nums[idx]) {
                idx = i;
            }
        }
        if (!head) {
            head = new TreeNode(nums[idx]);
            if (idx > beg) Construct(nums, beg, idx - 1, head->left);
            if (idx < end) Construct(nums, idx + 1, end, head->right);
        }
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n be the size of nums

Space complexity: maximum recursion depth is n, each recursion call uses 1 extra space (int idx)
-> O(n) space

Time complexity: maximum recursion depth is n, consider at the number k recursion call, we have to scan a total
of m elements in nums -> O(m) time -> worst case: O(n^2) time
*/

/*
ALGORITHM EXPLAINATION

The main function of this code is the Construct function, it scans the whole array to find the largest element, then
it construct a binary tree/sub binary tree using the found element, then create a binary tree using the left leftover
elements and the right leftover elements as its sub trees on the left and right side correspondingly
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