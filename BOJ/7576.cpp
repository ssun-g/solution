#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

queue<pair<int, int> > qp;
int M, N;
int tomato[1001][1001];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };


void bfs() {
	while (!qp.empty()) {
		int x = qp.front().first;
		int y = qp.front().second;
		qp.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < M && 0 <= ny && ny < N && tomato[ny][nx] == 0) {
				tomato[ny][nx] = tomato[y][x] + 1;
				qp.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	int answer = -1;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &tomato[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 1) {
				qp.push(make_pair(j, i));
			}
		}
	}

	bfs();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 0) {
				printf("-1\n");
				return 0;
			}
			else answer = max(answer, tomato[i][j]);
		}
	}
	printf("%d\n", answer - 1);

	return 0;
}