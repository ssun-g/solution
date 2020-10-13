#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

vector<pair<int, int> > v[10001];
int check[10001];

void Reset() {
	for (int i = 0; i < 10001; i++) {
		check[i] = 0;
	}
}

bool dfs(int cur, int cost, int from) {
	check[cur] = 1;
	if (cur == from) return true;
	for (int i = 0; i < v[cur].size(); i++) {
		pair<int, int> next = v[cur][i];
		if (!check[next.first] && cost <= next.second)
			if (dfs(next.first, cost, from)) return true;
	}

	return false;
}

int main() {
	int N, M;
	int maxCost = -1;
	int answer = -1;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		v[a].push_back(make_pair(b, cost));
		v[b].push_back(make_pair(a, cost));
		maxCost = max(maxCost, cost);
	}

	int to, from;
	scanf("%d %d", &to, &from);

	int left = 0;
	int right = maxCost;
	int mid;
	while (left <= right) {
		Reset();
		mid = (left + right) / 2;
		if (dfs(to, mid, from)) {
			left = mid + 1;
			answer = max(answer, mid);
		}
		else right = mid - 1;
	}
	printf("%d\n", answer);

	return 0;
}