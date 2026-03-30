class Solution {
private:
    double calc(unordered_map<string, vector<pair<string, double>>>& list, unordered_set<string>& visited, string& query1, string& query2) {
        if (query1 == query2) return 1.0;
        visited.insert(query1);
        for (int i = 0; i < list[query1].size(); i++) {
            if (visited.find(list[query1][i].first) == visited.end()) {
                double res = calc(list, visited, list[query1][i].first, query2);
                if (res != -1.0) return res*list[query1][i].second;
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        unordered_map<string, vector<pair<string, double>>> list;
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            list[a].push_back({b, values[i]});
            list[b].push_back({a, 1.0/values[i]});
        }
        for (int i = 0; i < queries.size(); i++) {
            string a = queries[i][0];
            string b = queries[i][1];
            if (list.find(a) != list.end() && list.find(b) != list.end()) {
                unordered_set<string> visited;
                res.push_back(calc(list, visited, a, b));
            }
            else if (a == b && list.find(a) != list.end()) res.push_back(1.0);
            else res.push_back(-1.0);
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