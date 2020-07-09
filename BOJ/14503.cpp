#include<cstdio>
using namespace std;

int n, m, r, c, d;
int dir_cnt, cnt;
int turnDir[4] = { 3, 0 ,1, 2 };
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int room[50][50];

void clean(int x, int y, int dir) {
	if (room[y][x] == 1) return;
	if (room[y][x] == 0) {
		dir_cnt = 0;
		room[y][x] = 2;
		cnt++;
	}

	int nx = x + dx[dir];
	int ny = y + dy[dir];
	int bx = x + dx[turnDir[dir]];
	int by = y + dy[turnDir[dir]];
	if (room[ny][nx] == 0) clean(nx, ny, turnDir[dir]);
	else if (dir_cnt < 4 && room[ny][nx] != 0) {
		dir_cnt++;
		clean(x, y, turnDir[dir]);
	}
	else if (dir_cnt == 4 && room[by][bx] != 1) {
		dir_cnt = 0;
		clean(bx, by, dir);
	}
	else if (dir_cnt == 4 && room[by][bx] == 1) return;
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &room[i][j]);
		}
	}
	clean(c, r, d);
	printf("%d\n", cnt);

	return 0;
}