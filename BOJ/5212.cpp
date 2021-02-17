#include <bits/stdc++.h>
using namespace std;

// 좌표를 저장하기 위한 class
class Point {
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int R, C;
Point sp(10, 10); // 50년 후의 지도를 그리기 위한 직사각형의 왼쪽 위 좌표
Point ep(0, 0); // 50년 후의 지도를 그리기 위한 직사각형의 오른쪽 아래 좌표
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
vector<string> Map;

void Solve() {
	vector<string> tmp = Map;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (Map[y][x] == '.') continue; // 현재 위치가 바다인 경우 신경쓸 필요가 없다.

			int seaCount = 0;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				// 현재 노드 기준으로 상,하,좌,우 4방향을 살펴보고 바다(.)이면 카운트를 +1 해준다.
				if (nx < 0 || nx >= C || ny < 0 || ny >= R || Map[ny][nx] == '.') seaCount++;
			}
			if (seaCount >= 3) tmp[y][x] = '.'; // 3방향 이상이 바다이면 50년 후 섬은 잠긴다.
			else { // 섬이 남아 있다면 50년 후의 지도를 그리기 위해 최대 좌표(직사각형) 값을 업데이트 해준다.
				sp.x = min(sp.x, x);
				sp.y = min(sp.y, y);
				ep.x = max(ep.x, x);
				ep.y = max(ep.y, y);
			}
		}
	}

	// output
	for (int i = sp.y; i <= ep.y; i++) {
		for (int j = sp.x; j <= ep.x; j++) {
			cout << tmp[i][j];
		}
		cout << '\n';
	}
}

void Input() {
	string s;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> s;
		Map.push_back(s);
	}
}

int main() {

	Input();
	Solve();

	return 0;
}