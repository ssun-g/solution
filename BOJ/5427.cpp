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

int w, h, endY = -1, endX = -1;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int fire[1000][1000];
int step[1000][1000];
vector<string> Map;
queue<Point> f;

void fire_bfs() {
	while (!f.empty()) {
		Point cur = f.front();
		f.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (0 <= nx && nx < w && 0 <= ny && ny < h && !fire[ny][nx] && (Map[ny][nx] == '.' || Map[ny][nx] == '@')) {
				fire[ny][nx] = fire[cur.y][cur.x] + 1;
				f.push(Point(ny, nx));
			}
		}
	}
}


void escape_bfs(int y, int x) {
	queue<Point> q;
	q.push(Point(y, x));
	step[y][x] = 0;

	while (!q.empty()) {
		Point cur = q.front();
		q.pop();
		if (cur.y == 0 || cur.x == 0 || cur.y == h - 1 || cur.x == w - 1) {
			endY = cur.y;
			endX = cur.x;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (0 <= nx && nx < w && 0 <= ny && ny < h && step[ny][nx] == -1 &&
				(!fire[ny][nx] || step[cur.y][cur.x] + 1 < fire[ny][nx]) && (Map[ny][nx] == '.')) {
				step[ny][nx] = step[cur.y][cur.x] + 1;
				q.push(Point(ny, nx));
			}
		}
	}
}

int main() {
	int startY, startX;
	int tc;
	cin >> tc;
	while (tc--) {
		Map.clear();
		memset(step, -1, sizeof(step));
		memset(fire, 0, sizeof(fire));
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			string s;
			cin >> s;
			Map.push_back(s);
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (Map[i][j] == '*') f.push(Point(i, j));
				if (Map[i][j] == '@') {
					startY = i;
					startX = j;
				}
			}
		}

		fire_bfs();
		escape_bfs(startY, startX);

		if (step[endY][endX] == -1 || (endY == -1 && endX == -1)) cout << "IMPOSSIBLE" << '\n';
		else cout << step[endY][endX] + 1 << '\n';

	}
	return 0;
}