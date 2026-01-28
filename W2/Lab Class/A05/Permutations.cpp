#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int begin = 0;

    vector<vector<int>> permute(vector<int>& nums) {
	    vector<vector<int> > result;
	    
	    Recurse(nums, begin, result);
	    return result;
    }
    
	void Recurse(vector<int> &nums, int swapPoint, vector<vector<int> > &result)	{
		if (swapPoint >= nums.size()) {
		    result.push_back(nums);
		    return;
		}

        Recurse(nums, swapPoint + 1, result);

		for (int i = swapPoint + 1; i < nums.size(); i++) {
		    swap(nums[swapPoint], nums[i]);
		    Recurse(nums, swapPoint + 1, result);
		    swap(nums[swapPoint], nums[i]);
		}
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n is the size of nums, meaning the number of numbers in a designated permutation

Space complexity: maximum recursion depth is n, there are n! permutation to push to the vector
-> O(n!*n) space

Time complexity: swapPoint starting from begin = 0, up until n – 1, each operation, there is a loop
of n - swapPoint times, so the total operation is 1*2*3...*n = n!, then copy the exact same permutation to vector cost O(n) time
-> O(n!*n) time
*/

/*
ALGORITHM EXPLAINATION

The main function of this code is the Recurse function, it will swap the current swapPoint with every number after it to create
a different combination, which is a new permutation; inside it is a loop to increase the current swapPoint indirectly and recursively
call the Recurse function. As swapPoint is increasingly increased, the stopping condition would be when swapPoint >= nums.size(),
which is the bound of the combination. So every combination would be traversed at least once, hence all the possible permutations.
*/

/*
TEST CASE

CASE 1: Input: nums = [1,2,3]
		Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

CSAE 2: Input: nums = [1,2,5]
		Output: [[1,2,5],[1,5,2],[2,1,5],[2,5,1],[5,1,2],[5,2,1]]

CASE 3: Input: nums = [0,4,3]
		Output: [[0,4,3],[0,3,4],[4,0,3],[4,3,0],[3,4,0],[3,0,4]]

*/