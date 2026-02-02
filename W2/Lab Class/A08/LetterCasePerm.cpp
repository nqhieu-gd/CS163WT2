#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> v;
        Permute(s, 0, v);
        return v;
    }

    void Permute(string s, int ini, vector<string>& v) {
        if (ini >= s.size()) {
            v.push_back(s);
            return;
        }
        Permute(s, ini + 1, v);
        if (s[ini] >= 65 && s[ini] <= 90) {
            s[ini] = s[ini] + 32;
            Permute(s, ini + 1, v);
        }
        else if (s[ini] >= 97 && s[ini] <= 122) {
            s[ini] = s[ini] - 32;
            Permute(s, ini + 1, v);
        }
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n be the size of s, meaning the number of characters in s

Space complexity: maximum recursion depth is n
-> O(n) space

Time complexity:
Permute(s, 0, v); -> it will always traverse the whole string to find all combinations possible -> O(n) time
-> O(n) time
*/

/*
ALGORITHM EXPLAINATION

The main function of this code is the Permute function, it will start from the left-most characters, if it is a non-character
sign/symbol, move to the next character, if it is, try both its lowercase and uppercase form and recursingly call the function,
starting from the next character to the right, hence every combination will be go through at least once
*/

/*
TEST CASE

CASE 1: Input: s = "CS163"
		Output: ["CS163","Cs163","cS153","cs163"]

CSAE 2: Input: s = "NQH"
		Output: ["NQH","NQh","NqH","Nqh","nQH","nQh","nqH","nqh"]

CASE 3: Input: s = "lab"
		Output: ["lab","laB","lAb","lAB","Lab","LaB","LAb","LAB"]

*/