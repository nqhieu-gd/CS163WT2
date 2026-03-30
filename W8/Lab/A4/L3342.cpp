class Solution {
private:
    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int SP(vector<vector<int>>& moveTime, int m, int n) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> dis(n, vector<int> (m, INT_MAX));
        dis[0][0] = 0;
        while (!pq.empty()) {
            int topTime = pq.top().first;
            int topCol = pq.top().second.first;
            int topRow = pq.top().second.second;
            pq.pop();
            if (topCol == m - 1 && topRow == n - 1) return topTime;
            if (topTime > dis[topRow][topCol]) continue;
            for (int i = 0; i < 4; i++) {
                int subCol = topCol + moves[i].first;
                int subRow = topRow + moves[i].second;
                if (subCol >= 0 && subCol < m && subRow >= 0 && subRow < n) {
                    int subTime = max(moveTime[subRow][subCol], topTime) + 1 + (subRow + subCol + 1)%2;
                    if (subTime < dis[subRow][subCol]) {
                        dis[subRow][subCol] = subTime;
                        pq.push({subTime, {subCol, subRow}});
                    }
                }
            }
        }
        return -1;
    }
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        return SP(moveTime, m, n);
    }
};

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