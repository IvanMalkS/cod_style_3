/* Продолжение задания №CalcTree8 */

#include "expression_tree.h"
#include <stdexcept>
#include <cmath>

ExpressionTree::ExpressionTree(const std::string& expression) {
    size_t index = 0;
    root = buildTree(expression, index);
}

std::unique_ptr<TreeNode> ExpressionTree::buildTree(const std::string& expression, size_t& index) {
    if (index >= expression.size()) {
        throw std::invalid_argument("Некорректное выражение");
    }

    char token = expression[index];
    index++;

    if (isdigit(token)) {
        return std::make_unique<TreeNode>(token - '0');
    }

    int value;
    switch (token) {
        case '+': value = -1; break;
        case '-': value = -2; break;
        case '*': value = -3; break;
        case '/': value = -4; break;
        case '%': value = -5; break;
        case '^': value = -6; break;
        default: throw std::invalid_argument("Некорректный оператор");
    }

    auto node = std::make_unique<TreeNode>(value);
    node->left = buildTree(expression, index);
    node->right = buildTree(expression, index);
    return node;
}

int ExpressionTree::evaluate(const TreeNode* node) const {
    if (!node) {
        return 0;
    }

    if (node->value >= 0) {
        return node->value;
    }

    int leftValue = evaluate(node->left.get());
    int rightValue = evaluate(node->right.get());

    switch (node->value) {
        case -1: return leftValue + rightValue;
        case -2: return leftValue - rightValue;
        case -3: return leftValue * rightValue;
        case -4:
            if (rightValue == 0) throw std::runtime_error("Деление на ноль");
            return leftValue / rightValue;
        case -5:
            if (rightValue == 0) throw std::runtime_error("Деление на ноль");
            return leftValue % rightValue;
        case -6: return static_cast<int>(std::pow(leftValue, rightValue));
        default: throw std::runtime_error("Некорректный оператор");
    }
}

void ExpressionTree::simplifyTree(std::unique_ptr<TreeNode>& node) {
    if (!node) {
        return;
    }

    simplifyTree(node->left);
    simplifyTree(node->right);

    if (node->left && evaluate(node->left.get()) == 0) {
        node = std::move(node->right);
    } else if (node->right && evaluate(node->right.get()) == 0) {
        node = std::move(node->left);
    }
}

void ExpressionTree::simplify() {
    simplifyTree(root);
}

TreeNode* ExpressionTree::getRoot() {
    return root.get();
}
