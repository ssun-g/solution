#include<iostream>
#include<string>
#include<queue>
using namespace std;

int M, N;
int Map[101][101];
int dist[101][101];
int dx[4] = { 0, 0, -1 , 1 };
int dy[4] = { -1, 1 ,0, 0 };

void bfs(int x, int y) {
	queue<pair<int, int> > qp;
	qp.push(make_pair(x, y));
	dist[y][x] = 0;

	while (!qp.empty()) {
		int curx = qp.front().first;
		int cury = qp.front().second;
		qp.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (0 <= nx && nx < M && 0 <= ny && ny < N) {
				if (Map[ny][nx] == 1) {
					if (dist[ny][nx] > dist[cury][curx] + 1) {
						dist[ny][nx] = dist[cury][curx] + 1;
						qp.push(make_pair(nx, ny));
					}
				}
				else {
					if (dist[ny][nx] > dist[cury][curx]) {
						dist[ny][nx] = dist[cury][curx];
						qp.push(make_pair(nx, ny));
					}
				}
			}
		}
	}

}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			Map[i][j] = input[j] - '0';
			dist[i][j] = 987654321;
		}
	}
	bfs(0, 0);
	cout << dist[N - 1][M - 1] << '\n';

	return 0;
}