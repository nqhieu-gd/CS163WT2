#include <iostream>
#include <climits>

void dijkstra(int** g, int n, int start, int target) {
    int* dis = new int[n];
    int* prev = new int[n];
    for (int i = 0; i < n; i++) {
        if (i != start - 1) dis[i] = INT_MAX;
        prev[i] = n;
    }
    dis[start - 1] = 0;
    dijkstraSub(start, g, n, dis, prev);
    if (prev[target - 1] == n) {
        std::cerr << "No path found.";
    }
    else {
        std:: cout << "The shorted path is " << dis[target - 1] << " in length: ";
        tracing(dis, prev, start, target);
    }
    delete[] dis;
    delete[] prev;
}

void dijkstraSub(int start, int** g, int n, int*& dis, int*& prev) {
    for (int i = 0; i < n; i++) {
        if (g[start - 1][i] > 0 && dis[start - 1] + g[start - 1][i] < dis[i]) {
            dis[i] = dis[start - 1] + g[start - 1][i];
            prev[i] = start - 1;
            dijkstraSub(i + 1, g, n, dis, prev);
        }
    }
}

void tracing(int*& dis, int*& prev, int start, int target) {
    if (target == start) {
        std::cout << start;
        return;
    }
    tracing(dis, prev, start, prev[target - 1] + 1);

    std::cout << " -> " << target;
}