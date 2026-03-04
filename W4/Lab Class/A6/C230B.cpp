#include <iostream>
#include <vector>

bool is_prime[1000001];

void buildUp() {
    std::fill(is_prime + 2, is_prime + 1000001, true);
    for (long long p = 2; p * p <= 1000000; p++) {
        if (is_prime[p]) {
            for (long long i = p * p; i <= 1000000; i += p)
                is_prime[i] = false;
        }
    }
}

long long sqr(long long n) {
    if (n == 1 || n == 0) return 1;
    long long beg = 2, end = 1000000, cur = 600001;
    while (cur*cur != n) {
        if (beg + 1 >= end) {
            if (beg*beg == n) return beg;
            else if (end*end == n) return end;
            else return 1;
        }
        if (cur*cur > n) {
            end = cur;
            cur = (end + beg)/2;
        }
        else {
            beg = cur;
            cur = (end + beg)/2;
        }
    }
    return cur;
}

int main() {

    buildUp();

    int n;
    std::cin >> n;
    while (n--) {
        long long x;
        std::cin >> x;
        
        long long root = sqr(x);
        
        if (root * root == x && is_prime[root]) {
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    }
    return 0;
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Space complexity:
- vector storage is the number of lanterns -> O(n) space
- temp vector for merge sort -> O(n) space
=> O(n) space

Time complexity:
- merege sort: O(n)
- each pair of adjacent location is examined once, plus the outer range, for a total of n + 1 examinations -> O(n)
=> O(n) time
*/

/*
ALGORITHM EXPLAINATION

Firstly, the container (vector in this case) is sorted, then we examine each pair of adjacent location to find the
largest distance. If the largest distance is bigger than 2 times the distance of the first lantern and starting point
and of the last lantern and the last point of the road, then the radius of the lighting area is half of it, that way
every area of the road is covered. Otherwise, the minimum radius must be the higher between the distance of the first
lantern to the starting point and the distance of the last lantern and the last point to cover the whole road (every
other point is covered to since the distance is smaller).
*/

/*
TEST CASE

CASE 1: Input: 2, 5,
               4, 3
		Output: 3

CSAE 2: Input: 5, 12
               2, 5, 0, 4, 3
		Output:7

CASE 3: Input: 6, 18
               0, 13, 15, 18, 3, 5
		Output: 4
*/