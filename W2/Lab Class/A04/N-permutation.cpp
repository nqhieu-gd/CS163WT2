#include "N-Permutation.h"

std::vector<std::vector<int>> Permutation(int n) {
    std::vector<std::vector<int> > result;
    std::vector<int> nums;
    for (int i = 1; i <= n; i++) nums.push_back(i);
	    
    Recurse(nums, 0, result);
    return result;
}

void Recurse(std::vector<int>& nums, int begin, std::vector<std::vector<int>>& result) {
    if (begin >= nums.size()) {
        result.push_back(nums);
        return;
    }

    Recurse(nums, begin + 1, result);

    for (int i = begin + 1; i < nums.size(); i++) {
        std::swap(nums[begin], nums[i]);
        Recurse(nums, begin + 1, result);
        std::swap(nums[begin], nums[i]);
    }
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n be the number of numbers in a designated permutation

Space complexity: maximum recursion depth is n, there are n! permutation to push to the vector
-> O(n!*n) space

Time complexity: swapPoint starting from begin = 0, up until n – 1, each operation, there is a loop
of n - swapPoint times, so the total operation is 1*2*3...*n = n!, then copy the exact same permutation to vector cost O(n) time
-> O(n!*n) time
*/

/*
ALGORITHM EXPLAINATION

Firstly, nums is an initial permutation of n, meaning [1,2,3,...,n]

The main function of this code is the Recurse function, it will swap the current swapPoint with every number after it to create
a different combination, which is a new permutation; inside it is a loop to increase the current swapPoint indirectly and recursively
call the Recurse function. As swapPoint is increasingly increased, the stopping condition would be when swapPoint >= nums.size(),
which is the bound of the combination. So every combination would be traversed at least once, hence all the possible permutations.
*/

/*
TEST CASE

CASE 1: Input: 3
		Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

CSAE 2: Input: 4
        Output: [[1,2,3,4], [1,2,4,3], [1,3,2,4], [1,3,4,2], [1,4,3,2], [1,4,2,3], [2,1,3,4], [2,1,4,3], [2,3,1,4], [2,3,4,1], [2,4,3,1], [2,4,1,3], [3,2,1,4], [3,2,4,1], [3,1,2,4], [3,1,4,2], [3,4,1,2], [3,4,2,1], [4,2,3,1], [4,2,1,3], [4,3,2,1], [4,3,1,2], [4,1,3,2], [4,1,2,3]]

CASE 3: Input: 2
		Output: [[1,2],[2,1]]

*/