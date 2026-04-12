#include <iostream>
#include "../Sorting.h"

void heapAdd(int* ar, int n, int key) {
    ar[n] = key;
    while (n > 0) {
        if (ar[n] > ar[(n - 1)/2]) {
            std::swap(ar[n], ar[(n - 1)/2]);
            n = (n - 1)/2;
            continue;
        }
        break;
    }
}

void heapBuild(int* ar, int n) {
    for (int i = 1; i < n; i++) {
        heapAdd(ar, i, ar[i]);
    }
}

void HeapBalance(int* ar, int n) {
    for (int i = 0; i*2 + 1 < n;) {
        int sub = 1;
        if (i*2 + 2 < n && ar[i*2 + 1] < ar[i*2 + 2]) sub = 2;
        if (ar[i] < ar[i*2 + sub]) {
            std::swap(ar[i], ar[i*2 + sub]);
            i = i*2 + sub;
            continue;
        }
        break;
    }
}

void heapSortFunc(int* ar, int n) {
    for (int i = n - 1; i > 0; i--) {
        std::swap(ar[0], ar[n - 1]);
        HeapBalance(ar, n - 1);
    }
}

void heapSort(int* ar, int n) {
    heapBuild(ar, n);
    heapSortFunc(ar, n);
}

//Nguyen Quang Hieu - 25125043

/*
Testing for datasets of 100.000 elements:

Random dataset: 0.0037725 seconds.
Sorted dataset: 0.0108063 seconds.
Reversed sorted dataset: 0.0010275 seconds.

=> Heap sort build a max heap from the given dataset, a sorted dataset will force it to build the max heap from scratch but
the elements are more managable, hence whenever it switch with the last element, the time it takes to heapify down also
decreases; whereas for reversed sorted dataset, it doesn't build a heap because the array itself is a max heap already, but
the last element is always the smallest, so it calls heapify every time and it takes maximum time possible, results in worse
time performance. The performance results speaks for itself: sorted > random > reversed sorted
*/