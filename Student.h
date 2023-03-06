#pragma once
#include <iostream>
#include <cstring>
#define MAX_STRING 100
#pragma warning(disable:4996)

class Student {
private:
	int id;
	char* name;
	char* dept;
public:
	Student()
		: id(0), name(NULL), dept(NULL) {}
	Student(int id, const char* name, const char* dept)
		: id(id) {
		this->name = new char[strlen(name) + 1];
		this->dept = new char[strlen(dept) + 1];
		strcpy(this->name, name);
		strcpy(this->dept, dept);
	}
	void display() {
		std::cout << "�й� : " << id << " " << "�̸� : " << name << " " << "�а� : " << dept << " " << std::endl;
	}
	~Student() {
		if (name != NULL) {
			delete name;
			name = NULL;
		}
		if (dept != NULL) {
			delete dept;
			dept = NULL;
		}
	}
	Student(const Student& rhs) {
		id = rhs.id;
		name = strdup(rhs.name);
		dept = strdup(rhs.dept);
	}
};