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

let v be the number of vertices in the graph, e is the number of edges

Space complexity:
- dis store the time needed to traval from (0, 0) to (x, y) -> O(m * n)
- pq store the current adjacent rooms needed to process, worst case it will store almost the full edges list at once -> O(m * n + m + n)
=> overall: O(m * n)

Time complexity: SP



ALGORITHM EXPLAINATION

We use graph theory's way to solve this, 2 adjacent rooms are rooms that share a same wall, this model will become a graph
of m * n vertices and (m - 1)*(n - 1) edges, we use regular shortest path algorithm to solve this problem



TEST CASE

CASE 1: Input: m = 4, n = 3
                {{0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}} (all instant room)
		Output: 7

CASE 2: Input: m = 1, n = 1
                {{0}} (one-room only)
		Output: 0

CASE 3: Input: m = 4, n = 4
                {{0, 3, 0, 150},
                {5, 2, 7, 59},
                {1, 4, 81, 96},
                {14, 9, 36, 0}} (regular graph)
		Output: 39
*/