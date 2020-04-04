#include<cstdio>
#include<iostream>
using namespace std;

int r, c, w, s;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int check[250][250];
char arr[250][250];

void bfs(int y, int x) {
	if (arr[y][x] == 'v') w++;
	if (arr[y][x] == 'k') s++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && 0 <= ny && nx < c && ny < r && !check[ny][nx] && arr[ny][nx] != '#') {
			check[ny][nx] = 1;
			bfs(ny, nx);
		}
	}
}

int main() {
	int wolf = 0, sheep = 0;
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!check[i][j] && arr[i][j] != '#') {
				w = 0;
				s = 0;
				check[i][j] = 1;
				bfs(i, j);
				
				if (w != 0 || s != 0) {
					if (w < s) sheep += s;
					else wolf += w;
				}
			}
		}
	}

	printf("%d %d\n", sheep, wolf);

	return 0;
}