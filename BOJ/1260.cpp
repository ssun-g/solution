#include<cstdio>
#include<queue>
using namespace std;

int node[1001][1001];
int check[1001];
queue<int> q;

void Reset() {
	for (int i = 0; i < 1001; i++) {
		check[i] = 0;
	}
}

void dfs(int init, int n) {
	check[init] = 1;
	printf("%d ", init);
	for (int i = 1; i <= n; i++) {
		if (!check[i] && node[init][i] == 1) dfs(i, n);
	}
}

void bfs(int init, int n) {
	check[init] = 1;
	q.push(init);
	while (!q.empty()) {
		int frt = q.front();
		printf("%d ", frt);
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (!check[i] && node[frt][i] == 1) {
				check[i] = 1;
				q.push(i);
			}
		}
	}
}

int main() {
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		node[a][b] = 1;
		node[b][a] = 1;
	}

	dfs(V, N);
	printf("\n");
	Reset();
	bfs(V, N);

	return 0;
}