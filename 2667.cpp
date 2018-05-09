#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int arr[25][25];
int check[25][25];

int dfs(int, int);

int main() {
	vector<int> ans;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0 && arr[i][j] == 1) {
				check[i][j] = 1;
				ans.push_back(dfs(i, j));
			}
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}

int dfs(int r, int c) {
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (0 <= nr && nr < n && 0 <= nc && nc < n && check[nr][nc] == 0 && arr[nr][nc] == 1) {
			check[nr][nc] = 1;
			ret += dfs(nr, nc);
		}
	}
	return ret;
}