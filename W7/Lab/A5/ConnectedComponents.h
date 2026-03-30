#pragma once

int** list();

void bfsHelper(int** list, int* ar, int idx, int n, std::vector<int>& cpn);

void ConnectedComponents(int** list, int n);