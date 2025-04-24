/* Продолжение задания №CalcTree8 */

#ifndef CALCTREE_H
#define CALCTREE_H

#include <memory>
#include <string>

using namespace std;

// Коды операций
enum OpCode {
	ADD = -1,
	SUB = -2,
	MUL = -3,
	DIV = -4,
	MOD = -5,
	POW = -6
};

// Узел дерева выражения
struct Node {
	int value;  // если >=0: операнд (0..9), если <0: операция (код)
	unique_ptr<Node> left;
	unique_ptr<Node> right;

	explicit Node(int v);
};

// Класс для чтения токенов из префиксного выражения
class TokenReader {
public:
	explicit TokenReader(const string& s);

	// Считывает следующий токен (оператор или цифра)
	bool GetNextToken(string& token);

private:
	void SkipSpaces();

	const string& expr_;
	size_t pos_;
};

// Преобразование символа операции в код
int OpCharToCode(char op);

// Рекурсивное построение дерева из префиксного выражения
unique_ptr<Node> BuildTree(TokenReader& reader);

// Вычисление степени с целочисленными степенями >=0
int IPow(int base, int exp);

// Рекурсивное вычисление дерева с преобразованием поддеревьев, где левое или правое равно 0
// Возвращает значение поддерева
int EvaluateAndTransform(unique_ptr<Node>& node);

// Для отладки: вывод дерева
void PrintTree(const unique_ptr<Node>& node, int level = 0);

#endif  // CALCTREE_H
