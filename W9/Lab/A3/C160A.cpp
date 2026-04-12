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
        if (ar[left] >= ar[right]) br[cur++] = ar[left++];
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

int sum(int* ar, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += ar[i];
    }
    return s;
}

void beingPetty(int* ar, int sum, int n) {
    int s = 0, num = 0;
    for (int i = 0; i < n; i++) {
        num++;
        s += ar[i];
        sum -= ar[i];
        if (s > sum) break;
    }
    std::cout << num;
}

int main() {
    int n;
    std::cin >> n;
    int* ar = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> ar[i];
    }
    mergeSort(ar, 0, n - 1);
    beingPetty(ar, sum(ar, n), n);

    return EXIT_SUCCESS;
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

let n be the number of coins

Space complexity:
- mergeSort: cost n space to create a temporary array -> O(n)

Time complexity:
- mergeSort: follow the devide and concur method -> O(log n)
- sum: traverse the whole array -> O(n)
- beingPetty: traverse the array and gradually take coins until the condition is met -> O(n)
=> Overall: O(n)



ALGORITHM EXPLAINATION

We want to take the least number of coins but the sum is higher, so we have to start by taking the largest coins, so we will
sort the array decreasingly, then count the total sum of the coins; after that, we gradually takes the largest coin possible,
if the sum of our coins is not larger than the remaining coins, repeat the process until it is; finally, we print out the number
of coins we took and that's it.



TEST CASE

CASE 1: Input: 6
               143, 54, 43, 32, 22, 1 (sorted array)
		Output: 2 (143 and 54)

CASE 2: Input: 6
               1, 22, 32, 43, 54, 143 (sorted array)
		Output: 2 (143 and 54)

CASE 3: Input: 6
               5, 5, 5, 5, 5, 5 (equilibrium array)
		Output: 4 (4 coins of 5)
*/