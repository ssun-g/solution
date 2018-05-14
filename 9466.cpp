#include <cstdio>
#include <cstring>
using namespace std;

int t, n, ans;
int arr[100001], visit[100001], cycle[100001];

int dfs(int start, int cur, int dep) {
	visit[cur] = dep;
	cycle[cur] = start;

	int next = arr[cur];

	if (visit[next] == 0) {
		dfs(start, next, dep + 1);
	}
	else if (visit[next] != 0 && start == cycle[next])
		return dep - visit[next] + 1;
	else if (visit[next] != 0 && start != cycle[next])
		return 0;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);

		memset(visit, 0, sizeof(visit));
		ans = 0;

		for (int i = 1; i <= n; ++i)
			scanf("%d", &arr[i]);

		for (int i = 1; i <= n; ++i) {
			if (visit[i] != 0)
				continue;
			if (visit[arr[i]] == 0)
				ans += dfs(i, i, 1);
		}
		printf("%d\n", n - ans);
	}
	return 0;
}
