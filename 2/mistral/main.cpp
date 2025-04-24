/* Продолжение задания №CalcTree8 */

#include <iostream>
#include <fstream>
#include <string>
#include "expression_tree.h"

int main() {
    std::string filename = "expression.txt";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return 1;
    }

    std::string expression;
    std::getline(file, expression);
    file.close();

    try {
        ExpressionTree tree(expression);
        tree.simplify();
        std::cout << "Указатель на корень дерева: " << tree.getRoot() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
