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

let k = 1000001 be the size of is_prime

Space complexity:
- is_prime storage: O(k)
- sqr takes constant space -> O(1)
=> O(k) space

Time complexity:
- buildUp: the classic sieve of Eratosthene building function -> O(k log(log k))
- sqr: applying binary search to find the perfect quare root -> O(log x)
sqr is called n times => O(k log(log k) + n log x) time
*/

/*
ALGORITHM EXPLAINATION

The sieve of Eratosthene is a classic algorithm to detect prime numbers for time efficiency at the cost
of spaces.

A T-prime is a number with 3 divisors, assume n is a T-prime, then n has 3 divisors which are 1, n and a
prime number 1 < p < n. Since p is n's divisor, n/p is also n's divisor, and 1 < n/p < n, so n/p = p, which
means n = p^2.

The sqr function is used to find perfect square root of a number. As stated above, we only need to know
perfect square root so this is enough.

In the main function, we continuously enter n number, after each input, we examine if that number satisfies
T-prime's qualities, then print out "YES" or "NO" accordingly.
*/

/*
TEST CASE

CASE 1: Input: 2
               51 25
		Output: NO
                YES

CASE 2: Input: 5
               1 25 0 4 3
		Output: NO
                YES
                NO
                YES
                NO

CASE 3: Input: 0
		Output:
*/