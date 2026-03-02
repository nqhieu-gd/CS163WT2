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