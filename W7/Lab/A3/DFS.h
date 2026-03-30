#pragma once

int** list();

void dfsHelper(int** list, int n, int idx, int* ar, std::ofstream& fout);

void dfs(int** list, int n);