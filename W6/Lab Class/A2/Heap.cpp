#include "Heap.h"
#include <iostream>

int parent(int* a, int n, int i) {
    if (i == 0) return -1;
    return (i - 1)/2;
}

int left(int* a, int n, int i) {
    if (i*2 + 1 >= n) return -1;
    return i*2 + 1;
}

int right(int* a, int n, int i) {
    if (i*2 + 2 >= n) return -1;
    return i*2 + 2;
}

void maxHeapify(int* a, int n, int i) {
    while (i*2 + 2 < n) {
        if (a[i*2 + 1] > a[i*2 + 2] && a[i] < a[i*2 + 1]) {
            std::swap(a[i], a[i*2 + 1]);
            i = i*2 + 1;
        }
        else if (a[i*2 + 1] <= a[i*2 + 2] && a[i] < a[i*2 + 2]) {
            std::swap(a[i], a[i*2 + 2]);
            i = i*2 + 2;
        }
        else break;
    }
    if (i*2 + 1 < n && a[i] < a[i*2 + 1]) std::swap(a[i], a[i*2 + 1]);
}

void buildMaxHeap(int* a, int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        maxHeapify(a, n, i);
    }
}

void heapSort(int* a, int n) {
    buildMaxHeap(a, n);
    for (int i = n - 1; i > 0; i--) {
        std::swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n be the number of array elements

Space complexity:
- Array storage: n -> O(n)
- Each function works on the array without allocating new memory -> O(1) for all

Time complexity:
- parent / left / right: the index for the corresponding element is fixed -> O(1)
- maxHeapify: the current element will only sink to 1 of its 2 child elements -> O(log n)
- buildMaxHeap: calls maxHeapify for the upper part of the heap, meaning n/2 times -> O(n log n)
- heapSort: creates a heap by using buildMaxHeap, then swap the highest element with the last one, then call
maxHeapify to get the newly swapped element to its right place in the new array of n - 1 element, repeat until the
last element -> O(n log n) + O(n log n) = O(n log n)



ALGORITHM EXPLAINATION

- parent / left / right: return the exact index of the corresponding element using heap logic.
- maxHeapify: sink the current element to its child element that is higher than the other one (if there is the other
one) and let that child element take its original place, repeat until it can not sink anymore.
- buildMaxHeap: a heap of n elements would have at least n/2 leaf node, if maxHeapify is call for a leaf node, it
will do nothing so we skip the last n/2 elements, for the remaining part, call maxHeapify from the last element to
the first one (this will avoid the unnecessary error happens when we call maxHeapify from the first element first
because the area it sinks isn't following the heap logic).
- heapSort: it takes the last element and swap it with the last element, now we have a sorted part at the end and
an unsorted part is the remaining one, now we call maxHeapify on the first element to leave it at its right place
and repeat the process, until all the array has been sorted.



TEST CASE

CASE 1: Input: [2, 5, 12, 50, 4, 3], buildMaxHeap(a, 6), left(a, 6, 2)
		Output: [50, 5, 12, 2, 4, 3], 5

CASE 2: Input: [2, 5, 12, 50, 4, 3], buildMaxHeap(a, 6), parent(a, 6, 4)
		Output: [50, 5, 12, 2, 4, 3], 1

CASE 3: Input: [2, 5, 12, 50, 4, 3], buildMaxHeap(a, 6), parent(a, 6, 3)
		Output: [50, 5, 12, 2, 4, 3], 1
*/