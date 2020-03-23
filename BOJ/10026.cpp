#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> ans, ans2;

int n, cmp[2];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int check[100][100];
char arr[100][100];

int n_dfs(int, int);
int u_dfs(int, int);

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("\n%c", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				check[i][j] = 1;
				ans.push_back(n_dfs(i, j));
			}
		}
	}

	memset(check, 0, sizeof(check));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				check[i][j] = 1;
				ans2.push_back(u_dfs(i, j));
			}
		}
	}
	printf("%d %d", ans.size(), ans2.size());

	return 0;
}

int n_dfs(int r, int c) {
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (0 <= nr && nr < n && 0 <= nc && nc < n && arr[nr][nc] == arr[r][c] && !check[nr][nc]) {
			check[nr][nc] = 1;
			ret += n_dfs(nr, nc);
		}
	}

	return ret;
}

int u_dfs(int r, int c) {
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (0 <= nr && nr < n && 0 <= nc && nc < n && !check[nr][nc]) {
			if ((arr[r][c] == 'R' && arr[nr][nc] == 'G') || (arr[r][c] == 'G' && arr[nr][nc] == 'R')) {
				check[nr][nc] = 1;
				ret += u_dfs(nr, nc);
			}
			else if (arr[r][c] == arr[nr][nc]) {
				check[nr][nc] = 1;
				ret += u_dfs(nr, nc);
			}
		}
	}

	return ret;
}