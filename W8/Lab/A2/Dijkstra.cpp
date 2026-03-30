#include <iostream>
#include <queue>
#include "Dijkstra.h"

void dijkstra(int** graph, int n, int start, int target) {
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;
    std::vector<int> prev(n, -1);
    prev[start] = start;
    std::vector<double> dis(n, 99999.0);
    dis[start] = 0.0;
    shortest_path(graph, n, start, target, pq, prev, dis);
}

void displayPath(int start, int target, std::vector<int>& prev, bool& cont) {
    if (prev[target] == -1) return;
    if (target == start) {
        std::cout << '[' << start << ']';
        cont = true;
        return;
    };
    displayPath(start, prev[target], prev, cont);
    if (cont) std::cout << " -> [" << target << ']';
}

void shortest_path(int** graph, int n, int start, int target, std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>>& pq, std::vector<int>& prev, std::vector<double>& dis) {
    pq.push({0.0, start});
    while (!pq.empty()) {
        int top = pq.top().second;
        double curDis = pq.top().first;
        pq.pop();
        if (top == target) {
            bool cont = false;
            displayPath(start, target, prev, cont);
        }
        for (int i = 0; i < n; i++) {
            if (graph[top][i] > 0) {
                if (curDis + graph[top][i] < dis[i]) {
                    dis[i] = curDis + graph[top][i];
                    prev[i] = top;
                    pq.push({dis[i], i});
                }
            }
        }
    }
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

let v be the number of vertices in a connected part of the graph, p is the number of
isolated connected parts in the graph

Space complexity:
- list (adjacency-matrix of the graph): the number of all the vertices in the graph is v*p
-> O((v*n)^2)
- components stores all the visited vertices of all parts -> O(v*p)
- ar (visited-edge list): O(v*p)
- vt stores a maximum of v - 1 vertices in a connected part at once -> O(v)

Time complexity:
- list: traverses the full list saved in the test file to input the graph -> O(v^2)
- bfsHelper traverses the full row of the current element to find and add the adjacent
vertices to the queue, then mark them as visited, repeat the process until all vertices
have been visited, however we still have to examine the full matrix as there may be multiple
isolated parts -> O((v*p)^2)



ALGORITHM EXPLAINATION

Starting from the root and record it, we will also record all of its neighboring vertices
to the queue and pop the root back, then we repeat the whole process until all the neighboring
vertices have been recorded. Then we search for remaining unvisted vertices, them being
unvisited means that they are in a different component, so we create a new container to store
them, then we repeat the aforementioned process, repeat until all the vertices have been
marked visited, that means the graph has been traversed.



TEST CASE

CASE 1: Input: n = 3;
                {{0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}} (3-isolated-vertices graph)
		Output: 3
                1
                2
                3

CASE 2: Input: n = 0
                {} (empty graph)
		Output: 

CASE 3: Input: n = 1
                {{0}} (single-node graph)
		Output: 1
                1
*/