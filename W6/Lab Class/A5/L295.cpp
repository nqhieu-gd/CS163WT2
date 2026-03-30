class MedianFinder {
    int bal;
    vector<int> maxH;
    vector<int> minH;

    void insert(int key, vector<int>& list, bool check) {
        list.push_back(key);
        int s = list.size() - 2;
        while (s > -1) {
            if (list[s + 1] != list[s/2] && (list[s + 1] > list[s/2]) == check) {
                swap(list[s + 1], list[s/2]);
                s = s/2 - 1;
            }
            else break;
        }
    }

    int top(vector<int>& list) {
        if (list.size() == 0) return -1;
        return list[0];
    }

    int pop(vector<int>& list, bool c) {
        if (list.size() == 0) return -1;
        int j = list.size() - 1;
        int sub = list[0];
        swap(list[0], list[j]);
        list.erase(list.begin() + j);
        int i = 0;
        if (c == true) {
            while (2*i + 2 < j) {
                if (list[i] < list[2*i + 2] && list[2*i + 1] < list[2*i + 2]) {
                    swap(list[i], list[2*i + 2]);
                    i = 2*i + 2;
                }
                else if (list[i] < list[2*i + 1] && list[2*i + 1] >= list[2*i + 2]) {
                    swap(list[i], list[2*i + 1]);
                    i = 2*i + 1;
                }
                else break;
            }
            if (2*i + 1 < j && list[i] < list[2*i + 1]) swap(list[i], list[2*i + 1]);
        }
        else {
            while (2*i + 2 < j) {
                if (list[i] > list[2*i + 2] && list[2*i + 1] > list[2*i + 2]) {
                    swap(list[i], list[2*i + 2]);
                    i = 2*i + 2;
                }
                else if (list[i] > list[2*i + 1] && list[2*i + 1] <= list[2*i + 2]) {
                    swap(list[i], list[2*i + 1]);
                    i = 2*i + 1;
                }
                else break;
            }
            if (2*i + 1 < j && list[i] > list[2*i + 1]) swap(list[i], list[2*i + 1]);
        }
        return sub;
    }

    void rebalance() {
        if (minH.size() > 0 && top(minH) < top(maxH)) {
            int min = pop(minH, false);
            int max = pop(maxH, true);
            insert(min, maxH, true);
            insert(max, minH, false);
        }
    }

    void add(int key) {
        if (bal == 0) {
            insert(key, maxH, true);
            bal++;
        }
        else {
            insert(key, minH, false);
            bal--;
        }
        rebalance();
    }

public:
    MedianFinder(): bal(0) {}
    ~MedianFinder() {}
    
    void addNum(int num) {
        add(num);
    }
    
    double findMedian() {
        if (bal == 1) return top(maxH);
        else return (double) (top(maxH) + top(minH))/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n be the number of number added

Space complexity:
- maxH storage: ~n/2 -> O(n)
- minH storage: ~n/2 -> O(n)

Time complexity:
- insert: insert a number to one of the 2 heaps and rebalance the added number by swapping with its parent if the
condition is met -> O(log n)
- top: return the top element of the current heap -> O(1)
- pop: calls the top element of the current heap, then remove it from the heap by swapping it with the last element
and rebalance the heap again -> O(log n)
- rebalance: if the top of the minH is smaller than the top of the maxH, swap them to keep them in check by calling
pop and insert twice -> O(log n)
- add: add an element to one of the heap after checking the balance factor: if it is 0, meaning 2 heaps are having the
same number of elements, then add to maxH first, else add to minH first, then call rebalance -> O(log n)
- addNum: call add once -> O(log n)
- findMedian: check the balance factor to know if there are odd or even number of elements, then return the
corresponding result -> O(1)



ALGORITHM EXPLAINATION

The median is the middle elements of all the input elements, if we devide them into 2 streams, then we only care
for the lowest element in the upper half, or the highest element in the lower half, or both.

minH is to store the bigger half with the top element always being the lowest one, and maxH is to store the lower
half with the top element always being the highest one.

The idea is to keep the order of their elements according to those rules, then we will know the exact result by
calling the top element of the 2 heaps.

The reason for choosing heap is that it can be sorted in O(log n) time and cost a constant space, while with regular
container it would be up to O(n).



TEST CASE

CASE 1: Input: 18 (only 1 input)
		Output: 18

CASE 2: Input: 2, 5, 12, 50, 4, 3 (regular input)
		Output: 4.5

CASE 3: Input: -1 -5 -4 6 9 (negative input included)
		Output: -1
*/