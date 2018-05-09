#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector<vector<int>> adj(1005);
queue<int> q;

int n, m, v, a, b, check[1005];
void dfs(int);
void bfs(int);

int main() {
	scanf("%d%d%d", &n, &m, &v);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(v);
	printf("\n");
	memset(check, 0, sizeof(check));
	bfs(v);
	printf("\n");

	return 0;
}

void dfs(int index) {
	check[index] = 1;
	printf("%d ", index);

	for (int i = 0; i < adj[index].size(); i++) {
		int next = adj[index][i];
		if (!check[next])
			dfs(next);
	}
}

void bfs(int st) {
	check[st] = 1;
	q.push(st);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d ", now);

		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i];
			if (!check[next]) {
				check[next] = 1;
				q.push(next);
			}
		}
	}
}