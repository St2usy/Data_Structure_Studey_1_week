#pragma once
#define MAX_STACK_SIZE 100
#include "Student.h"
#include <iostream>

// 오류 처리 함수
inline void error(const char* message) {
	std::cout << message << std::endl;
	exit(1);
}

class StudentStack {
private:
	int top;
	Student data[MAX_STACK_SIZE];
public:
	StudentStack()
		: top(-1) {}
	~StudentStack() {}
	bool isEmpty() {
		if (top == -1) return true;
		else return false;
	}
	bool isFuLL() {
		if (top == MAX_STACK_SIZE - 1) return true;
		else return false;
	}
	void push(Student e) {
		if (isFuLL()) { error("Error : Stack is FULL!!"); }
		else {
			top += 1;
			data[top] = e; // 복사생성자, 대입연산자 오버로딩의 차이
		}
	}
	Student pop() {
		if (isEmpty()) { error("Error :: Stack is Empty !!"); }
		else {
			Student popdata = data[top];
			top -= 1;
			return popdata;
		}
	}
	Student peek() {
		if (isEmpty()) { error("Error :: Stack is Empty !!"); }
		else {
			return data[top];
		}
	}
	void display() {
		std::cout << "스택 갯수는 : " << top + 1 << std::endl;
		std::cout << "---------------Stack---------------" << std::endl;
		for (int i = 0; i <= top; i++) {
			data[i].display();
		}
	}
};
