#pragma once

void selectionSort(int* ar, int n);

void insertionSort(int* ar, int n);


void quickSortHelp(int* ar, int start, int end);
void quickSort(int* ar, int n);


void mergeSortHelp(int* ar, int start, int end);
void mergeSort(int* ar, int n);


void heapAdd(int* ar, int n, int key);
void heapBuild(int* ar, int n);
void HeapBalance(int* ar, int n);
void heapSortFunc(int* ar, int n);
void heapSort(int* ar, int n);