#include<cstdio>
#include<vector>
#include<utility>
using namespace std;

vector<pair<int, int> > vp[10001];
int check[10001];
int node;
int length;

void Reset() {
	for (int i = 0; i < 10001; i++) {
		check[i] = 0;
	}
}

void dfs(int init, int cost) {
	check[init] = 1;
	if (length < cost) {
		length = cost;
		node = init;
	}
	for (int i = 0; i < vp[init].size(); i++) {
		if (!check[vp[init][i].first]) {
			dfs(vp[init][i].first, cost + vp[init][i].second);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		vp[a].push_back(make_pair(b, cost));
		vp[b].push_back(make_pair(a, cost));
	}

	dfs(1, 0); // find node

	length = 0;
	Reset();

	dfs(node, 0); // find diameter
	printf("%d\n", length);

	return 0;
}