#include<cstdio>

using namespace std;

int mp[1000][1000];
int check[1000];
int n, m;

void dfs(int idx) {
	check[idx] = 1;
	for (int i = 0; i < n; i++) {
		if (!check[i] && mp[idx][i]) dfs(i);
	}
}

int main() {
	int a, b;
	int result = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		mp[a - 1][b - 1] = 1;
		mp[b - 1][a - 1] = 1;
	}

	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			result++;
			dfs(i);
		}
	}

	printf("%d\n", result);

	return 0;
}