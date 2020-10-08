#include<cstdio>
using namespace std;

int node[1001][1001];
int check[1001];

void dfs(int init, int size) {
	check[init] = 1;
	for (int i = 1; i <= size; i++) {
		if (!check[i] && node[init][i] == 1) dfs(i, size);
	}
}

int main() {
	int N, M;
	int answer = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		node[a][b] = 1;
		node[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			answer++;
			dfs(i, N);
		}
	}
	printf("%d\n", answer);

	return 0;
}