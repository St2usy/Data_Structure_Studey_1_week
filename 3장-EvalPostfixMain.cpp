#include "OperandStack.h"
#include <string>
#include <iostream>
using std::string;
// 입력으로부터 후위 표기 수식을 읽어 계산하는 함수
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
//	std::cout << "수식을 입력하세요: ";
//	getline(std::cin, str); // string형에서 공백을  포함한 입력을 받을 때 cin으로 입력받지 않고 getline으로 입력 받는다. <주의사항 있음>
//	double ref = calcPostfixExpr(str);
//	std::cout << ref;
//
//	return 0;
//}