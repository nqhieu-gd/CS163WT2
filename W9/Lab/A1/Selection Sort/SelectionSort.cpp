#include <iostream>
#include "../Sorting.h"

void selectionSort(int* ar, int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i; j < n; j++) {
            if (ar[j] < ar[min]) min = j;
        }
        std::swap(ar[i], ar[min]);
    }
}

//Nguyen Quang Hieu - 25125043

/*
Testing for datasets of 100.000 elements:

Random dataset: 6.1824 seconds.
Sorted dataset: 6.20861 seconds.
Reversed sorted dataset: 6.3986 seconds.

=> Selection sort always traverses the array to find the min value and swap with the min idex value of the unsorted part, so
the performance will always be the same, hence the results are close and are always slow for large dataset.
*/