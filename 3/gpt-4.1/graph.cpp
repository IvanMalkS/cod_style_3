/* Продолжение задания №TopologicalSort */

#include "graph.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Graph::Graph(int n) : n_(n), adj_(n, vector<int>(n, 0)) {}

bool Graph::LoadFromFile(const string& filename) {
	ifstream fin(filename);
	if (!fin) {
		cerr << "Ошибка открытия файла " << filename << "\n";
		return false;
	}

	fin >> n_;
	adj_.assign(n_, vector<int>(n_, 0));

	for (int i = 0; i < n_; ++i) {
		for (int j = 0; j < n_; ++j) {
			fin >> adj_[i][j];
		}
	}

	return true;
}

bool Graph::Dfs(int v, vector<Color>& colors, vector<int>& order) {
	colors[v] = Color::GRAY;

	// Перебираем соседей в порядке убывания номера
	for (int u = n_ - 1; u >= 0; --u) {
		if (adj_[v][u] != 0) {
			if (colors[u] == Color::GRAY) {
				// Найден цикл
				return false;
			}
			if (colors[u] == Color::WHITE) {
				if (!Dfs(u, colors, order)) {
					return false;
				}
			}
		}
	}

	colors[v] = Color::BLACK;
	order.push_back(v + 1);  // +1 для номеров вершин с 1
	return true;
}

bool Graph::TopologicalSort(vector<int>& order) {
	order.clear();
	vector<Color> colors(n_, Color::WHITE);

	for (int v = n_ - 1; v >= 0; --v) {
		if (colors[v] == Color::WHITE) {
			if (!Dfs(v, colors, order)) {
				return false;
			}
		}
	}

	// Порядок получен в обратном порядке DFS, перевернём
	reverse(order.begin(), order.end());
	return true;
}
