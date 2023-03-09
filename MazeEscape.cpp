#include "Location2D.h"
#include <stack>
#include <iostream>
const int MAZE_SIZE = 6;
using std::stack;

char map[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};

bool isValidLoc(int r, int c) {
	if (r<0 || c<0 || r>MAZE_SIZE || c>MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x'; // 
}

int main() {
	stack<Location2D> locStack; // 위치 스택 객체 생성
	Location2D entry(1, 0);
	locStack.push(entry);

	while (locStack.empty() == false) {
		Location2D here = locStack.top();
		locStack.pop();

		int r = here.row;
		int c = here.col;
		std::cout << '(' << r << " " << "," << " " << c << ')' << " ";
		if (map[r][c] == 'x') {
			std::cout << "미로 탐색 성공!!" << std::endl;
			return 0;
		}
		else {
			map[r][c] = '.'; // 지나옴 처리
			if (isValidLoc(r - 1, c)) locStack.push(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c)) locStack.push(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1)) locStack.push(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1)) locStack.push(Location2D(r, c + 1));
		}
	}
	std::cout << "미로 탐색 실패" << std::endl;
}