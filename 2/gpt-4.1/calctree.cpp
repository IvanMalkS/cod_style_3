/* Продолжение задания №CalcTree8 */

#include "calctree.h"
#include <cctype>
#include <iostream>
#include <stdexcept>

using namespace std;

// --- Node ---

Node::Node(int v) : value(v), left(nullptr), right(nullptr) {}

// --- TokenReader ---

TokenReader::TokenReader(const string& s) : expr_(s), pos_(0) {}

void TokenReader::SkipSpaces() {
	while (pos_ < expr_.size() && isspace(expr_[pos_])) {
		++pos_;
	}
}

bool TokenReader::GetNextToken(string& token) {
	SkipSpaces();
	if (pos_ >= expr_.size()) {
		return false;
	}

	char c = expr_[pos_];

	// Операторы: + - * / % ^
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^') {
		token = c;
		++pos_;
		return true;
	}

	// Цифры 0..9
	if (isdigit(c)) {
		token = c;
		++pos_;
		return true;
	}

	// Неизвестный символ — считаем ошибкой
	return false;
}

// --- OpCharToCode ---

int OpCharToCode(char op) {
	switch (op) {
		case '+': return ADD;
		case '-': return SUB;
		case '*': return MUL;
		case '/': return DIV;
		case '%': return MOD;
		case '^': return POW;
		default: throw invalid_argument("Unknown operator");
	}
}

// --- BuildTree ---

unique_ptr<Node> BuildTree(TokenReader& reader) {
	string token;
	if (!reader.GetNextToken(token)) {
		throw runtime_error("Unexpected end of expression");
	}

	if (token.size() == 1 && isdigit(token[0])) {
		return make_unique<Node>(token[0] - '0');
	}

	int opCode = OpCharToCode(token[0]);
	auto node = make_unique<Node>(opCode);

	node->left = BuildTree(reader);
	node->right = BuildTree(reader);

	return node;
}

// --- IPow ---

int IPow(int base, int exp) {
	int result = 1;
	while (exp > 0) {
		if (exp & 1) {
			result *= base;
		}
		base *= base;
		exp >>= 1;
	}
	return result;
}

// --- EvaluateAndTransform ---

int EvaluateAndTransform(unique_ptr<Node>& node) {
	if (!node) {
		return 0;
	}

	if (node->value >= 0) {
		return node->value;
	}

	int leftVal = EvaluateAndTransform(node->left);
	int rightVal = EvaluateAndTransform(node->right);

	if (leftVal == 0 || rightVal == 0) {
		int val = 0;
		switch (node->value) {
			case ADD: val = leftVal + rightVal; break;
			case SUB: val = leftVal - rightVal; break;
			case MUL: val = leftVal * rightVal; break;
			case DIV: val = (rightVal != 0) ? (leftVal / rightVal) : 0; break;
			case MOD: val = (rightVal != 0) ? (leftVal % rightVal) : 0; break;
			case POW: val = IPow(leftVal, rightVal); break;
			default: throw runtime_error("Unknown operator code");
		}
		node = make_unique<Node>(val);
		return val;
	}

	int val = 0;
	switch (node->value) {
		case ADD: val = leftVal + rightVal; break;
		case SUB: val = leftVal - rightVal; break;
		case MUL: val = leftVal * rightVal; break;
		case DIV: val = (rightVal != 0) ? (leftVal / rightVal) : 0; break;
		case MOD: val = (rightVal != 0) ? (leftVal % rightVal) : 0; break;
		case POW: val = IPow(leftVal, rightVal); break;
		default: throw runtime_error("Unknown operator code");
	}

	return val;
}

// --- PrintTree ---

void PrintTree(const unique_ptr<Node>& node, int level) {
	if (!node) {
		return;
	}
	for (int i = 0; i < level; ++i) {
		cout << "\t";
	}
	if (node->value >= 0) {
		cout << "Operand: " << node->value << " (addr: " << node.get() << ")\n";
	} else {
		cout << "Operator: " << node->value << " (addr: " << node.get() << ")\n";
	}
	PrintTree(node->left, level + 1);
	PrintTree(node->right, level + 1);
}
