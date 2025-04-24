/* 
 * Программа для построения и преобразования дерева арифметического выражения
 * в префиксной форме с последующей оптимизацией поддеревьев с нулевыми результатами
 */
#include <iostream>
#include <fstream>
#include <memory>
#include "expression_tree.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Использование: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        return 1;
    }

    std::string expression;
    std::getline(file, file, expression);
    file.close();

    try {
        ExpressionTree tree;
        auto root = tree.buildFromPrefix(expression);
        
        if (!root) {
            std::cerr << "Ошибка построения дерева" << std::endl;
            return 1;
        }

        tree.optimizeZeroSubtrees(root);
        std::cout << "Указатель на корень дерева: " << root.get() << std::endl;
        
        // Дополнительный вывод для проверки
        std::cout << "Префиксный обход: ";
        tree.printPrefix(root.get());
        std::cout << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
