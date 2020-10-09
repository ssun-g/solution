#include<cstdio>
using namespace std;

int w, h, answer;
int Map[51][51];
int check[51][51];
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

void Reset() {
	answer = 0;
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			Map[i][j] = 0;
			check[i][j] = 0;
		}
	}
}

void dfs(int y, int x) {
	check[y][x] = 1;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < w && 0 <= ny && ny < h && !check[ny][nx] && Map[ny][nx] == 1)
			dfs(ny, nx);
	}
}

int main() {
	while (true) {
		Reset();
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &Map[i][j]);
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!check[i][j] && Map[i][j] == 1) {
					dfs(i, j);
					answer++;
				}
			}
		}
		printf("%d\n", answer);
	}

	return 0;
}