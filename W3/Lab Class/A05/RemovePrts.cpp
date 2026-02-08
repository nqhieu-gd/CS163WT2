class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> prts;
        int j = 0, k = s.size();
        for (int i = 0; i < k; i++) {
            char c = s[i];
            if (c == '(') {
                if (!prts.empty()) s[j++] = c;
                prts.push(c);
            } 
            else {
                prts.pop();
                if (!prts.empty())
                    s[j++] = c;
            }
        }
        s.erase(j);
        return s;
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n be size of s, meaning the number of parenthesises

Space complexity: stack: all parenthesises minus the outer most ones, no more extra space needed except for
2 integers -> O(n)

Time complexity: for (int i = 0; i < k; i++) {...} with k = n -> O(n)
*/

/*
ALGORITHM EXPLAINATION

The removeOuterParentheses function will traverse the string s, it will then create another string based on s, but only
add an open or close parenthesis if only it's not the outer most ones, then it return the founded string.

prts (stand for parenthesis) add '(' sign whenever it happens to meet one (except the first one it encounters when it's
empty, because it's the outer most one) and subtract one whenever it meets ')' sign, as s is proper already, the next time
it's emptied again, that means we have encounter the next outer most parenthesis of the right side.
*/

/*
TEST CASE

CASE 1: Input: ((()(()())))((())(()))
		Output: (()(()()))(())(())

CSAE 2: Input: (((())))
		Output: ((()))

CASE 3: Input: ()()()()
		Output: 
*/