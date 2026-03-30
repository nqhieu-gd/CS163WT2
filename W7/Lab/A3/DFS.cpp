#include <iostream>
#include <fstream>
#include "DFS.h"

int** list() {
    std::ifstream fin;
    fin.open("Graph.txt");
    if (!fin.is_open()) {
        std::cerr << "Error opening the input file.";
        return nullptr;
    }
    int n = 0;
    fin >> n;
    int** li = new int*[n];
    for (int i = 0; i < n; i++) {
        li[i] = new int[n];
        for (int j = 0; j < n; j++) {
            fin >> li[i][j];
        }
    }
    fin.close();
    return li;
}

void dfsHelper(int** list, int n, int idx, int* ar, std::ofstream& fout) {
    ar[idx] = 1;
    fout << idx + 1 << ' ';

    for (int i = 0; i < n; i++) {
        if (ar[i] == 0 && list[idx][i] == 1) dfsHelper(list, n, i, ar, fout);
    }
}

void dfs(int** list, int n) {
    std::ofstream fout;
    fout.open("DFSVertexList.txt");
    if (!fout.is_open()) {
        std::cerr << "Can not open the destination file.";
        return;
    }
    int* ar = new int[n];
    for (int i = 0; i < n; i++) ar[i] = 0;
    for (int i = 0; i < n; i++) {
        if (ar[i] == 0) dfsHelper(list, n, i, ar, fout);
    }
    delete[] ar;
    fout.close();
}

//Nguyen Quang Hieu - 25125043

/*
TIME - SPACE COMPLEXITY

let v be the number of vertices in the graph

Space complexity:
- list (adjacency-matrix of the graph): O(v^2)
- ar (visited-edge list): O(v)
- dfsHelper: maximum recursion stack is v (it can not go deeper once all the vertices have
been marked visited) -> O(v)

Time complexity:
- list: traverses the full list saved in the test file to input the graph -> O(v^2)
- dfsHelper traverses the full row of the current element to find the connected edge, and
then do the same with those connected edge, meaning each vertex is visited once, but still
check all "possible" neighbor in the matrix -> O(v^2)



ALGORITHM EXPLAINATION

Starting from the root and record it, we will go to the neighboring vertices, each time we
will repeat the process and record that vertex, when we've reached the end, we traced back on the
path to the original branched vertex (can be the root or any vertex on the path to the current
vertex that is branched to several different path). Repeat the process until all branches have
been traced.



TEST CASE

CASE 1: Input: n = 3;
                {{0, 1, 0},
                {1, 0, 1},
                {0, 1, 0}} (straight graph)
		Output: 1 2 3

CASE 2: Input: n = 0
                {} (empty graph)
		Output: 

CASE 3: Input: n = 1
                {{0}} (single-node graph)
		Output: 1
*/