#include<cstdio>
#include<cstring>

using namespace std;

int mp[100][100];
int check[100];
int tc;

void dfs(int idx) {
	for (int i = 0; i < tc; i++) {
		if (mp[idx][i] && !check[i]) {
			check[i] = 1;
			dfs(i);
		}
	}
}

int main() {
	scanf("%d", &tc);
	// input
	for (int i = 0; i < tc; i++) {
		for (int j = 0; j < tc; j++) {
			scanf("%d", &mp[i][j]);
		}
	}

	// dfs
	for (int i = 0; i < tc; i++) {
		memset(check, 0, sizeof(check));
		dfs(i);
		for (int j = 0; j < tc; j++) {
			if (check[j]) mp[i][j] = 1;
		}
	}

	for (int i = 0; i < tc; i++) {
		for (int j = 0; j < tc; j++) {
			printf("%d ", mp[i][j]);
		}
		printf("\n");
	}

	return 0;
}