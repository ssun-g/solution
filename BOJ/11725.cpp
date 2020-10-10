#include<cstdio>
#include<vector>
using namespace std;

vector<int> v[100001];
int check[100001];
int parent[100001];

void dfs(int init) {
	check[init] = 1;
	for (int i = 0; i < v[init].size(); i++) {
		if (!check[v[init][i]]) {
			parent[v[init][i]] = init;
			dfs(v[init][i]);
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= N; i++) {
		printf("%d\n", parent[i]);
	}

	return 0;
}