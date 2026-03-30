#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include "ConnectedComponents.h"

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

void bfsHelper(int** list, int* ar, int idx, int n, std::vector<int>& cpn) {
    ar[idx] = 1;
    std::queue<int> vt;
    vt.push(idx);
    while (!vt.empty()) {
        cpn.push_back(vt.front());
        for (int i = 0; i < n; i++) {
            if (ar[i] == 0 && list[vt.front()][i] == 1) {
                vt.push(i);
                ar[i] = 1;
            }
        }
        vt.pop();
    }
}

void ConnectedComponents(int** list, int n) {
    std::ofstream fout;
    fout.open("ConnectedComponents.txt");
    if (!fout.is_open()) {
        std::cerr << "Can not open the destination file.";
        return;
    }
    std::vector<std::vector<int>> components;
    int* ar = new int[n];
    for (int i = 0; i < n; i++) ar[i] = 0;
    for (int i = 0; i < n; i++) {
        if (ar[i] == 0) {
            std::vector<int> li;
            bfsHelper(list, ar, i, n, li);
            components.push_back(li);
        }
    }
    delete[] ar;
    fout << components.size() << '\n';
    for (int i = 0; i < components.size(); i++) {
        for (int j = 0; j < components[i].size(); j++) {
            fout << components[i][j] + 1 << ' ';
        }
        fout << '\n';
    }
    fout.close();
}

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