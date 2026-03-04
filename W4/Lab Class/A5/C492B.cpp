#include <iostream>
#include <vector>
#include <iomanip>

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

float minDis(int n, int l, std::vector<int>& list) {
    MSort(list, 0, n - 1);
    float subs = list[0];
    for (int i = 1; i < n; i++) {
        float k = (float) (list[i] - list[i - 1])/2;
        subs = (subs > k)? subs : k;
    }
    l = (l - list[n - 1]);
    subs = (subs > l)? subs : l;
    return (float) subs;
}

int main() {
    int n, l;
    std::cin >> n >> l;
    std::vector<int> list;
    for (int i = 0; i < n; i++) {
        list.push_back(0);
        std::cin >> list[i];
    }
    std::cout << std::fixed << std::setprecision(10) << minDis(n, l, list);

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
- merege sort: O(n)
- each pair of adjacent location is examined once, plus the outer range, for a total of n + 1 examinations -> O(n)
=> O(n) time
*/

/*
ALGORITHM EXPLAINATION

Firstly, the container (vector in this case) is sorted, then we examine each pair of adjacent location to find the
largest distance. If the largest distance is bigger than 2 times the distance of the first lantern and starting point
and of the last lantern and the last point of the road, then the radius of the lighting area is half of it, that way
every area of the road is covered. Otherwise, the minimum radius must be the higher between the distance of the first
lantern to the starting point and the distance of the last lantern and the last point to cover the whole road (every
other point is covered to since the distance is smaller).
*/

/*
TEST CASE

CASE 1: Input: 2, 5,
               4, 3
		Output: 3

CSAE 2: Input: 5, 12
               2, 5, 0, 4, 3
		Output:7

CASE 3: Input: 6, 18
               0, 13, 15, 18, 3, 5
		Output: 4
*/