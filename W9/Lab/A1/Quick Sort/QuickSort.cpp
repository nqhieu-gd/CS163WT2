#include <iostream>
#include "../Sorting.h"

void quickSortHelp(int* ar, int start, int end) {
    if (start >= end) return;
    int med = ar[(start + end)/2];
    int left = start, right = end;
    while (left <= right) {
        while (ar[left] < med) left++;
        while (ar[right] > med) right--;
        if (left <= right) {
            std::swap(ar[right], ar[left]);
            left++;
            right--;
        }
    }
    quickSortHelp(ar, start, right);
    quickSortHelp(ar, left, end);
}

void quickSort(int* ar, int n) {
    quickSortHelp(ar, 0, n - 1);
}

//Nguyen Quang Hieu - 25125043

/*
Testing for datasets of 100.000 elements: (choosing median as the middle element)

Random dataset: 0.0134837 seconds.
Sorted dataset: 0.0044381 seconds.
Anti-quick-sort dataset: 0.0141237 seconds.

=> Quick sort works best on sorted dataset since we don't need to perform any swap and the median element will always stay
in the middle, results in lightning fast performance; random dataset gives worse results since it requires a lot of swap
and the median may not be in the middle but somewhere far in the left/right side. And anti-quick-sort dataset (dataset that
always has the median element at each step the maximum/minimum element). Reversed sorted gives the best results as well
because the swap happens at each element, keeping the median in the middle all the time. Best-case dataset: sorted or reversed
sorted dataset and worst-case dataset: anti-quick-sort dataset
*/