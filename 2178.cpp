#include<cstdio>
#include<queue>
using namespace std;

int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int arr[105][105];
int check[105][105];

typedef struct {
	int r, c, cnt;
}node;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	queue<node> q;
	q.push({ 0,0,1 });
	check[0][0] = 1;
	
	int ans = 0;
	while (!q.empty()) {
		node u = q.front();
		if (u.r == n - 1 && u.c == m - 1) {
			ans = u.cnt;
			break;
		}
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nr = u.r + dr[k];
			int nc = u.c + dc[k];
			if (0 <= nr && nr < n && 0 <= nc && nc < m && arr[nr][nc] && !check[nr][nc]) {
				check[nr][nc] = 1;
				q.push({ nr,nc,u.cnt + 1 });
			}
		}
	}
	printf("%d", ans);

	return 0;
}