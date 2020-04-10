#include<cstdio>
using namespace std;

int result;
int student[100001];
int check[100001];
int cycle[100001];

void Reset() {
	result = 0;
	for (int i = 0; i < 100001; i++) {
		student[i] = 0;
		check[i] = 0;
		cycle[i] = 0;
	}
}

void dfs(int node) {
	if (cycle[node] == 1 || check[node] == -1) return;
	if (!check[node]) check[node] = 1;
	else if (check[node] == 1) {
		cycle[node] = 1;
		result++;
	}
	dfs(student[node]);
	check[node] = -1;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		Reset();
		int n;
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &student[j]);
		}

		for (int j = 1; j <= n; j++) {
			if (!check[j]) dfs(j);
		}

		printf("%d\n", n - result);
	}

	return 0;
}