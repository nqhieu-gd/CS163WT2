#pragma once

int** list();

void bfsHelper(int** list, int* ar, int idx, int n, std::ofstream& fout);

void bfs(int** list, int n);