#pragma once
#include <iostream>
#include <vector>

std::vector<std::vector<int>> Permutation(int n);

void Recurse(std::vector<int>& nums, int begin, std::vector<std::vector<int>>& result);