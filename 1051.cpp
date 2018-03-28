#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int square[51][51], MAX = 1;
void go(int, int, int);

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &square[i][j]);
		}
	}
	go(n, m, 0);
	return 0;
}

void go(int row, int col, int cnt) {
	if (cnt == min(row, col)) {
		printf("%d", MAX);
		return;
	}
	for (int i = 0; i < row; i++) {
		if (i + cnt > row - 1)
			break;
		for (int j = 0; j < col; j++) {
			if (j + cnt > col - 1)
				break;
			if (square[i][j] == square[i][j + cnt] && square[i][j + cnt] == square[i + cnt][j] && square[i + cnt][j] == square[i + cnt][j + cnt]) {
				MAX = max(MAX, (cnt + 1)*(cnt + 1));
			}
		}
	}
	go(row, col, cnt + 1);
}
