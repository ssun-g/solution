#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;

int t, m, n, k, x, y;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int check[50][50];
int arr[50][50];

int dfs(int, int);

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		memset(arr, 0, sizeof(arr));
		memset(check, 0, sizeof(check));
		ans.clear();
		scanf("%d%d%d", &m, &n, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d%d", &x, &y);
			arr[y][x] = 1;
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arr[j][k] == 1 && !check[j][k]) {
					check[j][k] = 1;
					ans.push_back(dfs(j, k));
				}
			}
		}
		printf("%d\n", ans.size());
	}

	return 0;
}

int dfs(int r, int c) {
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (0 <= nr && nr < n && 0 <= nc && nc < m && !check[nr][nc] && arr[nr][nc] == 1) {
			check[nr][nc] = 1;
			ret += dfs(nr, nc);
		}
	}

	return ret;
}