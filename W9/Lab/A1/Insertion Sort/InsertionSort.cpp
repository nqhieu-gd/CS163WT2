#include <iostream>
#include "../Sorting.h"

void insertionSort(int* ar, int n) {
    for (int i = 1; i < n; i++) {
        int pt = i;
        int key = ar[i];
        while (pt > 0 && ar[pt - 1] > key) {
            ar[pt] = ar[pt - 1];
            pt--;
        }
        ar[pt] = key;
    }
}

//Nguyen Quang Hieu - 25125043

/*
Testing for datasets of 100.000 elements:

Random dataset: 4.15943 seconds.
Sorted dataset: 0.0002052 seconds.
Reversed sorted dataset: 8.26539 seconds.

=> For a sorted dataset, insertion only traverse the array without making any changes because the sorted part + the new element
is already sorted, whereas for a reversed sorted array, it needs to perform maximum number of operation possible, results in
a massive difference in time performance: best-case is sorted dataset and worst-case is revesed sorted dataset.
*/