#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int arr[500][500];
int check[500][500];

bool comp(int a, int b) {
	return a > b;
}

int dfs(int y, int x) {
	int ret = 1;
	check[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!check[ny][nx] && arr[ny][nx] == 1 && 0 <= nx && nx < m && 0 <= ny && ny < n) {
			ret += dfs(ny, nx);
		}
	}

	return ret;
}

int main() {
	vector<int> v;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && !check[i][j]) {
				v.push_back(dfs(i, j));
			}
		}
	}

	sort(v.begin(), v.end(), comp);
	if (v.empty()) printf("0\n0\n");
	else printf("%d\n%d\n", v.size(), v[0]);

	return 0;
}