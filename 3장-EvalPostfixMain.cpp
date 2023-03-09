#include "OperandStack.h"
#include <string>
#include <iostream>
using std::string;
// �Է����κ��� ���� ǥ�� ������ �о� ����ϴ� �Լ�
double calcPostfixExpr(string checkstr) {
	OperandStack stack;

	for (int i = 0; i < checkstr.length(); i++) {
		if (checkstr[i] == '+' || checkstr[i] == '-' || checkstr[i] == '*' || checkstr[i] == '/') {
			double val2 = stack.pop();
			double val1 = stack.pop();
			switch (checkstr[i]) {
			case '+': stack.push(val1 + val2); break;
			case '-': stack.push(val1 - val2); break;
			case '*': stack.push(val1 * val2); break;
			case '/': stack.push(val1 / val2); break;
			}
		}
		else if (checkstr[i] >= '0' && checkstr[i] <= '9') {
			checkstr[i] -= 48;
			stack.push(checkstr[i]);
		}
	}
	return stack.pop();
}
//
//int main() {
//	string str;
//	std::cout << "������ �Է��ϼ���: ";
//	getline(std::cin, str); // string������ ������  ������ �Է��� ���� �� cin���� �Է¹��� �ʰ� getline���� �Է� �޴´�. <���ǻ��� ����>
//	double ref = calcPostfixExpr(str);
//	std::cout << ref;
//
//	return 0;
//}