/* Продолжение задания №CalcTree8 */

#include <iostream>
#include <fstream>
#include "calctree.h"

using namespace std;

int main() {
	const char* filename = "filename";

	ifstream fin(filename);
	if (!fin) {
		cerr << "Ошибка открытия файла " << filename << "\n";
		return 1;
	}

	string expr;
	getline(fin, expr);
	fin.close();

	try {
		TokenReader reader(expr);
		auto root = BuildTree(reader);

		EvaluateAndTransform(root);

		cout << "Root pointer: " << root.get() << "\n";

		// Для отладки: распечатать дерево
		// PrintTree(root);

	} catch (const exception& ex) {
		cerr << "Ошибка: " << ex.what() << "\n";
		return 1;
	}

	return 0;
}
