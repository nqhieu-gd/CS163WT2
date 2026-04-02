#include <iostream>
#include <queue>
#include "Dijkstra.h"

void dijkstra(int** graph, int n, int start, int target) {
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;
    std::vector<int> prev(n, -1);
    prev[start] = start;
    std::vector<double> dis(n, 99999.0);
    std::vector<bool> visited(n, false);
    dis[start] = 0.0;
    shortest_path(graph, n, start, target, pq, prev, dis, visited);
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

void shortest_path(int** graph, int n, int start, int target, std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>>& pq, std::vector<int>& prev, std::vector<double>& dis, std::vector<bool>& visited) {
    pq.push({0.0, start});
    while (!pq.empty()) {
        int top = pq.top().second;
        double curDis = pq.top().first;
        pq.pop();
        if(visited[top]) continue;
        visited[top] = true;
        if (top == target) {
            bool cont = false;
            displayPath(start, target, prev, cont);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (graph[top][i] > 0) if(!visited[i]) {
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

let v be the number of vertices in the graph, e is the number of edges

Space complexity:
- prev, dis and visited: O(v)
- pq stores all the adjacent nodes of the current examined node if a more optimal path is found, worst case every operation
results in a better path and push in all the adjacent node, meaning all the edges will be examined and the other end would
be saved once -> O(e)
- displayPath maximum recursion stack is v as there are no 2 same node on the shortest path -> O(v)
=> overall time: O(v), worst case: O(e)

Time complexity:
- prev, dis and visited initialization: O(v)
- shortest_path:
    + scanning the neighboring area of the current top element: O(v)
    + the algorithm locks the examined node up after processing, limiting the number of scanning to a maximum of v times
    -> O(v^2)
    + for each element in pq, push and pop are called once, each takes O(log v) -> O(e log v)
-> overall time complexity: O(v^2 + e log v)



ALGORITHM EXPLAINATION

a priority_queue is used to ensure that the current top is always the smallest one in terms of path. Assuming the graph's
weight is positive for all edges, then examine the larger one first will not lead to the shorter path because the weight will
only add up, hence the priority_queue (as min heap)

a visited vector is used to ensure that each node will be processed exactly once, because the pq ensure we will find the shortest
path to the current node, there is no use processing a node twice

a prev and a dis vector are used to store the node that leads to the current node and the total distance to the current node
respectively

we will add the starting node, examine all the possible node that it leads to, pop it back, then process the adjacent nodes,
examine all the possible path and save to the pq if that path is more optimized; repeat the progress until the target node
is processed because the remaining paths are just not shorter because of pq's logic



TEST CASE

CASE 1: Input: n = 3, start = 0, target = 2
                {{0, 5, 0},
                {5, 0, 0},
                {0, 0, 0}} (target and start aren't connected)
		Output: 

CASE 2: Input: n = 0
                {} (empty graph)
		Output: 

CASE 3: Input: n = 4, start = 2, target = 3
                {{0, 5, 0, 150},
                {5, 0, 4, 59},
                {0, 4, 0, 96},
                {150, 59, 96, 0}} (regular graph)
		Output: 2 -> 1 -> 3
*/