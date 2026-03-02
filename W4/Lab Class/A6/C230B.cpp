#include <iostream>
#include <vector>

void TPrime(int n) {
    int i = 1;
    while (++i) {
        if (i*i == n) {
            break;
        }
        else if (i*i > n) {
            std::cout << "NO\n";
            return;
        }
    }
    n = 1;
    while (++n) {
        if (n*n > i) break;
        else if (i % n == 0) {
            std::cout << "NO\n";
            return;
        }else if (n == i) {
            std::cout << "YES\n";
            return;
        }
    }
}

int main() {
    int n;
    std::vector<int> li;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        li.push_back(0);
        std::cin >> li[i];
    }
    for (int i = 0; i < n; i++) {
        TPrime(li[i]);
    }
    return 0;
}