/* Продолжение задания №TopologicalSort */

#include <iostream>
#include "graph.h"

using namespace std;

int main() {
	const string filename = "FileName";

	Graph graph(0);
	if (!graph.LoadFromFile(filename)) {
		return 1;
	}

	vector<int> topoOrder;
	if (!graph.TopologicalSort(topoOrder)) {
		cout << "No solution" << endl;
		return 0;
	}

	for (size_t i = 0; i < topoOrder.size(); ++i) {
		cout << topoOrder[i];
		if (i + 1 != topoOrder.size()) {
			cout << " ";
		}
	}
	cout << endl;

	return 0;
}
