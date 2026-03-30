#include <iostream>
#include <climits>

void dijkstra(int** g, int n, int start, int target);

void dijkstraSub(int start, int** g, int n, int*& dis, int*& prev);

void tracing(int*& dis, int*& prev, int start, int target);