#include<cstdio>
#include<vector>
using namespace std;

vector<int> node[20001];
int bipa[20001];

void Reset() {
	for (int i = 0; i < 20001; i++) {
		node[i].clear();
		bipa[i] = 0;
	}
}

void dfs(int init, int flag) {
	bipa[init] = flag;
	for (int i = 0; i < node[init].size(); i++) {
		if (bipa[node[init][i]] == 0)
			dfs(node[init][i], flag*-1);
	}
}

bool isBipa(int size) {
	for (int i = 1; i <= size; i++) {
		for (int j = 0; j < node[i].size(); j++) {
			if (bipa[i] == bipa[node[i][j]])
				return false;
		}
	}

	return true;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		Reset();
		int V, E;
		scanf("%d %d", &V, &E);
		for (int i = 0; i < E; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			node[a].push_back(b);
			node[b].push_back(a);
		}

		for (int i = 1; i <= V; i++) {
			if (bipa[i] == 0) dfs(i, 1);
		}
		if (isBipa(V)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}