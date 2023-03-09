#pragma once
#include <iostream>
#include <cstring>
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
		std::cout << "학번 : " << id << " " << "이름 : " << name << " " << "학과 : " << dept << " " << std::endl;
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
	Student& operator=(const Student& rhs2) {
		if (this == &rhs2) return *this;

		delete name;
		delete dept;

		this->name = new char[strlen(rhs2.name) + 1];
		this->dept = new char[strlen(rhs2.dept) + 1];

		strcpy(this->name, rhs2.name);
		strcpy(this->dept, rhs2.dept);

		id = rhs2.id;

		return *this;
	}
};