#include<cstdio>
using namespace std;

int answer;
int tv[100001];
int check[100001];

void dfs(int hated) {
	if (!check[hated]) {
		check[hated] = 1;
		if (tv[hated] != 0) {
			answer++;
			dfs(tv[hated]);
		}
	}
	else answer = -1;
}

int main() {
	int N, M, P;
	scanf("%d %d %d", &N, &M, &P);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (tv[b] == 0) tv[b] = a;
	}
	dfs(P);
	printf("%d", answer);

	return 0;
}