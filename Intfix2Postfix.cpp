#include "Stack_Made_2.h"
#include <iostream>
#include <string>
using std::string;

// ��ü�� �켱���� ���
inline int precedence(char op) {
	switch (op) {
	case '(': case')': return 0;
	case '+': case'-': return 1; // �켱���� �߰�
	case '*': case'/': return 2; // �켱���� ����
	}
	return -1;
}

// ���� ǥ�� ������ ���� ǥ�� �������� ��ȯ�ϴ� �Լ�
void innfix2Postfix(string checkstr) {
	ArrayStack stack;
	char op; // �����ڸ� �޴� ����

	for (int i = 0; i < checkstr.length(); i++) {
		if (checkstr[i] >= '0' && checkstr[i] <= '9') { // �ǿ����ڸ� �״�� ���
			std::cout << checkstr[i] << " ";
		}
		else if (checkstr[i] == '(') stack.push(checkstr[i]); // '( �̸� ���ÿ� ����

		else if (checkstr[i] == ')') { // ') �̸� '( �� ���ö����� ������ ���
			while (!stack.isEmpty()) {
				op = stack.pop();
				if (op == '(') break;
				else std::cout << op << " ";
			}
		}

		else if (checkstr[i] == '+' || checkstr[i] == '-' || checkstr[i] == '*' || checkstr[i] == '/') { // ������( + - * / )�� --> �켱���� �� ó�� < ������� �ٽ� ���� >
			while (!stack.isEmpty()) {
				op = stack.peek();
				if (precedence(checkstr[i]) <= precedence(op)) { // ������ �����ڿ� ���ؼ� ���� �������� �켱������ �� ������
					std::cout << op << " "; // ������ �����ڸ� �������
					stack.pop(); // pop�� �����Ѵ�.
				}
				else break;
			}
			stack.push(checkstr[i]); // ���� �����ڸ� push�Ѵ�.
		}
	}
	while (!stack.isEmpty())  // ��ȸ�� ������ �����ִ� �����ڵ��� ����Ѵ�.
		std::cout << stack.pop() << " ";
	std::cout << std::endl;
}

//int main() {
//	string str;
//	std::cout << "������ �Է��ϼ���: ";
//	getline(std::cin, str);
//	innfix2Postfix(str);
//}