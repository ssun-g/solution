#include<cstdio>
#include<algorithm>
using namespace std;

int n, m;
int MAX = -1;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int lab[8][8];
int check[8][8];
int vcheck[8][8];

void Reset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vcheck[i][j] = 0;
		}
	}
}

void arrCopy(int to[][8], int from[][8]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			from[i][j] = to[i][j];
		}
	}
}

int safeSize() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lab[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void virus(int x, int y) {
	vcheck[y][x] = 1;
	lab[y][x] = 2;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!vcheck[ny][nx] && lab[ny][nx] == 0 && 0 <= nx && nx < m && 0 <= ny && ny < n) virus(nx, ny);
	}
}

void wall(int x, int y, int cnt) {
	if (cnt == 3) {
		int tmp_lab[8][8] = { 0, };
		arrCopy(lab, tmp_lab);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!vcheck[i][j] && lab[i][j] == 2) virus(j, i);
			}
		}
		MAX = max(MAX, safeSize());
		arrCopy(tmp_lab, lab);
		Reset();
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j] && lab[i][j] == 0) {
				check[i][j] = 1;
				lab[i][j] = 1;
				wall(j, i, cnt + 1);
				check[i][j] = 0;
				lab[i][j] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &lab[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j] && lab[i][j] == 0) {
				check[i][j] = 1;
				lab[i][j] = 1;
				wall(j, i, 1);
				check[i][j] = 0;
				lab[i][j] = 0;
			}
		}
	}
	printf("%d\n", MAX);

	return 0;
}