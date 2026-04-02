class Solution {
private:
    double ShortestPath(vector<vector<pair<int, double>>>& list, int start, int target, vector<pair<double, int>>& dis) {
        queue<int> adj;
        adj.push(start);
        while (!adj.empty()) {
            int top = adj.front();
            adj.pop();
            for (int i = 0; i < list[top].size(); i++) {
                if (dis[top].first*list[top][i].second > dis[list[top][i].first].first) {
                    dis[list[top][i].first].first = dis[top].first*list[top][i].second;
                    dis[list[top][i].first].second = top;
                    adj.push(list[top][i].first);
                }
            }
        }
        return dis[target].first;
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        if (edges.size() == 0) return 0;
        if (n == 2 && edges.size() != 0) return succProb[0];
        vector<vector<pair<int, double>>> list(n);
        vector<pair<double, int>> dis(n, {0.0, -1});
        dis[start_node].first = 1.0;
        dis[start_node].second = start_node;
        for (int i = 0; i < edges.size(); i++) {
            list[edges[i][0]].push_back({edges[i][1], succProb[i]});
            list[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        return ShortestPath(list, start_node, end_node, dis);
    }
};

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

let v be the number of vertices in the graph, e is the number of edges

Space complexity:
- list: stores data of the adjacency list of the graph -> O(e + v)
- dis: stores the maximum probability of any path to the current vertex -> O(v)
- adj: stores the adjacent vertices to the top element, at any time it can hold at most e - 1 elements -> O(e)
=> overall: O(e + v)

Time complexity:
- list initialization: requires the full edge list's traversal -> O(e)
- ShortestPath: examine the adj queue and perform a constant number of operation, since adj can store a maximum number of
elements of ~e, however each vertex can lead to another one and add in adj -> overall: O(e log v), worst case: O(e * v)
=> overall: O(e log v), worst case: O(e * v)


ALGORITHM EXPLAINATION

This is another form of the shortest path problem, but instead of total weight, we will calculate the multiply of weight; this
is because the more path we add, the less the probability be because it is always less than 1 so the multiple is less than the
original probability. So we will have to find: the path with the least edges and the multiple of the edges' weight is highest,
which is just the shortest path problem itself



TEST CASE

CASE 1: Input: n = 3, start_node = 0, end_node = 2
                {{1, 0.3, 0},
                {0.3, 1, 0.6},
                {0, 0.6, 1}} (3-isolated-vertices graph)
		Output: 0.18

CASE 2: Input: n = 2, start_node = 0, end_node = 1
                {{1, 0.54},
                {0.54, 1}} (dual-node connected graph)
		Output: 0.54

CASE 3: Input: n = 2, start_node = 0, end_node = 1
                {{1, 0},
                {0, 1}} (dual-node seperated graph)
		Output: 0
*/