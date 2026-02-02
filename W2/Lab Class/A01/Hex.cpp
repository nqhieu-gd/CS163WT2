#include "Hex.h"

int translateH2D(char s) {
    if (s > 47 && s < 58) return s - 48;
    if (s > 64 && s < 71) return s - 55;
    if (s > 96 && s < 103) return s - 87;
    return 0;
}

std::string translateD2H(int x) {
    std::string str = " ";
    int y = x%16;
    if (y < 10) str[0] = y + 48;
    else str[0] = y + 55;
    return str;
}

long hex2Decimal(std::string& s, int en) {
    if (en < 0) return 0;
    return hex2Decimal(s, en - 1)*16 + translateH2D(s[en]);
}

std::string decimal2Hex(int x) {
    if (x < 16) return translateD2H(x);
    return decimal2Hex(x/16) + translateD2H(x);
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n be the length of the hex string s, k be the number of hexadecimal digits of integer x (~log_16(x))

- hex2Decimal:
    + Space complexity: maximum recursion depth is n, no extra spaces cost
-> O(n) space
    + Time complexity: call translateH2D n times, translateH2D costs const time
-> O(n) time

- decimal2Hex:
    + Space complexity: maximum recursion depth is k (x has k digits in hex, each operation get one digits), no extra spaces needed
-> O(k) space
    + Time complexity: find k digits of x in hex via translateD2H(x), which costs const time
-> O(k) time
*/

/*
ALGORITHM EXPLAINATION

The Hex-Dec translator read the data character by character, get the total value in decemal and return its number.

The Dec-Hex translator get the number, translate it to hex and replace 10-15 by A-F correspondingly.
*/

/*
TEST CASE
- hex2Decimal:

CASE 1: Input: s = "A"
		Output: 10

CSAE 2: Input: s = "1F"
        Output: 31

CASE 3: Input: s = "2A3"
		Output: 675

- decimal2Hex:

CASE 1: Input: 15
		Output: F

CSAE 2: Input: 16
        Output: 10

CASE 3: Input: 36
		Output: 24
*/