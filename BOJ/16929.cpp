#include<bits/stdc++.h>
using namespace std;

int N, M;
int sx, sy;
int dx[4] = { 0, 0, -1, 1 }; // direction: 0, 1, 2, 3
int dy[4] = { -1, 1, 0, 0 };
int check[50][50];
bool isCycle = false;

vector<string> dots;

void dfs(int x, int y, int direction, int turn_cnt) {
	if (isCycle) return;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < M && 0 <= ny && ny < N) {
			if (check[ny][nx]) {
				if (nx == sx && ny == sy && turn_cnt >= 4) { // 시작 지점으로 돌아왔고 방향이 3번 이상 꺾였으면 사이클 존재
					isCycle = true;
					return;
				}
			}
			else {
				if (dots[y][x] == dots[ny][nx]) { // 같은 문자일 때 사이클 탐색
					check[ny][nx] = 1;
					if (i == direction) dfs(nx, ny, i, turn_cnt);
					else dfs(nx, ny, i, turn_cnt + 1);
					check[ny][nx] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;

	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		dots.push_back(s);
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) { // 문자마다 사이클을 찾고 사이클이 존재하면 Yes 출력
			sx = x;
			sy = y;
			check[y][x] = 1;
			dfs(x, y, 0, 1);
			if (isCycle) {
				cout << "Yes" << '\n';
				return 0;
			}

		}
	}
	cout << "No" << '\n';

	return 0;
}