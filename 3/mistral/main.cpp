/* Продолжение задания №Топологическая сортировка графа */

#include <iostream>
#include <fstream>
#include <vector>
#include "topological_sort.h"

int main() {
    std::string filename = "graph.txt";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return 1;
    }

    int n;
    file >> n;
    std::vector<std::vector<int>> adjMatrix(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> adjMatrix[i][j];
        }
    }
    file.close();

    try {
        std::vector<int> result = topologicalSort(adjMatrix);
        for (int vertex : result) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
