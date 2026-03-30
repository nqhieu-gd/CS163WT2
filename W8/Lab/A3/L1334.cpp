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