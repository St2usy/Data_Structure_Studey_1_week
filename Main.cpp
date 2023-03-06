#include "Stack_Made_2.h"
#include "Student_Stack.h"

int main() {
	//ArrayStack stack;
	//for (int i = 0; i < 10; i++) {
	//	stack.push(i);
	//}
	//stack.display();
	//stack.pop();
	//stack.pop();
	//stack.pop();
	//stack.display();

	StudentStack stack2;
	stack2.push(Student(2219410, "sin", "computer"));
	stack2.push(Student(22194101, "kim", "computer"));
	stack2.push(Student(22194102, "lee", "computer"));
	stack2.display();
	stack2.pop();
	stack2.display();

	return 0;
}