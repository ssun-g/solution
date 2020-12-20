// 테스트 케이스가 여러개 주어질 경우 꼭 초기화 하기!

#include<bits/stdc++.h>
using namespace std;

class Point {
public:
	int floor;
	int x;
	int y;

	Point(int floor, int y, int x) {
		this->floor = floor;
		this->y = y;
		this->x = x;
	}
};

int L, R, C;
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
vector<string> Map[30];
int depth[30][30][30];

void Reset() {
	for (int i = 0; i < 30; i++) {
		Map[i].clear();
	}
}

string bfs(int floor, int y, int x) {
	Point point(floor, y, x);
	queue<Point> q;
	q.push(point);

	while (!q.empty()) {
		Point cur = q.front();
		q.pop();
		if (Map[cur.floor][cur.y][cur.x] == 'E')
			return "Escaped in " + to_string(depth[cur.floor][cur.y][cur.x]) + " minute(s).";

		for (int i = 0; i < 6; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nfloor = cur.floor + dz[i];
			if (0 <= nx && nx < C && 0 <= ny && ny < R && 0 <= nfloor && nfloor < L
				&& !depth[nfloor][ny][nx] && (Map[nfloor][ny][nx] == '.' || Map[nfloor][ny][nx] == 'E')) {
				depth[nfloor][ny][nx] = depth[cur.floor][cur.y][cur.x] + 1;
				q.push(Point(nfloor, ny, nx));
			}
		}
	}

	return "Trapped!";
}

int main() {
	while (true) {
		Reset();
		memset(depth, 0, sizeof(depth));

		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				string s;
				cin >> s;
				Map[i].push_back(s);
			}
		}

		bool escapeFlag = false;
		for (int i = 0; i < L; i++) {
			if (escapeFlag) break;
			for (int j = 0; j < R; j++) {
				if (escapeFlag) break;
				for (int k = 0; k < C; k++) {
					if (Map[i][j][k] == 'S') {
						cout << bfs(i, j, k) << '\n';
						escapeFlag = true;
						break;
					}
				}
			}
		}
	}

	return 0;
}