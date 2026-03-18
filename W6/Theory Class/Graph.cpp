#include <iostream>

bool isConnected(int** a, int n) {
    int* p = new int[n];
    p[0] = 1;
    int count = 1;
    for (int i = 1; i < n; i++) p[i] = 0;
    for (int i = 1; i < n; i++) if (!p[i]) return false;
    return true;
}

