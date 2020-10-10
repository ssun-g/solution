#include<cstdio>
#include<queue>
using namespace std;

queue<pair<int, int> > qp;
int N, M;
int maze[101][101];
int check[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void bfs() {
	while (!qp.empty()) {
		int x = qp.front().second;
		int y = qp.front().first;
		check[y][x] = 1;
		qp.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 < nx && nx <= M && 0 < ny && ny <= N && !check[ny][nx] && maze[ny][nx] == 1) {
				maze[ny][nx] = maze[y][x] + 1;
				qp.push(make_pair(ny, nx));
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}

	qp.push(make_pair(1, 1));
	bfs();
	printf("%d\n", maze[N][M]);

	return 0;
}