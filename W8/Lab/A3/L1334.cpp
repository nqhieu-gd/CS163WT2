class Solution {
private:
    void updateDis(vector<vector<int>>& dis, int n) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < n; i++) {
                    if (dis[i][k] != 20001 && dis[j][k] != 20001 && dis[i][k] + dis[j][k] < dis[i][j]) {
                        dis[i][j] = dis[i][k] + dis[j][k];
                        dis[j][i] = dis[i][j];
                    }
                }
            }
        }
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int>(n, 20001));
        for (int i = 0; i < edges.size(); i++) {
            dis[edges[i][0]][edges[i][1]] = edges[i][2];
            dis[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for (int i = 0; i < n; i++) {
            dis[i][i] = 0;
        }
        updateDis(dis, n);
        int min = n, res = -1;
        for (int i = 0; i < n; i++) {
            int num = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dis[i][j] <= distanceThreshold) {
                    num++;
                }
            }
            if (num <= min) {
                min = num;
                res = i;
            }
        }
        return res;
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

let v be the number of vertices in the graph, e is the number of edges

Space complexity: dis store the shortest distance between 2 nodes -> O(v^2)

Time complexity:
- updateDis: apply the Floyd-Warshall algorithm and update the Dis container, it traverse the whole list of vertices (as intermidiate
vertice) and the whole adjacency-matrix of the graph to do so -> O(v^3)
- findTheCity calls updateDis once, then process the whole dis list to perform the calculating operation -> O(v^3 + v^2)
=> overall: O(v^3)



ALGORITHM EXPLAINATION

We construct a distance matrix based on the Floyd-Warshall's algorithm, then we determine how many city that is shorter than
the distanceThreshold to the current processed city, if that number is smaller than the current saved city's number of neighboring
cities that is shorter to get to than the distanceThreshold, replace it; if no such city is found, return -1 instead



TEST CASE

CASE 1: Input: n = 3, distanceThreshold = 3
                {{0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}} (3-isolated-vertices graph)
		Output: -1

CASE 2: Input: n = 2, distanceThreshold = 6
                {{0, 1},
                {1, 0}} (2-city system)
		Output: 0

CASE 3: Input: n = 4, distanceThreshold = 60
                {{0, 5, 0, 150},
                {5, 0, 4, 59},
                {0, 4, 0, 96},
                {150, 59, 96, 0}} (regular graph)
		Output: 0 (0 and 2 are both viable, but 0 is lower in index)
*/