#include <iostream>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s = s1.size();
        if (s2.size() < s) return false;
        int alphabet[26] = {0};
        for (int i = 0; i < s; i++) {
            alphabet[s1[i] - 97]--;
        }
        return check(s, s2, 0, alphabet);
    }

    bool PermCheck(int s, string& s2, int ini, int arr[]) {
        int ar[26];
        for (int i = 0; i < 26; i++) {
            ar[i] = arr[i];
        }
        for (int i = 0; i < s; i++) {
            ar[s2[ini + i] - 97]++;
        }
        for (int i = 0; i < 26; i++) {
            if (ar[i] != 0) return false;
        }
        return true;
    }

    bool check(int s, string& s2, int ini, int ar[]) {
        if (ini > s2.size() - s) return false;
        if (PermCheck(s, s2, ini, ar)) return true;
        return check(s, s2, ini + 1, ar);
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n be the size of s1, m be the size of s2

Space complexity:
- alphabet[26] -> O(1)
- maximum recursion depth:
    + 0 if m < n -> O(1)
    + m - n + 1 if m >= n -> O(m)
-> O(n) space

Time complexity:
- CheckInclusion: for (int i = 0; i < s; i++)... -> O(n)
- check: maximum recursion depth is m - n + 1, each time calls CheckInclusion once -> O(n*m)
-> O(n*m) time
*/

/*
ALGORITHM EXPLAINATION

The main function of this code are the PermCheck function and check function. Firstly, the PermCheck function will examine the
substring of s2 starting from the initial position, with the length equal to s1's length. If they are permutation of each other,
return true and false otherwise. Then there is the check function, it will traverse s2 to find all substring all call PermCheck
to check if the current substring is a permutation of s1, if it is, then return true and if no such substring is found, return
false instead.
*/

/*
TEST CASE

CASE 1: Input: s1 = "csapcs", s2 = "sipsapccs"
		Output: true

CSAE 2: Input: s1 = "nqhieu", s2 ="hieuquang"
		Output: false

CASE 3: Input: s1 = "lab", s2 = "balloonparty"
		Output: true
*/