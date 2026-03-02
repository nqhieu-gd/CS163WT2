#include <iostream>
#include <vector>
#include <iomanip>

float minDis(int n, int l, std::vector<int>& list) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) if (list[j] > list[j + 1]) {
            int sub = list[j];
            list[j] = list[j + 1];
            list[j + 1] = sub;
        }
    }
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

Space complexity: vector storage is the number of lanterns
-> O(n) space

Time complexity:
- bubble sort: O(n^2)
- each pair of adjacent location is examined once, plus the outer range, for a total of n + 1 examinations -> O(n)
=> O(n^2) time
*/

/*
ALGORITHM EXPLAINATION

Firstly, the container (vector in this case) is sorted, then 
*/

/*
TEST CASE

CASE 1: Input: 10
		Output: 10

CSAE 2: Input: 2, 5, 1
		Output:       2
                     /  \
                    1    5

CASE 3: Input: 1, 2, 5, 0, 4, 3, 6
		Output:          1
                        / \
                       5   2
                      / \  / \
                     6   3 4  0

*/