/* 
 * Программа для построения и преобразования дерева арифметического выражения
 * в префиксной форме с последующей оптимизацией поддеревьев с нулевыми результатами
 */
#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <memory>
#include <string>
#include <vector>

struct TreeNode {
    int value;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;
    
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
public:
    /**
     * @brief Строит дерево из префиксного выражения
     * @param expression Строка с префиксным выражением
     * @return Указатель на корень дерева
     */
    std::unique_ptr<TreeNode> buildFromPrefix(const std::string& expression);
    
    /**
     * @brief Оптимизирует дерево, заменяя поддеревья с нулевыми результатами
     * @param node Текущий узел для обработки
     * @return Результат вычисления поддерева
     */
    int optimizeZeroSubtrees(std::unique_ptr<TreeNode>& node);
    
    /**
     * @brief Выводит дерево в префиксном порядке
     * @param node Текущий узел для вывода
     */
    void printPrefix(const TreeNode* node) const;

private:
    std::vector<std::string> tokens;
    size_t currentToken = 0;
    
    /**
     * @brief Рекурсивно строит дерево из токенов
     * @return Указатель на построенный узел
     */
    std::unique_ptr<TreeNode> buildTree();
    
    /**
     * @brief Вычисляет значение операции
     * @param op Код операции
     * @param left Левый операнд
     * @param right Правый операнд
     * @return Результат вычисления
     */
    int evaluateOperation(int op, int left, int right) const;
    
    /**
     * @brief Разбивает строку на токены
     * @param str Входная строка
     */
    void tokenize(const std::string& str);
};

#endif // EXPRESSION_TREE_H
