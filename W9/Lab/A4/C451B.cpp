#include <iostream>

void canWeFlip(int* ar, int n) {
    if (n == 1) {
        std::cout << "yes\n" << 1 << ' ' << 1 << '\n';
        return;
    }
    int count = 0;
    int pt = 1;
    int left = 0, right = 0;
    while (pt < n) {
        if (ar[pt] < ar[pt - 1]) {
            if (count == 1) break;
            count++;
            left = pt - 1;
            while (pt < n && ar[pt] < ar[pt - 1]) pt++;
            right = pt - 1;
        }
        pt++;
    }
    if ((pt < n) || (right < n - 1 && ar[left] > ar[right + 1]) || (left > 0 && ar[right] < ar[left - 1])) {
        std::cout << "no\n";
        return;
    }
    std::cout << "yes\n" << left + 1 << ' ' << right + 1 << '\n';
}

int main() {
    int n = 0;
    std::cin >> n;
    int* ar = new int[n];
    for (int i =0; i < n; i++) {
        std::cin >> ar[i];
    }
    canWeFlip(ar, n);
    delete[] ar;

    return EXIT_SUCCESS;
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

let n be the number of numbers in the array

Space complexity:
- canWeFlip: no auxiliary spaces required -> O(1)

Time complexity:
- canWeFlip: traverse the array to find the "flip parts" -> O(n)



ALGORITHM EXPLAINATION

We have to flip once and only once, so all we need to do is to find a "flip part", meaning a part where the increasing order
is violated, if we find 2+ such part, then we have to flip more than once, so we will print out "no"; however, if we found only
1 part, then that part is already sorted reversedly (if not, then it will have 2 elements such that the latter is higher than
the former, in which case it doesn't violate the increasing order, hence it would be considered 2 distinct "flip parts"), so
for it to be possible to be flipped in order to make the array sorted, the last element has to be higher than the element
befor the first element and the first element has to be lower than the element after the last element; if no such part is found,
we can simply rotate some element with itself, because in that case the array has already been sorted.



TEST CASE

CASE 1: Input: 6
               143, 54, 43, 32, 22, 1 (reversed sorted array)
		Output: yes
                1 6

CASE 2: Input: 6
               1, 22, 32, 43, 54, 143 (sorted array)
		Output: yes
                1 1

CASE 3: Input: 6
               1, 2, 4, 3, 6, 5 (array with 2 "flip parts")
		Output: no
*/