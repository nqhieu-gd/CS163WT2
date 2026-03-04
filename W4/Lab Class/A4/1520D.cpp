#include <iostream>
#include <vector>

void MSort(std::vector<int>& vt, int beg, int end) {
    if (beg >= end) return;
    int mid = (beg + end)/2;
    MSort(vt, beg, mid);
    MSort(vt, mid + 1, end);
    std::vector<int> temp;
    int left = beg, right = mid + 1;

    while (left <= mid && right <= end) {
        if (vt[left] <= vt[right]) temp.push_back(vt[left++]);
        else temp.push_back(vt[right++]);
    }

    while (left <= mid) temp.push_back(vt[left++]);
    while (right <= end) temp.push_back(vt[right++]);

    for (int i = 0; i < temp.size(); i++) {
        vt[beg + i] = temp[i];
    }
}

int main() {
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        
        std::vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            int a;
            std::cin >> a;
            diff[i] = a - i;
        }
        MSort(diff, 0, n - 1);
        long long ans = 0, cnt = 1;
        for (int i = 1; i < n; i++) {
            if (diff[i] == diff[i-1]) {
                cnt++;
            } else {
                ans += cnt * (cnt - 1) / 2;
                cnt = 1;
            }
        }
        ans += cnt * (cnt - 1) / 2;
        
        std::cout << ans << "\n";
    }
    return 0;
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

Space complexity:
- vector storage is the number of lanterns -> O(n) space
- temp vector for merge sort -> O(n) space
=> O(n) space

Time complexity:
- merge sort: O(n)
- every number needs to be renumbered once -> O(n)
- the whole number list needs to be traversed to get the number of similar value -> O(n)
the process repeat t times => O(tn) time
*/

/*
ALGORITHM EXPLAINATION

a_i - a_j = i - j <=> a_i - i = a_j - j

Let b_i = a_i - i, we replace a_i with b_i correspondingly, now what we need to do is to find how many
pairs of number that have the same value.
The first step after inputing and renumbering the values is to sort the values, we will then check the
adjacent numbers if they have similar value, and for each n numbers that have the same value, the number
of number pairs we can get from them is (n - 1)*n/2. By repeating the process until the very end, we get
the correct answer.
*/

/*
TEST CASE

CASE 1: Input: 2
               5
               1 25 0 4 3
               3
               4 0 5
		Output: 2
                0

CASE 2: Input: 3
               4
               0 5 21 52
               5
               2 5 1250 4 3
               1
               52 (1 input leads to 0 pairs)
		Output: 0
                0
                0

CASE 3: Input: 0 (no input leads to no output)
		Output:
*/