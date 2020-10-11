#include<cstdio>
#include<vector>
using namespace std;

vector<pair<int, int> > vp[100001];
int check[100001];
int node;
int diameter;

void Reset() {
	for (int i = 0; i < 100001; i++) {
		check[i] = 0;
	}
}

void dfs(int init, int cost) {
	check[init] = 1;
	if (diameter < cost) {
		diameter = cost;
		node = init;
	}
	for (int i = 0; i < vp[init].size(); i++) {
		if (!check[vp[init][i].first]) {
			dfs(vp[init][i].first, cost + vp[init][i].second);
		}
	}
}

int main() {
	int V;
	scanf("%d", &V);
	for (int i = 0; i < V; i++) {
		int a;
		scanf("%d", &a);
		while (true) {
			int b, cost;
			scanf("%d", &b);
			if (b == -1) break;
			scanf("%d", &cost);
			vp[a].push_back(make_pair(b, cost));
			vp[b].push_back(make_pair(a, cost));
		}
	}

	dfs(1, 0); // find node;

	diameter = 0;
	Reset();

	dfs(node, 0); // find diameter;
	printf("%d\n", diameter);

	return 0;
}