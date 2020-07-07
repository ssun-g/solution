#include<cstdio>
using namespace std;

int w, h;
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int check[50][50];
int map[50][50];

void Reset() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			check[i][j] = 0;
			map[i][j] = 0;
		}
	}
}

void go(int y, int x) {
	check[y][x] = 1;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < w && 0 <= ny && ny < h && !check[ny][nx] && map[ny][nx] == 1) go(ny, nx);
	}
}

int main() {
	while (true) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;
		Reset();
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!check[i][j] && map[i][j] == 1) {
					go(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}




	return 0;
}