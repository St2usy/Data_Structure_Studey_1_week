#include "Stack_Made_2.h"
#include <cstdio>
#include <string>
#include <iostream>
using std::string;

bool checkMatching(string checkstr) {
	ArrayStack stack;

	for (int i = 0; i < checkstr.length(); i++) {
		if (checkstr[i] == '[' || checkstr[i] == '(' || checkstr[i] == '{')
			stack.push(checkstr[i]);
		else if (checkstr[i] == ']' || checkstr[i] == ')' || checkstr[i] == '}') {
			int prev = stack.pop();
			if ((checkstr[i] == ']' && prev != '[') ||
				(checkstr[i] == ')' && prev != '(') ||
				(checkstr[i] == '}' && prev != '{')) break;
		}
	}

	std::cout << "---------------문자열 괄호검사결과---------------" << std::endl;
	if (!stack.isEmpty())
		std::cout << "Error: 문제발견!" << std::endl;
	else
		std::cout << "OK: 괄호닫기정상" << std::endl;
	return stack.isEmpty();
}

//int main() {
//	string str;
//	getline(std::cin, str); // 공백까지 받을수 있는 입력 함수
//	checkMatching(str);
//
//	return 0;
//}