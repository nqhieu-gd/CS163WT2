#include <iostream>

long long fac(int n) {
    if (n == 2) return n;
    return fac(n - 1)*n;
}

void perm(int n, int* ar, int s) {
    for (int i = n - 1; i >= s; i--) {
        ar[i + 1] == ar[i];
    }
    ar[s] == n;
}

void permOut(int n, int* ar, int s) {
    perm(n, ar, s);
    for (int i = 0; i < n; i++) std::cout << ar[i] << " ";
    std::cout << '\n';
}

void perm(int n, int* ar) {
    
}

void perms(int n) {
    int* ar = new int[n];
}