#include <iostream>
#include <vector>
#include <iomanip>

bool isSafe(int x, int y, int n, const std::vector<std::vector<int>>& board);

bool Recurse(int x, int y, int moveIdx, int n, std::vector<std::vector<int>>& board, int xMove[], int yMove[]);

void KnightTour(int n);