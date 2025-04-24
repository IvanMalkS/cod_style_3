/* Продолжение задания №TopologicalSort */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

using namespace std;

class Graph {
public:
	explicit Graph(int n);

	// Загрузка графа из файла
	bool LoadFromFile(const string& filename);

	// Выполнить топологическую сортировку
	// Возвращает true, если сортировка возможна, false — если есть цикл
	bool TopologicalSort(vector<int>& order);

private:
	int n_;  // число вершин
	vector<vector<int>> adj_;  // матрица смежности

	// Вспомогательные функции для DFS
	enum class Color { WHITE, GRAY, BLACK };

	bool Dfs(int v, vector<Color>& colors, vector<int>& order);
};

#endif  // GRAPH_H
