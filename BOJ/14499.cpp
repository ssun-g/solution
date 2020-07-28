#include<cstdio>
using namespace std;

int n, m, r, c, k, direction;
int Map[20][20];
int dice[6]; // left, right, top, bottom, front, back
int ndice[6];
int dx[5] = { 0, 1, -1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };

bool safe(int x, int y) {
	if (0 <= x && x < m && 0 <= y && y < n) return true;
	else return false;
}

void Roll(int x, int y, int dir) {
	if (dir == 1) {
		ndice[0] = dice[3];
		ndice[1] = dice[2];
		ndice[2] = dice[0];
		ndice[3] = dice[1];
		ndice[4] = dice[4];
		ndice[5] = dice[5];
	}
	else if (dir == 2) {
		ndice[0] = dice[2];
		ndice[1] = dice[3];
		ndice[2] = dice[1];
		ndice[3] = dice[0];
		ndice[4] = dice[4];
		ndice[5] = dice[5];
	}
	else if (dir == 3) {
		ndice[0] = dice[0];
		ndice[1] = dice[1];
		ndice[2] = dice[4];
		ndice[3] = dice[5];
		ndice[4] = dice[3];
		ndice[5] = dice[2];
	}
	else {
		ndice[0] = dice[0];
		ndice[1] = dice[1];
		ndice[2] = dice[5];
		ndice[3] = dice[4];
		ndice[4] = dice[2];
		ndice[5] = dice[3];
	}

	if (Map[y][x] == 0) Map[y][x] = ndice[3];
	else {
		ndice[3] = Map[y][x];
		Map[y][x] = 0;
	}

	for (int i = 0; i < 6; i++) {
		dice[i] = ndice[i];
	}
}

int main() {
	scanf("%d %d %d %d %d", &n, &m, &r, &c, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &Map[i][j]);
		}
	}

	for (int i = 0; i < k; i++) {
		scanf("%d", &direction);
		int nx = c + dx[direction];
		int ny = r + dy[direction];
		if (safe(nx, ny)) {
			Roll(nx, ny, direction);
			printf("%d\n", ndice[2]);
			c = nx;
			r = ny;
		}
	}

	return 0;
}