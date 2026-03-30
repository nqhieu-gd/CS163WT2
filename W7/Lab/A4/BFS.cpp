#include <iostream>
#include <queue>
#include <fstream>
#include "BFS.h"

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

void bfsHelper(int** list, int* ar, int idx, int n, std::ofstream& fout) {
    std::queue<int> vt;
    vt.push(idx);
    ar[idx] = 1;
    while (!vt.empty()) {
        fout << vt.front() + 1 << ' ';
        for (int i = 0; i < n; i++) {
            if (ar[i] == 0 && list[vt.front()][i] == 1) {
                vt.push(i);
                ar[i] = 1;
            }
        }
        vt.pop();
    }
}

void bfs(int** list, int n) {
    std::ofstream fout;
    fout.open("BFSVertexList.txt");
    if (!fout.is_open()) {
        std::cerr << "Can not open the destination file.";
        return;
    }
    int* ar = new int[n];
    for (int i = 0; i < n; i++) ar[i] = 0;
    for (int i = 0; i < n; i++) {
        if (ar[i] == 0) bfsHelper(list, ar, i, n, fout);
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
- vt: vt stores a maximum of v - 1 vertices at once -> O(v)

Time complexity:
- list: traverses the full list saved in the test file to input the graph -> O(v^2)
- bfsHelper traverses the full row of the current element to find and add the adjacent
vertices to the queue, then mark them as visited, repeat the process until all vertices
have been visited, however we still have to examine the full matrix as there may be multiple
isolated parts -> O(v^2)



ALGORITHM EXPLAINATION

Starting from the root and record it, we will also record all of its neighboring vertices
to the queue and pop the root back, then we repeat the whole process until all the neighboring
vertices have been recorded. Then we search for remaining unvisted vertices, them being
unvisited means that they are in a different component, so we create a new container to store
them, then we repeat the aforementioned process, repeat until all the vertices have been
marked visited, that means the graph has been traversed.



TEST CASE

CASE 1: Input: n = 3;
                {{0, 1, 0},
                {1, 0, 1},
                {0, 1, 0}} (regular straight graph)
		Output: 1 2 3

CASE 2: Input: n = 0
                {} (empty graph)
		Output: 

CASE 3: Input: n = 1
                {{0}} (single-node graph)
		Output: 1
*/