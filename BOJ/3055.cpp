#include<bits/stdc++.h>
using namespace std;

class Point {
public:
	int y, x;

	Point(int y, int x) {
		this->y = y;
		this->x = x;
	}
};

int R, C;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int water[50][50];
int step[50][50];
vector<string> Map;
queue<Point> w;

void water_bfs() {
	while (!w.empty()) {
		Point cur = w.front();
		w.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (0 <= nx && nx < C && 0 <= ny && ny < R && !water[ny][nx] && Map[ny][nx] == '.') {
				water[ny][nx] = water[cur.y][cur.x] + 1;
				w.push(Point(ny, nx));
			}
		}
	}
}

void hdog_bfs(int y, int x) {
	queue<Point> q;
	q.push(Point(y, x));

	while (!q.empty()) {
		Point cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (0 <= nx && nx < C && 0 <= ny && ny < R && !step[ny][nx] && (!water[ny][nx] || step[cur.y][cur.x] + 1 < water[ny][nx]) && (Map[ny][nx] == '.' || Map[ny][nx] == 'D')) {
				step[ny][nx] = step[cur.y][cur.x] + 1;
				q.push(Point(ny, nx));
			}
		}
	}
}

int main() {
	int startY, startX, endY, endX;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		Map.push_back(s);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Map[i][j] == '*') w.push(Point(i, j));
			if (Map[i][j] == 'S') {
				startY = i;
				startX = j;
			}
			if (Map[i][j] == 'D') {
				endY = i;
				endX = j;
			}
		}
	}

	water_bfs();
	hdog_bfs(startY, startX);

	if (step[endY][endX] == 0) cout << "KAKTUS" << '\n';
	else cout << step[endY][endX] << '\n';

	return 0;
}