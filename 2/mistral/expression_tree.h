/* Продолжение задания №CalcTree8 */

#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <string>
#include <memory>

// Узел дерева
struct TreeNode {
    int value;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Класс для работы с деревом выражений
class ExpressionTree {
public:
    ExpressionTree(const std::string& expression);
    void simplify();
    TreeNode* getRoot();

private:
    std::unique_ptr<TreeNode> root;

    std::unique_ptr<TreeNode> buildTree(const std::string& expression, size_t& index);
    int evaluate(const TreeNode* node) const;
    void simplifyTree(std::unique_ptr<TreeNode>& node);
};

#endif // EXPRESSION_TREE_H
