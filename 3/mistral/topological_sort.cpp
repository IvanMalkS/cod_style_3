/* Продолжение задания №Топологическая сортировка графа */

#include "topological_sort.h"
#include <stdexcept>
#include <algorithm>
#include <stack>

void dfs(int v, const std::vector<std::vector<int>>& adjMatrix, std::vector<bool>& visited, std::vector<int>& tempMark, std::stack<int>& Stack) {
    visited[v] = true;
    tempMark[v] = 1;

    for (int i = 0; i < adjMatrix[v].size(); ++i) {
        if (adjMatrix[v][i] != 0) {
            if (!visited[i]) {
                dfs(i, adjMatrix, visited, tempMark, Stack);
            } else if (tempMark[i] == 1) {
                throw std::runtime_error("No solution");
            }
        }
    }

    tempMark[v] = 2;
    Stack.push(v);
}

std::vector<int> topologicalSort(const std::vector<std::vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    std::vector<bool> visited(n, false);
    std::vector<int> tempMark(n, 0);
    std::stack<int> Stack;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adjMatrix, visited, tempMark, Stack);
        }
    }

    std::vector<int> result;
    while (!Stack.empty()) {
        result.push_back(Stack.top());
        Stack.pop();
    }

    std::reverse(result.begin(), result.end());
    std::sort(result.begin(), result.end(), std::greater<int>());

    return result;
}
