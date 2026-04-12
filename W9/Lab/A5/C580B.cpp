#include <iostream>

struct duo{
    int money;
    long long frsp;
};

void mergeSort(duo* ar, int start, int end) {
    if (start >= end) return;
    int mid = (start + end)/2;

    mergeSort(ar, start, mid);
    mergeSort(ar, mid + 1, end);

    duo* br = new duo[end - start + 1];
    int left = start;
    int right = mid + 1;
    int cur = 0;

    while (left != mid + 1 && right != end + 1) {
        if (ar[left].money <= ar[right].money) br[cur++] = ar[left++];
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

void company(duo* ar, int n, int dif) {
    if (n == 0) return;
    int left = 0, right = 1;
    long long max = 0, sub = ar[left].frsp;
    while (right < n) {
        if (ar[right].money - ar[left].money >= dif) {
            if (sub > max) max = sub;
            sub -= ar[left].frsp;
            left++;
        }
        else {
            sub += ar[right].frsp;
            right++;
        }
    }
    if (sub > max) max = sub;
    std::cout << max;
}

int main() {
    int n, dif;
    std::cin >> n >> dif;
    duo* ar = new duo[n];
    for (int i = 0; i < n; i++) {
        duo sub;
        std::cin >> sub.money >> sub.frsp;
        ar[i] = sub;
    }
    mergeSort(ar, 0, n - 1);
    company(ar, n, dif);

    return EXIT_SUCCESS;
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

let n be the number of friends

Space complexity:
- mergeSort: cost n space to create a temporary array -> O(n)

Time complexity:
- mergeSort: follow the devide and concur method -> O(log n)
- company: use 2 pointers to traverse the array and find the viable friends group with maximum friendship factor -> O(n)
=> Overall: O(n)



ALGORITHM EXPLAINATION

If a friend A and a friend B can go together, that means all the friends that has more money than A but less money than B
(or vise versa) can also go to further increase the friendship factor. With that idea in mind, to avoid having to traverse
the friendlist for every possible composition, we just have to sort them based on their money. Assume we currently have a
group ranging from friend A to friend B, we will try to add friend number B + 1 and subtract all friend that can not go with
B + 1, we now have a group of frind number A + x (x >= 0) to friend number B + 1, if this group has more friendship factor
than the maximum friendship factor available, we rewrite the friendship factor, then we continue until we have examined all
friends of Kefa's.



TEST CASE

CASE 1: Input: 6, 1000000
               143, 1
               54, 5
               43, 43
               32, 54
               22, 99
               1, 100 (huge poor factor)
		Output: 303 (all of the above)

CASE 2: Input: 6, 1
               143, 1
               54, 5
               43, 43
               32, 54
               22, 99
               1, 100 (minimal poor factor)
		Output: 100 (only 1)

CASE 3: Input: 6, 50
               143, 1
               54, 5
               43, 43
               32, 54
               22, 99
               1, 100 (medium poor factor)
		Output: 296 (1, 22, 43 and 32)
*/