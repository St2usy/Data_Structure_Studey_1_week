#include "Stack_Made_2.h"
#include <iostream>
#include <string>
using std::string;

// 객체의 우선순위 계산
inline int precedence(char op) {
	switch (op) {
	case '(': case')': return 0;
	case '+': case'-': return 1; // 우선순위 중간
	case '*': case'/': return 2; // 우선순위 높음
	}
	return -1;
}

// 중위 표기 수식을 후위 표기 수식으로 변환하는 함수
void innfix2Postfix(string checkstr) {
	ArrayStack stack;
	char op; // 연산자를 받는 변수

	for (int i = 0; i < checkstr.length(); i++) {
		if (checkstr[i] >= '0' && checkstr[i] <= '9') { // 피연산자면 그대로 출력
			std::cout << checkstr[i] << " ";
		}
		else if (checkstr[i] == '(') stack.push(checkstr[i]); // '( 이면 스택에 삽입

		else if (checkstr[i] == ')') { // ') 이면 '( 가 나올때까지 연산자 출력
			while (!stack.isEmpty()) {
				op = stack.pop();
				if (op == '(') break;
				else std::cout << op << " ";
			}
		}

		else if (checkstr[i] == '+' || checkstr[i] == '-' || checkstr[i] == '*' || checkstr[i] == '/') { // 연산자( + - * / )면 --> 우선순위 비교 처리 < 여기부터 다시 공부 >
			while (!stack.isEmpty()) {
				op = stack.peek();
				if (precedence(checkstr[i]) <= precedence(op)) { // 이전의 연산자와 비교해서 이전 연산자의 우선순위가 더 높으면
					std::cout << op << " "; // 이전의 연산자를 출력한후
					stack.pop(); // pop을 수행한다.
				}
				else break;
			}
			stack.push(checkstr[i]); // 이후 연산자를 push한다.
		}
	}
	while (!stack.isEmpty())  // 순회가 끝나면 남아있는 연산자들을 출력한다.
		std::cout << stack.pop() << " ";
	std::cout << std::endl;
}

//int main() {
//	string str;
//	std::cout << "수식을 입력하세요: ";
//	getline(std::cin, str);
//	innfix2Postfix(str);
//}