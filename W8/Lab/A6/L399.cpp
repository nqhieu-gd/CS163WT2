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

let e be the number of equations, q be the number of queries, l be the average length of all variables, n be the number of
variables

Space complexity:
- list: list stores up to n variables of length l each and sum up to total of e quations -> O(e * l)
- visited: store data of all variables to check whether they have been visited -> O(n * l)
- calc: maximum recursio depth is the maximum number of elements -> O(n)
- res: stores the result for each query -> O(q)
=> overall: O((n + e) * l + q)

Time complexity:
- list initialization: iterate the entire e equations and push all variables, each takes O(l) -> O(e * l)
- calc: worst case calc will call itself from the first variable to the last variable, and execute find() or insert()
-> O((e + n) * l)
- calcEquation: calls calc for each query -> O((e + n) * l * q)
=> overall: O(((e + n) * q + e) * l)



ALGORITHM EXPLAINATION

this is a path finder problem, if we need to find a/d and we already have a/b, b/c and c/d, then a/d is simply a/b * b/c * c/d

if we have a/b, then b/a = 1/(a/b), so we say a and b are connected as they are related and they have a weighted connected
path

we build a graph based on that logic, and use the basic dfs utility, we find a/d (example) by traversing the graph from a, find
a possible path that leads to d, and multiply the weight



TEST CASE

CASE 1: Input: e = [["a", "b"], ["b", "c"], ["c", "d"]]
               v = [2, 3, 4]
               q = [["a", "d"]]
		Output: r = [24]

CASE 2: Input: e = [["a", "b"], ["b", "c"], ["c", "d"]]
               v = [2, 3, 4]
               q = [["a", "x"]]
		Output: r = [-1]

CASE 3: Input: e = [["a", "b"], ["b", "c"], ["c", "d"]]
               v = [2, 3, 4]
               q = [["x", "x"]]
		Output: r = [1]
*/