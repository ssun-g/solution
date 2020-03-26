#include<cstdio>
#include<iostream>
using namespace std;

int arr[9][9];
int col[9][10] = { 0, };
int row[9][10] = { 0, };
int square[9][10] = { 0, };

void sudoku(int cnt) {
	int x = cnt / 9;
	int y = cnt % 9;
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}

	if (arr[x][y]) sudoku(cnt + 1);
	else {
		for (int i = 1; i <= 9; i++) {
			if (!row[x][i] && !col[y][i] && !square[(x / 3) * 3 + (y / 3)][i]) {
				row[x][i] = 1;
				col[y][i] = 1;
				square[(x / 3) * 3 + (y / 3)][i] = 1;
				arr[x][y] = i;
				sudoku(cnt + 1);
				row[x][i] = 0;
				col[y][i] = 0;
				square[(x / 3) * 3 + (y / 3)][i] = 0;
				arr[x][y] = 0;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j]) {
				row[i][arr[i][j]] = 1;
				col[j][arr[i][j]] = 1;
				square[(i / 3) * 3 + (j / 3)][arr[i][j]] = 1;
			}
		}
	}

	sudoku(0);


	return 0;
}