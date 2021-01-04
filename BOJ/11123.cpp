#include<bits/stdc++.h>
using namespace std;

int H, W, answer;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int check[100][100];
vector<string> Map;

void Reset() {
	answer = 0;
	Map.clear();
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			check[i][j] = 0;
		}
	}
}

void dfs(int y, int x) {
	check[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 <= ny && ny < H && 0 <= nx && nx < W && !check[ny][nx] && Map[ny][nx] == '#')
			dfs(ny, nx);
	}
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		Reset();

		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			string s;
			cin >> s;
			Map.push_back(s);
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (Map[i][j] == '#' && !check[i][j]) {
					dfs(i, j);
					answer++;
				}
			}
		}
		cout << answer << '\n';
	}

	return 0;
}