#pragma once

void dijkstra(int** graph, int n, int start, int target);

void displayPath(int start, int target, std::vector<int>& prev, bool& cont);

void shortest_path(int** graph, int n, int start, int target, std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>>& pq, std::vector<int>& prev, std::vector<double>& dis);