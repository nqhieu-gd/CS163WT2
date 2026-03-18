class Solution {
public:
    struct heapCall {
        int size;
        vector<int> heap;
        void insert(int key) {
            heap.push_back(key);
            int s = size - 1;
            size++;
            while (s > -1 && key > heap[s/2]) {
                swap(heap[s/2], heap[s + 1]);
                s = s/2 - 1;
            }
        }
        void smash() {
            if (size >= 2) {
                int id1 = pop();
                id1 = id1 - pop();
                if (id1 > 0) insert(id1);
            }
        }
        int pop() {
            int sub = heap[0];
            swap(heap[0], heap[size - 1]);
            heap.erase(heap.begin() + size - 1);
            size--;
            rebalance();
            return sub;
        }
        void rebalance() {
            int i = 0;
            while (2*i + 2 < size) {
                if (heap[i] < heap[2*i + 2] && heap[2*i + 1] < heap[2*i + 2]) {
                    swap(heap[i], heap[2*i + 2]);
                    i = 2*i + 2;
                }
                else if (heap[i] < heap[2*i + 1] && heap[2*i + 1] >= heap[2*i + 2]) {
                    swap(heap[i], heap[2*i + 1]);
                    i = 2*i + 1;
                }
                else break;
            }
            if (2*i + 1 < size && heap[i] < heap[2*i + 1]) swap(heap[i], heap[2*i + 1]);
        }
        int top() {
            if (size == 0) return 0;
            return heap[0];
        }
        heapCall(): size(0) {}
        ~heapCall() {}
    };

    int lastStoneWeight(vector<int>& stones) {
        heapCall hc;
        for (int c : stones) hc.insert(c);
        while (hc.size > 1) {
            hc.smash();
        }
        return hc.top();
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

let n be the number of stones

Space complexity:
- size, insert, rebalance, top, pop and smash all cost constant space: O(1)
- heap storage: O(n)
- LastStoneWeight calls heapCall once to store the stones data: O(n)
=> O(n) space

Time complexity:
- insert: push_back at far below of the heap and redegree the newly added data level by level -> O(log n)
- rebalance: the balance operation is similar to the insert balancing logic, but it starts from the head element of
the heap till down below -> O(log n)
- top: call the top element of the heap only -> O(1)
- pop: call the top element of the heap, then subtract it from the heap after swapping it with the last element of
the heap and call rebalance there after -> O(log n)
- smash:
    + pop 2 highest elements -> O(log n)
    + Get the difference between them, if it's more than 0, insert the difference back into the heap -> O(log n)
=> O(log n)
- LastStoneWeight:
    + Calls insert n times -> O(n log n)
    + Calls smash until there is no more than 1 element left, after each smash the number of stones goes down by 1
or 2, so we expect a total of ~n smash calls -> O(n log n)
    + return the highest element of the heap by calling hc.top -> O(1)
=> O(n log n)



ALGORITHM EXPLAINATION

We will use priority queue for this problem, here I built my own max heap with the basic functions including upheap,
downheap (insert and pop), root (top) and self-balance (rebalance), with the addition of smash function

What the smash function does is that it calls 2 highest elements, in this case they are 2 heaviest stones, then deduct
the heavier one's mass by the lighted one's mass, if they have the same weight, they both vanish, else the heavier one
remains, then push the remaining mass back to the heap.

By doing so until the size of the heap is no more than 1, we have the right result for the problem.



TEST CASE

CASE 1: Input: 2 5 12 50 4 3 (abnormal heavy stone)
		Output: 24

CASE 2: Input: 5 5 5 5 5 5 5 5 (even number of stones of the same weight)
		Output: 0

CASE 3: Input: 6 8 10 9 5 7 3 4 (stones that are 1 unit heavier than the heaviest one lighter than itself)
		Output: 0
*/