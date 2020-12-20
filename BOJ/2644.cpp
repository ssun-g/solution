#include<bits/stdc++.h>
using namespace std;

int n, m, from, to;
int kinship[101][101];
int depth[101];

int bfs(int start) {
	int ret = 0;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		if (cur == to) return depth[to];
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (kinship[cur][i] == 1 && depth[i] == 0) {
				depth[i] = depth[cur] + 1;
				q.push(i);
			}
		}
	}

	return -1;
}

int main() {
	cin >> n;
	cin >> from >> to;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		kinship[x][y] = 1;
		kinship[y][x] = 1;
	}

	cout << bfs(from) << '\n';

	return 0;
}