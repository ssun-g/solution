#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> ans;

int Max, n, temp;
int rain;
int check[100][100];
int arr[100][100];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0, };

int dfs(int, int);

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	while (rain <= 100) {
		memset(check, 0, sizeof(check));
		ans.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > rain && !check[i][j]) {
					check[i][j] = 1;
					ans.push_back(dfs(i, j));
				}
			}
		}
		temp = ans.size();
		Max = max(Max, temp);
		rain++;
	}
	printf("%d\n", Max);

	return 0;
}

int dfs(int r, int c) {
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (0 <= nr && nr < n && 0 <= nc && nc < n && !check[nr][nc] && arr[nr][nc] > rain) {
			check[nr][nc] = 1;
			ret += dfs(nr, nc);
		}
	}

	return ret;
}