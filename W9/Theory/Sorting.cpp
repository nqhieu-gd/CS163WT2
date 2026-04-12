#include <iostream>
#include "Sorting.h"

void QuickSort(int* a, int n) {
    QuickSortHelp(a, 0, n - 1);
}

void QuickSortHelp(int* a, int start, int end) {
    if (start >= end) return;
    int med = (start + end)/2;
    int left = start, right = med + 1;
    for (int i = 0; i < med; i++) {
        left = i;
        if (a[left] > a[med]) {
            while (right <= end && a[right] > a[med]) right++;
            if (right >end) break;
            std::swap(a[right], a[left]);
        } 
    }
    if (left < med) {
        int num = 0;
        int Nleft = left;
        left = med - 1;
        while (Nleft < med) {
            if (a[Nleft] > a[med]) {
                std::swap(a[Nleft], a[left--]);
                num++;
            }
            Nleft++;
        }
        std::swap(a[med], a[med - num]);
        med = med - num;
    }
    if (right++ <= end) {
        int num = 0;
        int Nright = right;
        right = med + 1;
        while (Nright <= end) {
            if (a[Nright] < a[med]) {
                std::swap(a[Nright], a[right++]);
                num++;
            }
            Nright++;
        }
        std::swap(a[med], a[med + num]);
        med = med + num;
    }
    QuickSortHelp(a, start, med);
    QuickSortHelp(a, med + 1, end);
}