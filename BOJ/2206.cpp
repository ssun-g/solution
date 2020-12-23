#include<bits/stdc++.h>
using namespace std;

class Point {
public:
	int y, x, broken;

	Point(int y, int x, int broken) {
		this->y = y;
		this->x = x;
		this->broken = broken;
	}
};

int N, M;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int check[1000][1000][2];
vector<string> Map;

int bfs(int y, int x) {
	queue<Point> q;
	q.push(Point(y, x, 0));
	check[y][x][0] = 1;

	while (!q.empty()) {
		Point cur = q.front();
		q.pop();
		if (cur.y == N - 1 && cur.x == M - 1)
			return check[cur.y][cur.x][cur.broken];

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && check[ny][nx][cur.broken] == 0) {
				if (Map[ny][nx] == '0') {
					check[ny][nx][cur.broken] = check[cur.y][cur.x][cur.broken] + 1;
					q.push(Point(ny, nx, cur.broken));
				}
				else if (cur.broken == 0 && Map[ny][nx] == '1') {
					check[ny][nx][1] = check[cur.y][cur.x][cur.broken] + 1;
					q.push(Point(ny, nx, 1));
				}
			}
		}
	}

	return -1;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		Map.push_back(s);
	}

	cout << bfs(0, 0) << '\n';

	return 0;
}