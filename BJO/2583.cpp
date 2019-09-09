#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;

int n, m, k;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int check[100][100];
int arr[100][4];
int bond[100][100];

int dfs(int, int);

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int l = 0; l < k; l++) {
				if (arr[l][0] <= j && j < arr[l][2] && arr[l][1] <= i && i < arr[l][3]) {
					bond[i][j] = 0;
					break;
				}
				bond[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (bond[i][j] == 1 && !check[i][j]) {
				check[i][j] = 1;
				ans.push_back(dfs(i, j));
			}
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());

	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}

int dfs(int r, int c) {
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (0 <= nr && nr < n && 0 <= nc && nc < m && !check[nr][nc] && bond[nr][nc] == 1) {
			check[nr][nc] = 1;
			ret += dfs(nr, nc);
		}
	}

	return ret;
}