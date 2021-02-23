#include <bits/stdc++.h>
using namespace std;

int sudoku[9][9];
int check[10];

void resetSudoku() { // test case마다 주어지는 값이 다르므로 test case마다 변수를 초기화 해야한다.
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			sudoku[i][j] = 0;
		}
	}
}

void resetCheck() { // check배열 초기화
	for (int i = 1; i <= 9; i++) check[i] = 0;
}

bool isCorrect() {
	for (int i = 1; i <= 9; i++) {
		if (check[i] != 1) return false;
	}

	return true;
}

string checkSudoku() {
	bool correct = true;

	// 가로줄 체크
	for (int y = 0; y < 9; y++) {
		resetCheck(); // 가로줄을 기준으로 규칙이 맞는지 체크하기 위해 가로줄을 한 번 탐색할 때마다 check배열을 초기화
		for (int x = 0; x < 9; x++) {
			check[sudoku[y][x]]++;
		}
		if (!isCorrect()) return "INCORRECT";
	}

	// 세로줄 체크
	for (int x = 0; x < 9; x++) {
		resetCheck(); // 세로줄을 기준으로 규칙이 맞는지 체크하기 위해 세로줄을 한 번 탐색할 때마다 check배열을 초기화
		for (int y = 0; y < 9; y++) {
			check[sudoku[y][x]]++;
		}
		if (!isCorrect()) return "INCORRECT";
	}

	// 3x3작은 사각형 체크
	for (int dy = 0; dy < 3; dy++) {
		for (int dx = 0; dx < 3; dx++) {
			resetCheck(); // 사각형을 한 번 확인할 때마다 check배열을 초기화 해주어야 한다.
			for (int y = 0; y < 3; y++) {
				for (int x = 0; x < 3; x++) {
					check[sudoku[y + (dy * 3)][x + (dx * 3)]]++;
				}
			}
			if (!isCorrect()) return "INCORRECT";
		}
	}

	return "CORRECT";
}

int main() {
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		resetSudoku();
		resetCheck();
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> sudoku[i][j];
			}
		}

		cout << "Case " << i << ": " << checkSudoku() << '\n';
	}

	return 0;
}