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