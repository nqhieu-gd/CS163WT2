#include <iostream>

void mergeSort(int* ar, int start, int end) {
    if (start >= end) return;
    int mid = (start + end)/2;

    mergeSort(ar, start, mid);
    mergeSort(ar, mid + 1, end);

    int* br = new int[end - start + 1];
    int left = start;
    int right = mid + 1;
    int cur = 0;

    while (left < mid + 1 && right < end + 1) {
        if (ar[left] <= ar[right]) br[cur++] = ar[left++];
        else br[cur++] = ar[right++];
    }
    while (left < mid + 1) {
        br[cur++] = ar[left++];
    }
    while (right < end + 1) {
        br[cur++] = ar[right++];
    }
    for (int i = 0; i < cur; i++) {
        ar[start + i] = br[i];
    }
    delete[] br;
}

void gravFlip(int* ar, int n) {
    mergeSort(ar, 0, n - 1);
}

void traverse(int* ar, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << ar[i] << ' ';
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    int* ar = new int[n];
    for (int i =0; i < n; i++) {
        std::cin >> ar[i];
    }
    gravFlip(ar, n);
    traverse(ar, n);
    delete[] ar;

    return EXIT_SUCCESS;
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

let n be the number of columns in the box

Space complexity:
- mergeSort: cost n space to create a temporary array -> O(n)

Time complexity:
- mergeSort: follow the devide and concur method -> O(log n)



ALGORITHM EXPLAINATION

If the gravity is turned to the right, then all the cube will be "dropped" to the right side, that means the right-most side
will have the maximum number of toy cubes possible, or the highest toy cubes number in any column previously, while the
left-most side has minimum, that means the toy box has been sorted increasingly from the left to the right, so all we need
to do is to perform a sorting algorithm and we have the answer



TEST CASE

CASE 1: Input: 6
               143, 54, 43, 32, 22, 1 (reversed sorted array)
		Output: 1, 22, 32, 43, 54, 143

CASE 2: Input: 6
               1, 22, 32, 43, 54, 143 (sorted array)
		Output: 1, 22, 32, 43, 54, 143

CASE 3: Input: 6
               5, 5, 5, 5, 5, 5 (equilibrium array)
		Output: 5, 5, 5, 5, 5, 5
*/