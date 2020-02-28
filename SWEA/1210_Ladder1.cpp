#include<cstdio>
using namespace std;

int ladder[100][100];
int check[100][100];
int dx[3] = { -1, 1, 0 };
int dy[3] = { 0, 0, -1 };
int result;

void dfs(int y, int x) {
	check[y][x] = 1;
	if (y == 0) result = x;
	for (int i = 0; i < 3; i++) {
		int cy = y + dy[i];
		int cx = x + dx[i];
		if (ladder[cy][cx] == 1 && cy < 100 && cx < 100 && cy >= 0 && cx >= 0 && !check[cy][cx]) {
			dfs(cy, cx);
			return;
		}
	}
}

int main() {
	int num;
	for (int k = 0; k < 10; k++) {
		scanf("%d", &num);
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf("%d", &ladder[i][j]);
			}
		}

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				check[i][j] = 0;
			}
		}

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (ladder[i][j] == 2) {
					dfs(i, j);
					printf("#%d %d\n", num, result);
				}
			}
		}
	}

	return 0;
}