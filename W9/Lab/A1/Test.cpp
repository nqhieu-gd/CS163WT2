#include <iostream>
#include <fstream>
#include <chrono>
#include "Sorting.h"
#include "Insertion Sort/InsertionSort.cpp"
#include "Selection Sort/SelectionSort.cpp"
#include "Quick Sort/QuickSort.cpp"
#include "Merge Sort/MergeSort.cpp"
#include "Heap Sort/HeapSort.cpp"

void test(void (*func)(int*, int), std::ifstream& file) {
    int n = 0;
    if(!(file >> n) || n <= 0) {
        std::cerr << "Error reading dataset file.";
        return;
    }
    int* ar = new int[n];
    for (int i = 0; i < n; i++) file >> ar[i];
    auto start = std::chrono::high_resolution_clock::now();
    func(ar, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << elapsed.count() << " seconds.\n";
    file.clear();
    file.seekg(0, std::ios::beg);
    delete[] ar;
}

int main() {
    std::ifstream fin;
    fin.open("dataset.txt");
    if (!fin.is_open()) {
        std::cerr << "Error opening file.";
        return EXIT_FAILURE;
    }
    std::cout << "Begin testing.\n\n";
    // std::cout << "Selection Sort Performance: ";
    // test(selectionSort, fin);
    // std::cout << "Insertion Sort Performance: ";
    // test(insertionSort, fin);
    std::cout << "Quick Sort Performance: ";
    test(quickSort, fin);
    // std::cout << "Merge Sort Performance: ";
    // test(mergeSort, fin);
    // std::cout << "Heap Sort Performance: ";
    // test(heapSort, fin);
    std::cout << "\nFinish testing.\n";
    fin.close();

    return EXIT_SUCCESS;
}

//Nguyen Quang Hieu - 25125043

/*
Testing for a dataset of 100.000 elements for each sorting algorithm:

Selection Sort Performance: 5.43664 seconds.
Insertion Sort Performance: 4.15943 seconds.
Quick Sort Performance: 0.0136476 seconds.
Merge Sort Performance: 0.0217778 seconds.
Heap Sort Performance: 0.0032 seconds.

=> Heap sort gives the best performance, surpass every other sorting algorithm by a large margin.
   Follows right after is quick sort, and then merge sort, although quick sort yields a better result (1.5 times faster than
merge sort), they are both really fast.
   Unfortunately, the next best performance is insertion sort and the last one is selection sort, both are slow (4.16s for 
insertion sort and 5.44s for selection sort).

=> For a moderately large to large dataset, heap sort, quick sort and merge sort give optimal performance, while selection
sort and insertion sort give mediocre and arguably bad performance, they only save more space but cost too much time, so they
are not suitable there.
*/