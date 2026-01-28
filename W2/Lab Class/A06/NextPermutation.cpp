#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 2;
        if(n <= -1) return;
        if(!nextPermFunc(nums, n)) {
            sort(nums.begin(), nums.end());
        }
    }

    bool nextPermFunc(vector<int>& nums, int cur) {
        if(cur < 0) return false;

        if(nums[cur] < nums[cur + 1]) {
            int sub = nums.size() - 1;
            while(nums[sub] <= nums[cur]) {
                sub--;
            }
            swap(nums[cur], nums[sub]);
            sort(nums.begin() + cur + 1, nums.end());
            return true;
        }

        return nextPermFunc(nums, cur - 1);
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Let n is the size of nums, meaning the number of numbers in a designated permutation

Space complexity: maximum recursion depth is n, the sort function uses O(log(n)) space, but they are independant
-> O(n) space

Time complexity:
- return nextPermFunc(nums, cur - 1); -> worst case, this runs from n - 2 up until 0 -> O(n) time
- while(nums[sub] <= nums[cur])... -> worst case, this runs from cur up until 0 -> O(n) time
- sort(nums.begin() + cur + 1, nums.end()); -> O(n*log(n)) time
- sort(nums.begin(), nums.end()); -> O(n*log(n)) time, only when there is no possible permutation higher
Those function are independant -> O(n*log(n)) time
*/

/*
ALGORITHM EXPLAINATION

The main function of this code is the NextPermFunc function, it will start from right to the left of the right-most side,
then move leftward until it find a possible increment location, which is where nums[cur] < nums[cur + 1] (otherwise if we swap 2
elements, it will become less, which is not what the "next permutation" is), then swap the current location with the once to the
right of it, and swap the whole sub array starting from its right up until the last element. The swapping is neccessary to get
the exact "next permutation". The NextPermFunc function return false only when the current permutation is the highest possible one,
then the "next permutation" would be the lowest permutation possible, hence the sort function.
*/

/*
TEST CASE

CASE 1: Input: nums = [1,2,3]
		Output: [1,3,2]

CSAE 2: Input: nums = [1,2,5]
		Output: [1,5,2]

CASE 3: Input: nums = [0,4,3]
		Output: [3,0,4]

*/