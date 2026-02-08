class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> rev;
        int k = word.size(), j = 0;
        for (int i = 0; i < k; i++) {
            rev.push(word[i]);
            if (word[i] == ch) {
                break;
            }
            if (i == k - 1) return word;
        }
        while (!rev.empty()) {
            word[j++] = rev.top();
            rev.pop();
        }
        return word;
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let h be the size of the prefix and n be the size of word

Space complexity:  stack size: h -> O(h), worst case it is O(n)

Time complexity: 
- The for loop runs until it meets the predesignated character or until it meets the last character of "word" -> O(h), worst
case it is O(n)
- The while loop traverse the whole stack, each element is visited once -> O(h), worst case it is O(n)
=> Total time complexity: O(h), worst case it is O(n)
*/

/*
ALGORITHM EXPLAINATION

The for loop traverse word until it gets pass the last character or the current character is the predesignated one, either
case, it add all the character until that time to a local stack rev. If no character in "Word" is the given character, do
nothing, else replace the prefix by calling the stack, as stack serve the LIFO principle, the result is that the prefix has
been reversed
*/

/*
TEST CASE

CASE 1: Input: 25125043 0 
		Output: 52152043

CSAE 2: Input: nqhieu h
		Output: qnhieu

CASE 3: Input: APCS d
		Output: APCS
*/