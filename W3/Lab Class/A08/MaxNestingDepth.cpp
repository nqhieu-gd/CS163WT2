class Solution {
public:
    int maxDepth(string s) {
        stack<int> prts;
        prts.push(0);
        int k = s.size(), num = 0;
        for (int j = 0; j < k; j++) {
            if (s[j] == '(') {
                prts.push(prts.top() + 1);
                if (prts.top() > num) num = prts.top();
            }
            else if (s[j] == ')' && prts.top() > 0) {
                prts.pop();
            }
        }
        return num;
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n be the size of s

Space complexity: maximum storeage needed for stack is n/2 (s is a proper string of parenthesises so it has n/2 '(' and
n/2 ')'), each stack push is called upon meeting a '(', no additional space needed except for 2 more integer.
-> O(n) space

Time complexity: the loop traverses the whole string s, at s[i], calculate the top and push if s[i] == '(', pop otherwise
-> O(n) time
*/

/*
ALGORITHM EXPLAINATION

The stack prts is used to calculate the current parenthesis's depth, its depth is just the total number of open parenthesis
before minus thhe number of close parenthesis before, then if the depth is higher than the recorded maximum depth, replace
the maximum depth and repeat until the whole string is traversed
*/

/*
TEST CASE

CASE 1: Input: ((((()(()()))())))
		Output: 6

CSAE 2: Input: ()
		Output: 1

CASE 3: Input: 
		Output: 0

*/