#include <iostream>
#include "../Sorting.h"

void mergeSortHelp(int* ar, int start, int end) {
    if (start >= end) return;
    int mid = (start + end)/2;

    mergeSortHelp(ar, start, mid);
    mergeSortHelp(ar, mid + 1, end);

    int* br = new int[end - start + 1];
    int left = start;
    int right = mid + 1;
    int cur = 0;

    while (left != mid + 1 && right != end + 1) {
        if (ar[left] <= ar[right]) br[cur++] = ar[left++];
        else br[cur++] = ar[right++];
    }
    while (left != mid + 1) {
        br[cur++] = ar[left++];
    }
    while (right != end + 1) {
        br[cur++] = ar[right++];
    }
    for (int i = 0; i < cur; i++) {
        ar[start + i] = br[i];
    }
    delete[] br;
}

void mergeSort(int* ar, int n) {
    mergeSortHelp(ar, 0, n - 1);
}

//Nguyen Quang Hieu - 25125043

/*
Testing for datasets of 100.000 elements:

Random dataset: 0.0314306 seconds.
Sorted dataset: 0.0189916 seconds.
Reversed sorted dataset: 0.0200192 seconds.
Interleaved dataset: 0.0412434

=> For sorted and reversed sorted dataset, merge sort performs the least comparison possible (only compare the first element
of a part to every element of the other part), whereas for random dataset, the comparison increases, especially for interleaved
dataset (dataset that are 2 distinct sorted dataset, place alternatingly with each other), where the number of comparison is
maximum, the performance decreases a lot, takes up to double that of the best-case dataset, however, the difference is still
negligible that it is almost unnoticable. So, best-case dataset is sorted or reversed sorted dataset and worst-case dataset
is interleaved dataset.
*/