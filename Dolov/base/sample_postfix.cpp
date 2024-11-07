#include "postfix.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	string expression;
	cout << "Введите выражение: ";
	getline(cin, expression);

	TPostfix postfix(expression);
	string postfixExpression = postfix.GetPostfix();

	postfixExpression.erase(remove(postfixExpression.begin(), postfixExpression.end(), ' '), postfixExpression.end());
	cout << "Арифметическое выражение: " << postfix.GetInfix() << endl;
	cout << "Постфиксная форма: " << postfixExpression << endl;

	vector<string> operands = postfix.GetOperands();

	if (!operands.empty()) {
		map<string, double> values;
		double value;

		for (const auto& op : operands) {
			cout << "Введите значение '" << op << "': ";
			while (!(cin >> value)) {
				cout << "Ошибка ввода. Пожалуйста, введите другое значение: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			values[op] = value;
		}

		cout << "Вычисленное значение выражения: " << postfix.Calculate(values) << endl;
	}
	else {
		cout << "Вычисленное значение выражения: " << postfix.Calculate({}) << endl;
	}

	return 0;
}
