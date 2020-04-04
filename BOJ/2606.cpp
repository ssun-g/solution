#include<cstdio>
using namespace std;

int com[101][101];
int check[101];

int dfs(int idx, int num) {
	int ret = 1;
	check[idx] = 1;
	for (int i = 1; i <= num; i++) {
		if (!check[i] && com[idx][i] == 1) ret += dfs(i, num);
	}

	return ret;
}

int main() {
	int a, b, n, net;
	scanf("%d %d", &n, &net);
	for (int i = 0; i < net; i++) {
		scanf("%d %d", &a, &b);
		com[a][b] = 1;
		com[b][a] = 1;
	}

	printf("%d\n", dfs(1, n) - 1);

	return 0;
}