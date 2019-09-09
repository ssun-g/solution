#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
queue<pair<int, int>> q;

int m, n, Max, cnt, cnt2;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int check[1000][1000];
int arr[1000][1000];

void bfs();

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == -1) cnt++;
			if (arr[i][j] == 1) {
				q.push({ i,j });
				check[i][j] = 1;
			}
		}
	}
	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) cnt2++;
		}
	}

	if (cnt + cnt2 == n * m) {
		printf("%d\n", Max - 1);
	}
	else {
		printf("-1\n");
	}

	return 0;
}

void bfs() {
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		Max = max(Max, check[r][c]);
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (0 <= nr && nr < n && 0 <= nc && nc < m && arr[nr][nc] == 0 && !check[nr][nc]) {
				arr[nr][nc] = 1;
				check[nr][nc] = check[r][c] + 1;
				q.push({ nr,nc });
			}
		}
	}
}