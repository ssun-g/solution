#include<cstdio>
#include<algorithm>
using namespace std;

int n, m;
int MAX = -1;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int ex_x[4][4] = { {0, 1, 2, 1}, {0, 1, 2, 1}, {0, 0, 0, -1}, {0, 0, 0, 1} };
int ex_y[4][4] = { {0, 0, 0, 1}, {0, 0, 0, -1}, {0, 1, 2, 1}, {0, 1, 2, 1} };
int paper[500][500];
int check[500][500];

void dfs(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		MAX = max(MAX, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < m && 0 <= ny && ny < n && !check[ny][nx]) {
			check[ny][nx] = 1;
			dfs(nx, ny, cnt + 1, sum + paper[ny][nx]);
			check[ny][nx] = 0;
		}
	}
}

void extra(int x, int y) {
	for (int i = 0; i < 4; i++) {
		bool flag = false;
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int nx = x + ex_x[i][j];
			int ny = y + ex_y[i][j];
			if (0 <= nx && nx < m && 0 <= ny && ny < n) sum += paper[ny][nx];
			else {
				flag = true;
				break;
			}
		}
		if (!flag) MAX = max(MAX, sum);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check[i][j] = 1;
			dfs(j, i, 1, paper[i][j]);
			check[i][j] = 0;

			extra(j, i);
		}
	}
	printf("%d\n", MAX);

	return 0;
}