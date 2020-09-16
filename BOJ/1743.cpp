#include<cstdio>
#include<algorithm>
using namespace std;

int N, M, K;
int trash[101][101];
int check[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(int y, int x) {
	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!check[ny][nx] && trash[ny][nx] == 1 && 1 <= nx && nx <= M && 1 <= ny && ny <= N) {
			check[ny][nx] = 1;
			cnt += dfs(ny, nx);
		}
	}
	return cnt;
}

int main() {
	int answer = -1;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		trash[r][c] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (trash[i][j] == 1 && !check[i][j]) {
				check[i][j] = 1;
				answer = max(answer, dfs(i, j));
			}
		}
	}
	printf("%d\n", answer);

	return 0;
}