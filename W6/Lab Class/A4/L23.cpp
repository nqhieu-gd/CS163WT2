/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1->val > list2->val) {
            list2->next = merge2Lists(list1, list2->next);
            return list2;
        }
        else {
            list1->next = merge2Lists(list1->next, list2);
            return list1;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        return mergingMerge(lists, 0, lists.size() - 1);
    }

    ListNode* mergingMerge(vector<ListNode*>& v, int beg, int end) {
        if (end <= beg) return v[beg];

        int i = (beg + end)/2;

        v[beg] = mergingMerge(v, beg, i);
        v[end] = mergingMerge(v, i + 1, end);

        return merge2Lists(v[beg], v[end]);
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let K be the number of linked list and m be the average number of nodes in a list

Space complexity:
- merge2Lists: maximum recursion stack: 2*m -> O(m)
- mergingMerge: maximum recursion stack is K -> O(log K)
- mergeKLists: cost constant space -> O(1)

Time complexity:
- merge2Lists: maximum recursion stack: 2*m, each operation cost constant time -> O(m)
- mergingMerge: maximum recursion stack is K, each mergingMerge also calls merge2Lists -> O(m log K)
- mergeKLists: call mergingMerge from start to end -> O(m log K)



ALGORITHM EXPLAINATION

merge2Lists is the standard merging function for 2 singly linked lists.

mergingMerge merge lists by pairs each time to minimize the time cost for merge2Lists (i.e. to prevent cases like
merging a n*n sized linked list with a n sized one, continue like that up to kth list) so the time cost doesn't get
to O(m * k) but O(m log K) instead.

mergeKLists check if the list of lists is empty, if it is then just do nothing, if not then merge all k lists.



TEST CASE

CASE 1: Input:[] (empty list of lists)
		Output: 

CASE 2: Input: [[1, 2, 3, 4, 5, 6, 7, 8, 9], [10, 11]] (one list that has the lowest element higher than the other's
highest element)
		Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

CASE 3: Input: [[null], [1, 2, 3]] (one empty list, one regular list)
		Output: [1, 2, 3]
*/