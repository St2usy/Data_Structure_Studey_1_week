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

	std::cout << "---------------���ڿ� ��ȣ�˻���---------------" << std::endl;
	if (!stack.isEmpty())
		std::cout << "Error: �����߰�!" << std::endl;
	else
		std::cout << "OK: ��ȣ�ݱ�����" << std::endl;
	return stack.isEmpty();
}

//int main() {
//	string str;
//	getline(std::cin, str); // ������� ������ �ִ� �Է� �Լ�
//	checkMatching(str);
//
//	return 0;
//}